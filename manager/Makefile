PROJECT_NAME = shortener_manager

.PHONY: bindings
bindings:
	wit-bindgen tiny-go --out-dir internal/bindgen/$(PROJECT_NAME) ./wit

wasm:
	mkdir -p build
	tinygo build -target=wasi -o build/$(PROJECT_NAME).wasm cmd/$(PROJECT_NAME)/main.go

embed:
	wasm-tools component embed ./wit build/$(PROJECT_NAME).wasm --output build/$(PROJECT_NAME).embed.wasm
	wasm-tools component new build/$(PROJECT_NAME).embed.wasm -o build/$(PROJECT_NAME).template.wasm --adapt adapters/tier2/wasi_snapshot_preview1.wasm

deploy-template:
	var=`golem-cli template list | yq '.[].template_name' | grep $(PROJECT_NAME)`; \
	if [ -z "$$var" ]; then \
		golem-cli template add --template-name $(PROJECT_NAME) ./build/$(PROJECT_NAME).template.wasm; \
	else \
		golem-cli template update --template-name $(PROJECT_NAME) ./build/$(PROJECT_NAME).template.wasm; \
	fi


update-test-worker:
	golem-cli worker delete --worker-name test --template-name $(PROJECT_NAME)
	golem-cli worker add --worker-name test --template-name $(PROJECT_NAME) -e WORKER_TEMPLATE_ID=96526150-1e03-4b3f-a017-333595134a72
