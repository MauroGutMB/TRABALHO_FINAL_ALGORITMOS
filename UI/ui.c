#include "ui.h"
#include "../db/dbFUNC/users.h"
#include "../db/dbFUNC/flights.h"
#include <ncurses.h>
#include <sqlite3.h>
#include <string.h>

//
//
// -------------------------------------------------------------------------------
// //
// -------------------------------------------------------------------------------
// //
//
//                FUNÇÕES GERAIS DE ORGANIZAÇÃO

void centralizar(int n_palavras, char *palavras[], int posicao[2]) {
  int largura_max = 0;
  for (int i = 0; i < n_palavras; i++) {
    int largura_atual = strlen(palavras[i]);
    if (largura_atual > largura_max) {
      largura_max = largura_atual;
    }
  }
  int x_inicial = (COLS - largura_max) / 2;
  int y_inicial = (LINES - n_palavras) / 2;
  posicao[0] = y_inicial;
  posicao[1] = x_inicial;
}

//
//
// -------------------------------------------------------------------------------
// //
// -------------------------------------------------------------------------------
// //
//
//                                    LOGIN

void cabecalhoLogin(int posicao[2]) {
  const char *cabecalhos[] = {"SISTEMA DE RESERVA DE VOOS",
                              "Faca login para ter acesso ao sistema"};
  mvprintw(posicao[0] - 7, posicao[1] - 10, "%s", cabecalhos[0]);
  mvprintw(posicao[0] - 5, posicao[1] - 15, "%s", cabecalhos[1]);
}

int menuLogin() {

  int nOpts = 3;

  char *opts[] = {"Login", "Cadastrar", "Sair"};

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

  while (telaMenu) {

    for (int i = 0; i < nOpts; i++) {

      if (i == seta) {
        attron(A_REVERSE);
      }
      mvprintw(i + posicao[0], posicao[1], "%s", opts[i]);
      attroff(A_REVERSE);
    }

    c = getch();

    switch (c) {
    case KEY_UP:
      seta = (seta - 1 + nOpts) % nOpts;
      break;
    case KEY_DOWN:
      seta = (seta + 1) % nOpts;
      break;
    case 10:
      escolha = seta;
      break; // 10 = Enter
    }

    if (escolha == 0) {
      endwin();
      return 1; // Login
    } else if (escolha == 1) {
      endwin();
      return 2; // Cadastrar
    }

    if (escolha != -1) {
      break;
    }
  }

  endwin();
  return 0;
}

//
//
// -------------------------------------------------------------------------------
// //
// -------------------------------------------------------------------------------
// //
//
//

//
//
// -------------------------------------------------------------------------------
// //
// -------------------------------------------------------------------------------
// //
//
//                           MENU CADASTRAR

void menuCadastro() {
  char nome[50];
  char cpf[50];
  int idade;

  initscr(); // Inicializa ncurses
  cbreak();  // Desabilita buffer de linha
  noecho();  // Não mostra os caracteres digitados
  curs_set(0);
  keypad(stdscr, TRUE); // Habilita teclas especiais

  // Título
  mvprintw(-4, COLS - 20 / 2, "MENU DE CADASTRO");

  // Nome
  mvprintw(5, (COLS - 20) / 2, "Digite seu nome: ");
  echo();
  getnstr(nome, 50);
  noecho();

  // CPF
  mvprintw(7, (COLS - 20) / 2, "Digite seu CPF: ");
  echo();
  getnstr(cpf, 50);
  noecho();

  // Idade
  mvprintw(9, (COLS - 20) / 2, "Digite sua idade: ");
  echo();
  scanw("%i", &idade);
  noecho();

  clear();
  mvprintw(5, (COLS - 20) / 2, "Dados Inseridos");
  mvprintw(7, (COLS - 20) / 2, "Nome : %s", nome);
  mvprintw(8, (COLS - 20) / 2, "CPF  : %s", cpf);
  mvprintw(9, (COLS - 20) / 2, "Idade: %d", idade);

  mvprintw(11, (COLS - 20) / 2, "Pressione 'c' para confirmar.");
  mvprintw(12, (COLS - 20) / 2, "Pressione qualquer botao para cancelar.");
  char c = getch();

  if (c == 'c') {
    novo_usuario(nome, cpf, idade);
  }

  clear();
  endwin();
}

//
// -------------------------------------------------------------------------------
// //
// -------------------------------------------------------------------------------
// //
//
//                        ADMIN - ADICIONAR VOO

// Voo novo_voo(char origem[], char destino[], char partida[], char chegada[], int codigo_voo) {

