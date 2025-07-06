#include "UI/ui.h"
#include "db/dbFUNC/users.h"
#include "src/funcs.h"
#include <ncurses.h>
#include <sqlite3.h>
#include <stdio.h>

int main() {

  int admlogin;
  int telaAdm = 1;

  /*
    'admlogin' pode receber 1, 2 ou 3:
    1. Remover Usuario
    2. Adicionar voo
    3. Remover voo
  */

  while (telaAdm) {

    admlogin = menuAdmin();

    printf("%i\n", admlogin);

    if (admlogin == 1) {
      clear();
      menuDelUsuario();
    }

    if(admlogin == 4){
      telaAdm = 0;
      clear();
    }

  }

  return 0;
}
