#include "ui.h"
#include <ncurses.h>
#include <string.h>


//
//
// ------------------------------------------------------------------------------- //
// ------------------------------------------------------------------------------- //
//
//                FUNÇÕES GERAIS DE ORGANIZAÇÃO

void centralizar(int nPalavras, char *palavras[], int posicao[2]){

  int largura = 0;
  int altura = nPalavras;

  for(int i = 0; i < nPalavras; i++){
    int tempLarg = strlen(palavras[i]);
    if(tempLarg > largura){
      largura = tempLarg;
    }
  }

  int xInicial = (COLS - largura) / 2;
  int yInicial = (LINES - altura) / 2;

  // parametros do mvprintw -> (y, x, string)
  posicao[0] = yInicial;
  posicao[1] = xInicial;
}

//
//
// ------------------------------------------------------------------------------- //
// ------------------------------------------------------------------------------- //
//
//                                    LOGIN

void cabecalhoLogin(int posicao[2]){

  char *textos[] = {
    "SISTEMA DE RESERVA DE VOOS",
    "Faca login para ter acesso ao sistema"
  };

  mvprintw(posicao[0] - 7, posicao[1] - 10, "%s", textos[0]);
  mvprintw(posicao[0] - 5, posicao[1] - 15, "%s", textos[1]);
}


int menuLogin(){

  int nOpts = 3;

  char *opts[] = {
    "Login",
    "Cadastrar",
    "Sair"
  };

  initscr();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
  curs_set(0);

  int posicao[2];
  posicao[0] = 1, posicao[1] = 1;

  centralizar(nOpts, opts, posicao);

  cabecalhoLogin(posicao);

  int telaMenu = 1;

  int seta = 0;
  int escolha = -1;
  int c;

  while(telaMenu){

    for(int i = 0; i < nOpts; i++){

      if(i == seta){
        attron(A_REVERSE);
      }
      mvprintw(i + posicao[0], posicao[1], "%s", opts[i]);
      attroff(A_REVERSE);

    }

    c = getch();

    switch(c){
      case KEY_UP: seta = (seta - 1 + nOpts) % nOpts; break;
      case KEY_DOWN: seta = (seta + 1) % nOpts; break;
      case 10: escolha = seta; break; // 10 = Enter
    }

    if(escolha == 0){
      endwin();
      return 1; // Login
    } else if(escolha == 1){
      endwin();
      return 2; // Cadastrar
    }

    if(escolha != -1){
      break;
    }

  }

  endwin();
  return 0;

}

//
//
// ------------------------------------------------------------------------------- //
// ------------------------------------------------------------------------------- //



// ------------------------------------------------------------------------------- //
// ------------------------------------------------------------------------------- //
//
//                                 ADMIN - INICIAL

void cabecalhoAdmin(int posicao[2]){

  char *textos[] = {
    "SISTEMA DE RESERVA DE VOOS",
    "Sistema reservado para administradores"
  };

  mvprintw(posicao[0] - 5, posicao[1] - 11, "%s", textos[1]);
  mvprintw(posicao[0] - 7, posicao[1] - 6, "%s", textos[0]);
}


int menuAdmin(){

  int nOpts = 3;

  char *opts[] = {
    "Remover Usuario",
    "Adicionar Voo",
    "Remover voo"
  };

  initscr();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
  curs_set(0);

  int posicao[2];
  posicao[0] = 1, posicao[1] = 1;

  centralizar(nOpts, opts, posicao);

  cabecalhoAdmin(posicao);

  int telaMenu = 1;

  int seta = 0;
  int escolha = -1;
  int c;

  while(telaMenu){

    for(int i = 0; i < nOpts; i++){

      if(i == seta){
        attron(A_REVERSE);
      }
      mvprintw(i + posicao[0], posicao[1], "%s", opts[i]);
      attroff(A_REVERSE);

    }

    c = getch();

    switch(c){
      case KEY_UP: seta = (seta - 1 + nOpts) % nOpts; break;
      case KEY_DOWN: seta = (seta + 1) % nOpts; break;
      case 10: escolha = seta; break; // 10 = Enter
    }

    if(escolha == 0){
      endwin();
      return 1; // Remover usuario
    } else if(escolha == 1){
      endwin();
      return 2; // Adicionar Voo
    } else if(escolha == 2){
      endwin();
      return 3; // Remover Voo
    }


    if(escolha != -1){
      break;
    }

  }
    

  endwin();

  return 0;

}

//
//
// ------------------------------------------------------------------------------- //
// ------------------------------------------------------------------------------- //
//
//                  opção - login

void cabecalhoUserLogin(int posicao[2]){

  char *textos[] = {
    "LOGIN",
    "Escolha de usuarios"
  };

  mvprintw(posicao[0] - 5, posicao[1] - 7, "%s", textos[1]);
  mvprintw(posicao[0] - 7, posicao[1] - 2, "%s", textos[0]);
}


int menuUserLogin(){

  int usuarios = 7;

  char *opts[] = {
    "Usuario 1",
    "Usuario 2",
    "Usuario 3",
    "Usuario 4",
    "Usuario 5",
    "Usuario 6",
    "Usuario 7"
  };

  initscr();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
  curs_set(0);

  int posicao[2];
  posicao[0] = 1, posicao[1] = 1;

  centralizar(usuarios, opts, posicao);
  cabecalhoUserLogin(posicao);

  int telaMenu = 1;

  int seta = 0;
  int escolha = -1;
  int c;

  while(telaMenu){

    for(int i = 0; i < usuarios; i++){

      if(i == seta){
        attron(A_REVERSE);
      }
      mvprintw(i + posicao[0], posicao[1] - 2, "%s", opts[i]);
      attroff(A_REVERSE);

    }

    c = getch();

    switch(c){
      case KEY_UP: seta = (seta - 1 + usuarios) % usuarios; break;
      case KEY_DOWN: seta = (seta + 1) % usuarios; break;
      case 10: escolha = seta; break; // 10 = Enter
    }


    if(escolha != -1){
      endwin();
      return escolha;
    }

  }
    

  endwin();

  return 0;

}