void menuAddVoo() {
  char origem[50];
  char destino[50];
  char partida[50];
  char chegada[50];
  int codigo_voo;

  initscr(); // Inicializa ncurses
  cbreak();  // Desabilita buffer de linha
  noecho();  // Não mostra os caracteres digitados
  curs_set(0);
  keypad(stdscr, TRUE); // Habilita teclas especiais

  // Título
  mvprintw(-4, COLS - 20 / 2, "INSERCAO DE VOOS");

  // Origem
  mvprintw(5, (COLS - 20) / 2, "Origem do voo: ");
  echo();
  getnstr(origem, 50);
  noecho();

  // Destino
  mvprintw(7, (COLS - 20) / 2, "Destino do voo: ");
  echo();
  getnstr(destino, 50);
  noecho();

  // Horario de partida
  mvprintw(9, (COLS - 20) / 2, "Horario de partida do voo: ");
  echo();
  getnstr(partida, 50);
  noecho();

  // Horario de chegada
  mvprintw(11, (COLS - 20) / 2, "Horario de chegada do voo: ");
  echo();
  getnstr(chegada, 50);
  noecho();


  // Codigo
  mvprintw(13, (COLS - 20) / 2, "Insira o codigo do voo: ");
  echo();
  scanw("%i", &codigo_voo);
  noecho();

  clear();
  mvprintw(5, (COLS - 20) / 2, "Dados Inseridos");
  mvprintw(6, (COLS - 20) / 2, "Origem : %s", origem);
  mvprintw(7, (COLS - 20) / 2, "Destino  : %s", destino);
  mvprintw(8, (COLS - 20) / 2, "Horario de partida: %s", partida);
  mvprintw(9, (COLS - 20) / 2, "Horario de chegada  : %s", chegada);
  mvprintw(10, (COLS - 20) / 2, "Codigo do voo: %i", codigo_voo);

  mvprintw(12, (COLS - 20) / 2, "Pressione 'c' para confirmar.");
  mvprintw(13, (COLS - 20) / 2, "Pressione qualquer botao para cancelar.");
  char c = getch();

  if (c == 'c') {
   novo_voo(origem, destino, partida, chegada, codigo_voo); 
  }

  clear();
  endwin();
}
//
// -------------------------------------------------------------------------------
// //
// -------------------------------------------------------------------------------
// //
//
//                        ADMIN - REMOVER USUARIO


void menuDelUsuario() {

  int menuUs = 1;

  int maxUsuarios = 50;
  char nomes[maxUsuarios][50];

  int totalUsuarios = fetch_all_users(nomes, maxUsuarios);

  if(totalUsuarios == 0){
    menuUs = 0;
    clear();
    endwin();
  }

  int seta = 0;
  int escolha = -1;
  int c = 0;

  initscr();
  cbreak();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);



  while (menuUs) {

    escolha = -1;

    clear();

    // atualiza a func
    totalUsuarios = fetch_all_users(nomes, maxUsuarios);

    mvprintw(6, COLS / 2 - 15, "Selecione um usuario para ser deletado");
    mvprintw(4, COLS / 2 - 15, "ASCII >>>>> %i\n", c);
    char teste[50];
    buscar_cpf_por_nome(nomes[seta], teste, 50);
    mvprintw(3, COLS / 2 - 15, "CPF >>>>> %s\n", teste);

    for (int i = 0; i < totalUsuarios; i++) {
      if (i == seta)
        attron(A_REVERSE);
      mvprintw(i + LINES / 2 - 6, COLS / 2 - 7, "%s", nomes[i]);
      attroff(A_REVERSE);
    }

    attron(A_UNDERLINE);
    mvprintw(totalUsuarios + LINES / 2 - 5, COLS / 2 - 10, "aperte 's' para sair.");
    attroff(A_UNDERLINE);

    c = getch();
    switch (c) {
    case KEY_UP:
      seta = (seta - 1 + totalUsuarios) % totalUsuarios;
      break;
    case KEY_DOWN:
      seta = (seta + 1) % totalUsuarios;
      break;
    case 10:
      escolha = seta;
      break; // Enter
    case 115:
      menuUs = 0;
      clear();
      endwin();
      break;
    }


    if(escolha != -1){

      char cpf_del[50];
      buscar_cpf_por_nome(nomes[seta], cpf_del, 50);

      remover_usuario(cpf_del);
    }
  }
  clear();
  endwin();
}

// 
//
// -------------------------------------------------------------- //
//
//                  ADMIN - REMOVER VOO

