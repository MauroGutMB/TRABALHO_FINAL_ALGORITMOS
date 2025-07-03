#include <ncurses.h>
#include <sqlite3.h>
#include <stdio.h>
#include "src/funcs.h"
#include "UI/ui.h"

int main(){

  int admlogin;

  admlogin = menuAdmin(); 

  /*
    'admlogin' pode receber 1, 2 ou 3:
    1. Remover Usuario
    2. Adicionar voo
    3. Remover voo
  */

  printf("%i\n", admlogin);

  return 0;
}
