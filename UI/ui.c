#include "ui.h"
#include <ncurses.h>

void tela(){

  initscr();

  printw("This is a ncurses module test.\n");

  refresh();
  getch();

  endwin();

}
