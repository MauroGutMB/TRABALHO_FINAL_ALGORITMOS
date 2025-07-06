int fetch_all_users(char nomes[][50], int maxUsuarios);

typedef struct {
  char nome[50];
  char cpf[20];
  int idade;
} Usuario;

typedef struct {
  char origem[50];
  char destino[50];
  char horario_partida[20];
  char horario_chegada[20];
  int codigo_voo;
} Voo;

typedef struct {
  int assento;
  int codigo_voo;
  char cpf_usuario[20];
  int codigo_reserva;
} Reserva;
