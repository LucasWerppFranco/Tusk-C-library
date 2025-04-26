# Projeto de Biblioteca de Entrada de Teclado

Este projeto contém uma biblioteca em C chamada `tusk`, que permite a leitura de teclas do teclado em modo não bloqueante em sistemas Unix/Linux. A biblioteca é útil para aplicações que precisam reagir imediatamente à entrada do usuário sem esperar por um Enter.

## Estrutura do Projeto

/projeto 
│
├── conio_lib.h # Cabeçalho da biblioteca 
├── conio_lib.c # Implementação da biblioteca 
└── main.c # Programa principal que utiliza a biblioteca

## Funcionalidades da Biblioteca

### 1. `set_conio_terminal_mode()`

Esta função configura o terminal para o modo não bloqueante. Ela desativa o modo canônico, permitindo que a entrada do teclado seja lida imediatamente, e desativa o eco, para que os caracteres digitados não sejam exibidos na tela.

### 2. `reset_terminal_mode()`

Esta função restaura as configurações padrão do terminal, reativando o modo canônico e o eco. Deve ser chamada antes de encerrar o programa para garantir que o terminal retorne ao seu estado normal.

### 3. `kbhit()`

Esta função verifica se há um caractere disponível para leitura no buffer de entrada. Se um caractere estiver disponível, ele é lido e colocado de volta no buffer, permitindo que o programa o processe. A função retorna 1 se um caractere estiver disponível e 0 caso contrário.

## Exemplo de Uso

O arquivo `main.c` demonstra como utilizar a biblioteca `conio_lib` para detectar a entrada do usuário. Abaixo está uma explicação detalhada do código:

```c
#include <stdio.h>
#include "conio_lib.h"

int main() {
    set_conio_terminal_mode(); // Configura o terminal em modo não bloqueante
    printf("Pressione 'n' para ver a mensagem ou 'q' para sair.\n");

    while (1) {
        if (kbhit()) { // Verifica se há um caractere disponível
            char ch = getchar(); // Lê o caractere
            if (ch == 'n') {
                printf("Você pressionou a tecla 'n'!\n");
            } else if (ch == 'q') {
                break; // Sai do loop se 'q' for pressionado
            }
        }
        usleep(100000); // Espera um pouco para evitar uso excessivo da CPU
    }

    reset_terminal_mode(); // Restaura as configurações do terminal
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
```

## Explicação do Código

- **1** Inclusão de Cabeçalho: O programa inclui o cabeçalho da biblioteca conio_lib.h, que contém as declarações das funções.

- **2** Configuração do Terminal: A função set_conio_terminal_mode() é chamada para configurar o terminal em modo não bloqueante.

- **3** Loop Principal: O programa entra em um loop infinito onde verifica continuamente se uma tecla foi pressionada usando a função kbhit().

- **4** Leitura de Teclas: Se uma tecla estiver disponível, ela é lida com getchar(). Se a tecla for 'n', uma mensagem é exibida. Se a tecla for 'q', o loop é encerrado.

- **5** Restauração do Terminal: Antes de encerrar, a função reset_terminal_mode() é chamada para restaurar as configurações do terminal.


## Compilação

Para compilar a biblioteca e o programa principal, use os seguintes comandos no terminal:

```bash
gcc -c conio_lib.c -o conio_lib.o  # Compila a biblioteca
gcc main.c conio_lib.o -o main      # Compila o programa principal
```

## Execução

Após a compilação, você pode executar o programa com o seguinte comando:

```bash
./main
```

Pressione 'n' para ver a mensagem ou 'q' para sair do programa.

### Notas Finais

- Você ainda existem seções para serem adicionadas conforme o projeto anda, como por exemplo: "Instalação", "Uso", "Exemplos", etc...
