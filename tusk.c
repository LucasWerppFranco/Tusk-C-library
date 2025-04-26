#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include "tusk.h"

// Função para configurar o terminal em modo não bloqueante
void set_conio_terminal_mode() {
    struct termios new_settings;
    tcgetattr(STDIN_FILENO, &new_settings); // Obtém as configurações atuais do terminal
    new_settings.c_lflag &= ~(ICANON | ECHO); // Desativa o modo canônico e o eco
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings); // Aplica as novas configurações
}

// Função para restaurar as configurações do terminal
void reset_terminal_mode() {
    struct termios new_settings;
    tcgetattr(STDIN_FILENO, &new_settings); // Obtém as configurações atuais do terminal
    new_settings.c_lflag |= (ICANON | ECHO); // Restaura o modo canônico e o eco
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings); // Aplica as novas configurações
}

// Função para verificar se há um caractere disponível para leitura
int kbhit() {
    struct termios oldt, newt;
    int oldf;
    tcgetattr(STDIN_FILENO, &oldt); // Obtém as configurações atuais do terminal
    newt = oldt; // Copia as configurações
    newt.c_lflag &= ~(ICANON | ECHO); // Desativa o modo canônico e o eco
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Aplica as novas configurações
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0); // Obtém as flags atuais
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK); // Define o modo não bloqueante

    int ch = getchar(); // Tenta ler um caractere
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restaura as configurações do terminal
    fcntl(STDIN_FILENO, F_SETFL, oldf); // Restaura as flags

    if(ch != EOF) { // Se um caractere foi lido
        ungetc(ch, stdin); // Coloca o caractere de volta no buffer
        return 1; // Retorna 1 para indicar que há um caractere disponível
    }

    return 0; // Retorna 0 se não houver caractere disponível
}
