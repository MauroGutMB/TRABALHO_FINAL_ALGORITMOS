#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "reservas.h"

Voo voos[MAX_VOOS];
int qtd_voos = 0;

// Função 
void cadastrarVoo() {
  setlocale(LC_ALL,"portuguese");
  
    if (qtd_voos >= MAX_VOOS) {
        printf("Limite máximo de voos atingido!\n");
        return;
    }

    Voo novo;
      printf("\n=== CADASTRAR VOO ===\n");
      printf("N° DO VOO: ");
      scanf("%d", &novo.numero);

      printf("ORIGEM: ");
      scanf("%s", novo.origem);

      printf("DESTINO: ");
      scanf("%s", novo.destino);

      printf("DATA: ");
      scanf("%s", novo.data);

      printf("HORA DE PARTIDA: ");
      scanf("%s", novo.hora_partida);

      printf("HORA DE CHEGADA: ");
      scanf("%s", novo.hora_chegada);

      voos[qtd_voos] = novo;
      qtd_voos++;

      printf("Voo cadastrado com sucesso!\n");
}

// Função
void exibirVoos() {
    printf("\n=== LISTA DE VOOS CADASTRADOS ===\n");
    if (qtd_voos == 0) {
        printf("Nenhum voo cadastrado.\n");
        return;
    }

    printf("N° VOO | ORINGEM | DESTINO | DATA | PARTIDA | CHEGADA\n");
    for (int i = 0; i < qtd_voos; i++) {
        printf("%d | %s | %s | %s | %s | %s\n",
               voos[i].numero, voos[i].origem, voos[i].destino,
               voos[i].data, voos[i].hora_partida, voos[i].hora_chegada);
    }
}

// Função
void pesquisarVoos() {
    char origem[50], destino[50], data[11];
    printf("\n=== PESQUISAR VOOS ===\n");
    printf("ORIGEM: ");
    scanf("%s", origem);
    printf("DESTINO : ");
    scanf("%s", destino);
    printf("DATA: ");
    scanf("%s", data);

    printf("\n=== RESULTADO DA PESQUISA ===\n");
    int encontrados = 0;
    printf("N° VOO | ORIGEM | DESTINO | DATA | PARTIDA | CHEGADA\n");
    for (int i = 0; i < qtd_voos; i++) {
        if (strcmp(voos[i].origem, origem) == 0 &&
            strcmp(voos[i].destino, destino) == 0 &&
            strcmp(voos[i].data, data) == 0) {

            printf("%d | %s | %s | %s | %s | %s\n",
                   voos[i].numero, voos[i].origem, voos[i].destino,
                   voos[i].data, voos[i].hora_partida, voos[i].hora_chegada);
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("Nenhum voo encontrado com esses critérios.\n");
    }
}

