# Sistema de Aeroporto

Trabalho final para a disciplina the PDS2 UFMG (2024/1).

Grupo:
- Amanda Fiaux
- Glaucus
- Pedro Pessoa

## Uso

O programa é uma biblioteca desenvolvida em torno de certos requisitos.

Para compilar o programa e rodar os testes, você precisará:
- instalar o [make](https://www.gnu.org/software/make/) e cmake.
- instalar o compilaodr g++.
- clonar o repositório localmente.

Com esses requisitos satisfeitos, basta rodar:

```bash
# veja os comandos disponiveis
make

# compila a biblioteca e os testes em ./build
make build

# roda todos os testes compilados
./run_test.sh

# se houver problemas de permissão, conserte antes de tentar novamente
chmod +x run_test.sh

# ou rode os testes individualmente
make list_tests
./build/end_to_end_test
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
