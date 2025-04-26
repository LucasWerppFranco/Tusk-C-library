#ifndef TUSK_H
#define TUSK_H

// Função para configurar o terminal em modo não bloqueante
void set_conio_terminal_mode();

// Função para restaurar as configurações do terminal
void reset_terminal_mode();

// Função para verificar se há um caractere disponível para leitura
int kbhit();

#endif // CONIO_LIB_H
