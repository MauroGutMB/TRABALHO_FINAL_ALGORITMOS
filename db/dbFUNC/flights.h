#include "../dbCONN/dbFetch.h"

typedef struct {
  char origem[50];
  char destino[50];
  char horario_partida[20];
  char horario_chegada[20];
  int codigo_voo;
} Voo;

Voo novo_voo(char origem[], char destino[], char partida[], char chegada[], int codigo_voo);
void remover_voo(int codigo_voo);
