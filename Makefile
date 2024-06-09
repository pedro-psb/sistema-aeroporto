.PHONY: help run_test build

help: ## Mostra comandos disponíveis.
	@awk 'BEGIN {FS = ":.*##"; printf "\nCommands:\n"} /^[a-zA-Z_0-9-]+:.*?##/ { printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)

build: ## Compila a biblioteca e os testes do projeto.
	@mkdir -p build
	cmake -B build
	cmake --build build

clean: ## Limpa o diretorio de build.
	@rm -rf build

list_tests: ## Lista os testes compilados.
	@mkdir -p build
	@find build -type f -name *_test
