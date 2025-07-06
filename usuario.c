#include "UI/ui.h"
#include "db/dbFUNC/users.h"
#include "src/funcs.h"
#include <ncurses.h>
#include <sqlite3.h>
#include <stdio.h>

int main() {

  int logado;
  int tela = 1;

  while (tela) {

    clear();
    logado = menuLogin();

    /*
      'logado' pode receber 0, 1 ou 2:
      1. Login
      2. Cadastrar
      0. Nenhuma ação. Sair do programa.
    */

    if (logado == 0) {
      break;
    }

    if (logado == 1) {
      clear();

      int teste = menuUserLogin();
      printf("Usuario de Index: %i\n", teste);
    }

    if (logado == 2) {
      printf("Novo usuario.\n");
      clear();
      menuCadastro();
    }
  }

  return 0;
}
