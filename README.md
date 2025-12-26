# Push Swap

Projeto da 42 que consiste em ordenar uma pilha de números utilizando um conjunto limitado de operações, com o objetivo de minimizar o número de movimentos.

## 📋 Descrição

O **push_swap** é um programa que recebe uma lista de números inteiros como argumentos e imprime uma sequência de instruções que ordenam esses números utilizando duas pilhas (A e B) e um conjunto específico de operações.

### Algoritmos Implementados

O projeto utiliza diferentes estratégias de ordenação dependendo da quantidade de elementos:

- **2 números:** Algoritmo direto com swap (máx. 1 operação)
- **3 números:** Algoritmo hardcoded para todas as permutações (máx. 2 operações)
- **4-5 números:** Selection Sort parcial + sort_three (máx. 12 operações)
- **Mais de 5:** Radix Sort adaptado para pilhas, baseado em bits

### Operações Disponíveis

- `sa`: swap a - troca os dois primeiros elementos da pilha A
- `sb`: swap b - troca os dois primeiros elementos da pilha B
- `ss`: swap both - executa sa e sb simultaneamente
- `pa`: push a - move o primeiro elemento de B para o topo de A
- `pb`: push b - move o primeiro elemento de A para o topo de B
- `ra`: rotate a - rotaciona todos os elementos de A (o primeiro vira o último)
- `rb`: rotate b - rotaciona todos os elementos de B
- `rr`: rotate b e Comandos

### Requisitos
- GCC ou outro compilador C
- Make

### Comandos Disponíveis

```bash
make           # Compila o projeto
make clean     # Remove arquivos objeto
make fclean    # Remove arquivos objeto e executável
make re        # Recompila tudo do zero
make test N=5  # Testa com N números aleatórios e valida resultado
make start N=5 # Executa com N números aleatórios (sem validação)

```bash
make clean    # Remove arquivos objeto
make fclean   # Remove arquivos objeto e executável
make re       # Recompila tudo do zero
```

## 🚀 Como Usar

### Execução Básica

```bash
./push_swap [números]
```

### Exemplos de Execução

```bash
# Ordenar números
./push_swap 4 2 8 1 9

# Com números negativos
./push_swap -3 5 -1 0 2

# Passando como string
./push_swap "4 2 8 1 9"

# Verificar resultado com checker
./push_swap 4 2 8 1 9 | ./checker_linux 4 2 8 1 9

# Contar operações
./push_swap 4 2 8 1 9 | wc -l
```

### Testes Automatizados

```bash
# Testa com validação completa
make test N=3    # 3 números
make test N=5    # 5 números
make test N=100  # 100 números
make test N=500  # 500 números

# Apenas executa (sem validar)
make start N=100
```

O comando `make test` irá:
- Gerar N números aleatórios de 1 a N
- Executar o push_swap
- Validar com o checker_linux
- Mostrar resultado (OK/KO) e número de movimentos
- Algum argumento não é um número inteiro
## 📊 Tratamento de Erros

O programa imprime `Error` nos seguintes casos:
- Argumento não é um número inteiro
- Argumento excede os limites INT_MIN (-2147483648) ou INT_MAX (2147483647)
- Números duplicados

## 🏗️ Estrutura do Projeto

```
push-swap/
├── Makefile           # Arquivo de compilação
├── checker_linux      # Programa para verificar resultado
├── libs/             # Bibliotecas customizadas
│   ├── charft/       # Funções de caracteres
│   ├── hsft/         # Tabela hash
│   ├── listft/       # Estrutura de lista encadeada
│   ├── mathft/       # Funções matemáticas
│   ├── memft/        # Gerenciamento de memória
│   └── stringft/     # Manipulação de strings
└── src/              # Código fonte principal
    ├── main.c
    ├── push_swap.h
    ├── algorithms/   # Implementação do Radix Sort
    ├── instructions/ # Operações das pilhas
    ├── parser/       # Parsing e validação de argumentos
    └── utils/        # Funções auxiliares
```