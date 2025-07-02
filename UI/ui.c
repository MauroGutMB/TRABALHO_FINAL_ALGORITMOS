#include "ui.h"
#include <ncurses.h>
#include <string.h>

#define nOpts 3

const char *opts[nOpts] = {
  "Login",
  "Cadastrar",
  "Sair",
};

const char *textos[] = {
  "SISTEMA DE RESERVA DE VOOS",
  "Faca login para ter acesso ao sistema"
};

void cabecalhoLogin(int posicao[2]){
  mvprintw(posicao[0] - 5, posicao[1] - 15, "%s", textos[1]);
  mvprintw(posicao[0] - 7, posicao[1] - 10, "%s", textos[0]);
}

void centralizar(const char *palavras[], int posicao[2]){

  int largura = 0;
  int altura = nOpts;

  for(int i = 0; i < nOpts; i++){
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

int menuLogin(){

  initscr();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
  curs_set(0);

  int posicao[2];
  posicao[0] = 1, posicao[1] = 1;

  centralizar(opts, posicao);

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
