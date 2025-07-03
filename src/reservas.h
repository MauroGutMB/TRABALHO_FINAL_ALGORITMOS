#ifndef RESERVAS_H
#define RESERVAS_H

#define MAX_VOOS 100

// Struct para o cadastro
typedef struct {
    int numero;
    char origem[50];
    char destino[50];
    char data[11];         
    char hora_partida[6];   
    char hora_chegada[6];   
} Voo;

// Struct para pesquisa
typedef struct {
    char origem[50];
    char destino[50];
    char data[11];          
} Pesquisa;

extern Voo voos[MAX_VOOS];
extern int qtd_voos;

// Funções
void cadastrarVoo();     
void exibirVoos();     
void pesquisarVoos();  

#endif
