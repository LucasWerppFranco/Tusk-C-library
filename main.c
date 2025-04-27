#include <stdio.h>
#include <time.h>
#include "tusk.h"

int main() {
    set_conio_terminal_mode(); 
    printf("Pressione 'n' para ver a mensagem ou 'q' para sair.\n");

    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = 100000 * 1000; 

    while (1) {
        if (kbhit()) { 
            char ch = getchar(); 
            if (ch == 'n') {
                printf("Você pressionou a tecla 'n'!\n");
            } else if (ch == 'q') {
                break; 
            }
        }
        nanosleep(&ts, NULL);
    }

    reset_terminal_mode(); 
    return 0; 
}
