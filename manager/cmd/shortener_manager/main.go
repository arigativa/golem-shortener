package main

import (
	"github.com/arigativa/golem-shortener/manager/internal/bindgen/shortener_manager"
	"github.com/arigativa/golem-shortener/manager/internal/service/manager"
)

func init() {
	// TODO env is not working
	shortener_manager.SetExportsGolemShortenerManagerApi(&manager.ManagerImpl{
		WorkerTemplateID: "xxxx",
		APIToken:         "yyyy",
		Prefix:           "https://www.shurl.hsslb.ch/go/go/",
	})
}

func main() {
}
