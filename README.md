# Sistema de Aeroporto

Trabalho final para a disciplina the PDS2 UFMG (2024/1).

Grupo:
- Amanda Fiaux
- Glaucus
- Pedro Pessoa

## Uso

O programa foi desenhado em torno de casos de teste, portanto não há uma interface para uso direto do programa.

Para compilar o programa e rodar os testes, você precisará:
- ter instalado no sistema o programa [make](https://www.gnu.org/software/make/).
- ter instalado no sistema o compilaodr g++.
- clonar o repositório localmente.

Com esses requisitos satisfeitos, basta rodar:

```bash
# roda todos os testes
make tests

# roda os testes funcionais
make functional_tests

# roda os testes unitarios
make unit_tests
```

## Guia de Estilo

```cpp
class NomeDeClasse {}; // 
int NomeDeMetodo {}; //

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
