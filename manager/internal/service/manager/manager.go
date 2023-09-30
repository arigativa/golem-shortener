package manager

import (
	"github.com/arigativa/golem-shortener/manager/internal/bindgen/shortener_manager"
	"github.com/arigativa/golem-shortener/manager/internal/workerapi"
	"math/rand"
	"strconv"
	"time"
)

var _ shortener_manager.ExportsGolemShortenerManagerApi = &ManagerImpl{}

type ManagerImpl struct {
	WorkerTemplateID string
	APIToken         string
	Prefix           string

	workers []shortener_manager.GolemShortenerManagerApiWorker
}

func (m ManagerImpl) Spawn(url string) (result shortener_manager.Result[string, string]) {
	shortID := generateRandomString(5)

	shortURL := m.Prefix + shortID

	worker, err := workerapi.CreateWorker(m.APIToken, m.WorkerTemplateID, workerapi.WorkerCreationRequest{
		Name: shortID,
		Env: [][]string{
			{"URL", url},
		},
	})
	if err != nil {
		result.SetErr(err.Error())
		return
	}

	m.workers = append(m.workers, shortener_manager.GolemShortenerManagerApiWorker{
		Id:      worker.WorkerID.WorkerName,
		Name:    url,
		Version: strconv.Itoa(worker.TemplateVersionUsed),
	})

	result.Set(shortURL)
	return
}

func (m ManagerImpl) GetWorkers() []shortener_manager.GolemShortenerManagerApiWorker {
	return m.workers
}

func (m ManagerImpl) Hello() string {
	return "To create a short url run: curl -k -d '{\"url\":\"https://google.com/?q=this%20is%20groundbreaking\"}' https://www.shurl.hsslb.ch/create"
}

const alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

func generateRandomString(length int) string {
	seededRand := rand.New(rand.NewSource(time.Now().UnixNano()))

	b := make([]byte, length)
	for i := range b {
		b[i] = alphabet[seededRand.Intn(len(alphabet))]
	}
	return string(b)
}
