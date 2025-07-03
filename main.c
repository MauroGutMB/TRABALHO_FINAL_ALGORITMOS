#include <ncurses.h>
#include <sqlite3.h>
#include <stdio.h>
#include "src/funcs.h"
#include "src/reservas.h"   
#include "UI/ui.h"

int main(){

    int logado;

    logado = menuLogin(); 

    /*
      'logado' pode receber:
      1. Login
      2. Cadastrar
      0. Nenhuma ação. Sair do programa.
    */

    printf("Status login: %i\n", logado);

    if (logado == 1) {
        int opcao;
        do {
            printf("\n--- MENU PRINCIPAL ---\n");
            printf("1. Cadastrar novo voo\n");
            printf("2. Exibir todos os voos\n");
            printf("3. Pesquisar voos\n");
            printf("0. Sair\n");
            printf("Escolha: ");
            scanf("%d", &opcao);

            switch(opcao) {
                case 1:
                    cadastrarVoo();
                    break;
                case 2:
                    exibirVoos();
                    break;
                case 3:
                    pesquisarVoos();
                    break;
                case 0:
                    printf("Saindo do sistema...\n");
                    break;
                default:
                    printf("Opção inválida! Tente novamente.\n");
            }
        } while (opcao != 0);
    } else if (logado == 2) {
        printf("Cadastrar novo usuário... (FUNÇÃO AINDA NÃO IMPLEMENTADA)\n");
    } else {
        printf("Encerrando programa.\n");
    }

    return 0;
}
