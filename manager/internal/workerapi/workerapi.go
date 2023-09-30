package workerapi

import (
	"bytes"
	"encoding/json"
	"errors"
	"fmt"
	go_wasi_http "github.com/zivergetech/go-wasi-http/roundtrip"
	"io"
	"net/http"
)

func init() {
	http.DefaultClient.Transport = go_wasi_http.WasiHttpTransport{}
}

type WorkerCreationRequest struct {
	Name string     `json:"name"`
	Args []string   `json:"args"`
	Env  [][]string `json:"env"`
}

type WorkerID struct {
	RawTemplateID string `json:"rawTemplateId"`
	WorkerName    string `json:"workerName"`
}

type VersionedWorkerID struct {
	WorkerID            WorkerID `json:"workerId"`
	TemplateVersionUsed int      `json:"templateVersionUsed"`
}

const GolemApiURL = "https://release.api.golem.cloud"

func CreateWorker(token string, templateID string, request WorkerCreationRequest) (*VersionedWorkerID, error) {
	if request.Args == nil {
		request.Args = []string{}
	}
	if request.Env == nil {
		request.Env = [][]string{}
	}

	postBody, err := json.Marshal(request)
	if err != nil {
		return nil, err
	}
	url := GolemApiURL + "/v1/templates/" + templateID + "/workers"
	fmt.Printf("Posting to %v\n", url)
	fmt.Printf("Body: %v\n", string(postBody))
	fmt.Printf("Authorization: %s\n", "Bearer "+token)

	req, err := http.NewRequest("POST", url, bytes.NewBuffer(postBody))
	if err != nil {
		return nil, fmt.Errorf("error creating request: %v", err.Error())
	}
	req.Header.Set("Content-Type", "application/json")
	req.Header.Set("Authorization", "Bearer "+token)

	resp, err := http.DefaultClient.Do(req)
	if err != nil {
		return nil, errors.New("error posting request: " + err.Error())
	}
	body, err := io.ReadAll(resp.Body)
	if err != nil {
		return nil, fmt.Errorf("error reading response: %v (status: %s)", err.Error(), resp.Status)
	}
	defer resp.Body.Close()

	fmt.Printf("Response: %v\n", string(body))
	var workerID VersionedWorkerID
	err = json.Unmarshal(body, &workerID)
	if err != nil {
		return nil, fmt.Errorf("error decoding response: %v (status: %s)", err.Error(), resp.Status)
	}
	return &workerID, nil
}
