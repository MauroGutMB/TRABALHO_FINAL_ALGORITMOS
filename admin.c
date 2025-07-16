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
    4. Sair
  */

  while (telaAdm) {

    admlogin = menuAdmin();

    printf("%i\n", admlogin);

    switch(admlogin){
      case 1: clear(); menuDelUsuario(); break;
      case 2: clear(); menuAddVoo(); break;
      case 3: clear(); menuDelVoo(); break;
      case 4: clear(); telaAdm = 0; break;
    }

  }

  return 0;
}
