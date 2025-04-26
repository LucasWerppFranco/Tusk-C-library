#include <stdio.h>
#include "tusk.h"

int main() {
    set_conio_terminal_mode(); 
    printf("Pressione 'n' para ver a mensagem ou 'q' para sair.\n");

    while (1) {
        if (kbhit()) { 
            char ch = getchar(); 
            if (ch == 'n') {
                printf("Você pressionou a tecla 'n'!\n");
            } else if (ch == 'q') {
                break; 
            }
        }
        usleep(100000); 
    }

    reset_terminal_mode();
    return 0; 
}
