#include "dbFetch.h"
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  TABELA usuarios = (nome STR, cpf STR, idade INT)
  TABELA DE voos = (origem STR, destino STR, horario_partida STR, horario_chegada_STR, codigo_voo INT)
  TABELA reservas = (assento INT, codigo_voo INT, cpf_usuario STR, codigo_reserva INT)
*/

// 
// 
// ------------------------------------------------------------------------ //
//
//                         PEGAR TODOS OS USUARIOS

int fetch_all_users(char nomes[][50], int maxUsuarios) {
  sqlite3 *db = NULL;
  sqlite3_stmt *stmt = NULL;

  if (sqlite3_open("db/dados.db", &db) != SQLITE_OK) {
    printf("Erro ao abrir banco!\n");
    return 0;
  }

  const char *sql = "SELECT nome FROM usuarios;";
  if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
    printf("Erro no prepare: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 0;
  }

  int count = 0;
  while (sqlite3_step(stmt) == SQLITE_ROW && count < maxUsuarios) {
    const unsigned char *nome = sqlite3_column_text(stmt, 0);
    strncpy(nomes[count], (const char *)nome, 50);
    nomes[count][49] = '\0'; // Garante null-termino
    count++;
  }

  sqlite3_finalize(stmt);
  sqlite3_close(db);

  return count; // Retorna quantos foram encontrados
}
