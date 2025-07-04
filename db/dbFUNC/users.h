typedef struct {
  int id;
  char nome[50];
  char cpf[50];
  int idade;
} Usuario;

Usuario novo_usuario(int id, char nome[50], char cpf[50], int idade);
