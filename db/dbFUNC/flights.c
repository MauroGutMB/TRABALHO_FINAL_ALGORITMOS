#include "../dbCONN/dbFetch.h"
#include "../dbFUNC/flights.h"
#include <sqlite3.h>
#include <stdio.h>
#include <string.h>

Voo novo_voo(char origem[], char destino[], char partida[], char chegada[], int codigo_voo) {
  sqlite3 *db = NULL;
  sqlite3_stmt *stmt = NULL;

  Voo novoVoo;
  strcpy(novoVoo.origem, origem);
  strcpy(novoVoo.destino, destino);
  strcpy(novoVoo.horario_partida, partida);
  strcpy(novoVoo.horario_chegada, chegada);

  if (sqlite3_open("db/dados.db", &db) != SQLITE_OK) {
    printf("Erro ao abrir banco!\n");
    return novoVoo;
  }

  char *sql = "INSERT INTO voos (origem, destino, horario_partida, horario_chegada, codigo_voo) VALUES (?, ?, ?, ?, ?);";

  if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
    printf("Erro no prepare: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return novoVoo;
  }

  sqlite3_bind_text(stmt, 1, origem, -1, SQLITE_TRANSIENT);
  sqlite3_bind_text(stmt, 2, destino, -1, SQLITE_TRANSIENT);
  sqlite3_bind_text(stmt, 3, partida, -1, SQLITE_TRANSIENT);
  sqlite3_bind_text(stmt, 4, chegada, -1, SQLITE_TRANSIENT);
  sqlite3_bind_int(stmt, 5, codigo_voo);

  if (sqlite3_step(stmt) == SQLITE_DONE) {
    // printf("✅ Usuario inserido!\n");
  } else {
    // printf("❌ Falha no INSERT: %s\n", sqlite3_errmsg(db));
  }

  sqlite3_finalize(stmt);
  sqlite3_close(db);

  return novoVoo;
}

void remover_voo(int codigo_voo){
  
  sqlite3 *db = NULL;
  sqlite3_stmt *stmt = NULL;

  if (sqlite3_open("db/dados.db", &db) != SQLITE_OK) {
    printf("Erro ao abrir banco!\n");
  }

  char *sql = "DELETE FROM voos WHERE codigo_voo = ?";

  if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
    printf("Erro no prepare: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
  }

  sqlite3_bind_int(stmt, 1, codigo_voo);

  if (sqlite3_step(stmt) == SQLITE_DONE) {
    // printf("✅ Usuario deletado!\n");
  } else {
    // printf("❌ Falha no delete: %s\n", sqlite3_errmsg(db));
  }

  sqlite3_finalize(stmt);
  sqlite3_close(db);
} 
