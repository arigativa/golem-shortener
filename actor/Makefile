PROJECT_NAME = url_shortener
WASI_SYSROOT = ../../wasi-sdk-20.0/share/wasi-sysroot
WASI_CXX = ../../wasi-sdk-20.0/bin/clang++
CXX = clang++
SRCS = main.cpp
OBJS = $(subst ..cc,.o,$(SRCS))
WORKER_NAME ?= default_worker_name

bindings:
	wit-bindgen c ./wit

compile:
	$(WASI_CXX) --sysroot $(WASI_SYSROOT) $(SRCS) $(PROJECT_NAME).c $(PROJECT_NAME)_component_type.o -o ./build/$(PROJECT_NAME).module.wasm

package: compile
	wasm-tools component new ./build/$(PROJECT_NAME).module.wasm -o ./build/$(PROJECT_NAME).wasm --adapt adapters/tier2/wasi_snapshot_preview1.wasm

deploy:
	golem-cli template add --template-name $(PROJECT_NAME) ./build/$(PROJECT_NAME).wasm

deploy-update:
	golem-cli template update --template-name $(PROJECT_NAME) ./build/$(PROJECT_NAME).wasm

spawn-worker:
	golem-cli worker add --worker-name $(WORKER_NAME) --template-name $(PROJECT_NAME) --env URL='https://example.com'

delete-worker:
	golem-cli worker delete --worker-name $(WORKER_NAME) --template-name $(PROJECT_NAME)