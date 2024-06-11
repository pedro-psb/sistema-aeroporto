# Sistema de Aeroporto

Trabalho final para a disciplina the PDS2 UFMG (2024/1).

Grupo:
- Amanda Fiaux
- Glaucus
- Pedro Pessoa

## Testando

### Basico

O programa é uma biblioteca desenvolvida em torno de certos requisitos.

Para compilar o programa e rodar os testes, você precisará:
- instalar o [cmake](https://cmake.org/download/).
- instalar o compilaodr g++.

Então, basta clonar o repositório e mudar para a pasta.

```bash
# especifica e configura o diretorio de build em ./build
cmake -B build

# muda para diretorio com Makefile gerado
cd build

# faz o build da biblioteca e dos testes
make

# roda todos os testes
ctest

# execute um teste diretamente (mesmo nome que os cpps em ./tests):
./flight_module_test
```

### Opcoes Uteis

```bash
# para rodar da raiz do repositorio, especifique a pasta build:
ctest --test-dir build

# opcoes do ctest (estando na pasta build):
ctest --show-only
ctest --rerun-failed --output-on-failure
ctest --rerun-failed --output-on-failure
```

## Guia de Estilo

```cpp
// Arquivo.hpp
class NomeDeClasse {
    public:
        int nomeDeVariavel;
        void nomeDeMetodo(string nomeDeParametro);
}; 
```

## Design

## Geral

Decidimos criar uma simulação de um sistema de aeroporto para explorar alguns aspectos da complexidade de tal sistema.

Para que o projeto fosse viável, restringimos o modelo do sistema em 3 grandes subsistemas:
- Sistema de Vendas: responsável por gerenciar a compra/venda de passagens e interação com clientes
- Sistema de Escalas: responsável por gerar escalas de voos e gerenciá-las junto aos recursos disponíveis
- Sistema de Recursos: responsável por gerenciar os recursos, alocando e desalocando de acordo com a disponibilidade

## Requisitos

**Sistema de Vendas**
    - Processar compra/cancelamento de `Passagem` de um `Cliente`
    - Solicitar próximo `Voo` a partir de `Data` que vai para `Destino` solicitado (consulta)
- **Sistema de Escalas**
    - Adicionar/Remover `Cliente` de um `Voo`
    - Criar `Voo` e escala de voos mensal
- **Sistema de Recursos**
    - Alocar e desalocar recursos do aeroporto (tripulação, voos e pistas)
