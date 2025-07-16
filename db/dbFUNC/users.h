#include "../dbCONN/dbFetch.h"

typedef struct {
  char nome[50];
  char cpf[20];
  int idade;
} Usuario;

Usuario novo_usuario(char nome[], char cpf[], int idade);
void remover_usuario(char cpf[]);
void buscar_cpf_por_nome(char nome[], char cpf_out[], int cpf_out_size);