void menuDelVoo() {

  int menuUs = 1;

  int maxVoos = 50;
  int codigos[maxVoos];

  int totalVoos = fetch_all_voos(codigos, maxVoos);

  if(totalVoos == 0){
    menuUs = 0;
    clear();
    endwin();
  }

  int seta = 0;
  int escolha = -1;
  int c = 0;

  initscr();
  cbreak();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);



  while (menuUs) {

    escolha = -1;

    clear();

    // atualiza a func
    totalVoos = fetch_all_voos(codigos, maxVoos);

    mvprintw(6, COLS / 2 - 15, "Selecione um usuario para ser deletado");

    for (int i = 0; i < totalVoos; i++) {
      if (i == seta)
        attron(A_REVERSE);
      mvprintw(i + LINES / 2 - 6, COLS / 2 - 7, "%i", codigos[i]);
      attroff(A_REVERSE);
    }

    attron(A_UNDERLINE);
    mvprintw(totalVoos + LINES / 2 - 5, COLS / 2 - 10, "aperte 's' para sair.");
    attroff(A_UNDERLINE);

    c = getch();
    switch (c) {
    case KEY_UP:
      seta = (seta - 1 + totalVoos) % totalVoos;
      break;
    case KEY_DOWN:
      seta = (seta + 1) % totalVoos;
      break;
    case 10:
      escolha = seta;
      break; // Enter
    case 115:
      menuUs = 0;
      clear();
      endwin();
      break;
    }


    if(escolha != -1){

      // char cpf_del[50];

      ////////////////////// ADICIONAR

    }
  }
  clear();
  endwin();
}
//
// -------------------------------------------------------------------------------
// //
// -------------------------------------------------------------------------------
// //
//
//                                 ADMIN - INICIAL

void cabecalhoAdmin(int posicao[2]) {

  char *textos[] = {"SISTEMA DE RESERVA DE VOOS",
                    "Sistema reservado para administradores"};

  mvprintw(posicao[0] - 5, posicao[1] - 11, "%s", textos[1]);
  mvprintw(posicao[0] - 7, posicao[1] - 6, "%s", textos[0]);
}

int menuAdmin() {

  int nOpts = 4;

  char *opts[] = {"Remover Usuario", "Adicionar Voo", "Remover voo", "Sair"};

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

  while (telaMenu) {

    for (int i = 0; i < nOpts; i++) {

      if (i == seta) {
        attron(A_REVERSE);
      }
      mvprintw(i + posicao[0], posicao[1], "%s", opts[i]);
      attroff(A_REVERSE);
    }

    c = getch();

    switch (c) {
    case KEY_UP:
      seta = (seta - 1 + nOpts) % nOpts;
      break;
    case KEY_DOWN:
      seta = (seta + 1) % nOpts;
      break;
    case 10:
      escolha = seta;
      break; // 10 = Enter
    }

    if (escolha == 0) {
      endwin();
      return 1; // Remover usuario
    } else if (escolha == 1) {
      endwin();
      return 2; // Adicionar Voo
    } else if (escolha == 2) {
      endwin();
      return 3; // Remover Voo
    } else if (escolha == 3){ 
      endwin();
      return 4; // sair
    }

    if (escolha != -1) {
      break;
    }
  }

  endwin();

  return 0;
}

//
//
// -------------------------------------------------------------------------------
// //
// -------------------------------------------------------------------------------
// //
//
//                  opção - login

void cabecalhoUserLogin(int posicao[2]) {

  char *textos[] = {"LOGIN", "Escolha de usuarios"};

  mvprintw(posicao[0] - 6, posicao[1] - 13, "%s", textos[1]);
  mvprintw(posicao[0] - 8, posicao[1] - 8, "%s", textos[0]);
}

int menuUserLogin() {
  // Define máximo de usuários
  int maxUsuarios = 50;
  char nomes[maxUsuarios][50];

  int totalUsuarios = fetch_all_users(nomes, maxUsuarios);
  if (totalUsuarios == 0) {
    return -1;
  }

  initscr();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
  curs_set(0);

  int posicao[2] = {LINES / 2, COLS / 2};

  cabecalhoUserLogin(posicao);

  int seta = 0;
  int escolha = -1;
  int c;

  while (1) {
    for (int i = 0; i < totalUsuarios; i++) {
      if (i == seta)
        attron(A_REVERSE);
      mvprintw(i + LINES / 2 - 2, COLS / 2 - 7, "%s", nomes[i]);
      attroff(A_REVERSE);
    }

    c = getch();
    switch (c) {
    case KEY_UP:
      seta = (seta - 1 + totalUsuarios) % totalUsuarios;
      break;
    case KEY_DOWN:
      seta = (seta + 1) % totalUsuarios;
      break;
    case 10:
      escolha = seta;
      break; // Enter
    }

    if (escolha != -1)
      break;
  }

  endwin();
  return escolha; // Retorna o índice do usuário escolhido
}
