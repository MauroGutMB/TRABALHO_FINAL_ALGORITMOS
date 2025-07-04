#include "users.h"
#include <sqlite3.h>
#include <stdio.h>
#include <string.h>

Usuario novo_usuario(int id, char nome[50], char cpf[50], int idade) {
  sqlite3 *db = NULL;
  sqlite3_stmt *stmt = NULL;

  Usuario novoUsuario;
  novoUsuario.id = id;
  strcpy(novoUsuario.nome, nome);
  strcpy(novoUsuario.cpf, cpf);
  novoUsuario.idade = idade;

  if (sqlite3_open("db/dados.db", &db) != SQLITE_OK) {
    printf("Erro ao abrir banco!\n");
    return novoUsuario;
  }

  char *sql = "INSERT INTO usuarios (id, nome, cpf, idade) VALUES (?, ?, ?, ?);";

  if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
    printf("Erro no prepare: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return novoUsuario;
  }

  sqlite3_bind_int(stmt, 1, id);
  sqlite3_bind_text(stmt, 2, nome, -1, SQLITE_TRANSIENT);
  sqlite3_bind_text(stmt, 3, cpf, -1, SQLITE_TRANSIENT);
  sqlite3_bind_int(stmt, 4, idade);

  if (sqlite3_step(stmt) == SQLITE_DONE) {
    printf("✅ Usuario inserido!\n");
  } else {
    printf("❌ Falha no INSERT: %s\n", sqlite3_errmsg(db));
  }

  sqlite3_finalize(stmt);
  sqlite3_close(db);

  return novoUsuario;
}
