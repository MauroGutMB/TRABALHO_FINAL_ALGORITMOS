#include <ncurses.h>
#include <sqlite3.h>
#include <stdio.h>
#include "src/funcs.h"
#include "UI/ui.h"

int main(){

  int logado;

  logado = menuLogin(); 

  /*
    'logado' pode receber 0, 1 ou 2:
    1. Login
    2. Cadastrar
    0. Nenhuma ação. Sair do programa.
  */

  printf("%i\n", logado);

  return 0;
}
