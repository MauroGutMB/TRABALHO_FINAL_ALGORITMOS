#include "../dbCONN/dbFetch.h"
#include <sqlite3.h>
#include <stdio.h>
#include <string.h>

Usuario novo_usuario(char nome[], char cpf[], int idade) {
  sqlite3 *db = NULL;
  sqlite3_stmt *stmt = NULL;

  Usuario novoUsuario;
  strcpy(novoUsuario.nome, nome);
  strcpy(novoUsuario.cpf, cpf);
  novoUsuario.idade = idade;

  if (sqlite3_open("db/dados.db", &db) != SQLITE_OK) {
    printf("Erro ao abrir banco!\n");
    return novoUsuario;
  }

  char *sql = "INSERT INTO usuarios (nome, cpf, idade) VALUES (?, ?, ?);";

  if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
    printf("Erro no prepare: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return novoUsuario;
  }

  sqlite3_bind_text(stmt, 1, nome, -1, SQLITE_TRANSIENT);
  sqlite3_bind_text(stmt, 2, cpf, -1, SQLITE_TRANSIENT);
  sqlite3_bind_int(stmt, 3, idade);

  if (sqlite3_step(stmt) == SQLITE_DONE) {
    // printf("✅ Usuario inserido!\n");
  } else {
    // printf("❌ Falha no INSERT: %s\n", sqlite3_errmsg(db));
  }

  sqlite3_finalize(stmt);
  sqlite3_close(db);

  return novoUsuario;
}

void remover_usuario(char cpf[]){
  
  sqlite3 *db = NULL;
  sqlite3_stmt *stmt = NULL;

  if (sqlite3_open("db/dados.db", &db) != SQLITE_OK) {
    printf("Erro ao abrir banco!\n");
  }

  char *sql = "DELETE FROM usuarios WHERE cpf = ?";

  if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
    printf("Erro no prepare: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
  }

  sqlite3_bind_text(stmt, 1, cpf, -1, SQLITE_TRANSIENT);

  if (sqlite3_step(stmt) == SQLITE_DONE) {
    // printf("✅ Usuario deletado!\n");
  } else {
    // printf("❌ Falha no delete: %s\n", sqlite3_errmsg(db));
  }

  sqlite3_finalize(stmt);
  sqlite3_close(db);
} 

void buscar_cpf_por_nome(char nome[], char cpf_out[], int cpf_out_size) {
  sqlite3 *db = NULL;
  sqlite3_stmt *stmt = NULL;

  if (sqlite3_open("db/dados.db", &db) != SQLITE_OK) {
    printf("Erro ao abrir banco!\n");
    return;
  }

  char *sql = "SELECT cpf FROM usuarios WHERE nome = ?";

  if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
    printf("Erro no prepare: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return;
  }

  sqlite3_bind_text(stmt, 1, nome, -1, SQLITE_TRANSIENT);

  int step = sqlite3_step(stmt);
  if (step == SQLITE_ROW) {
    const unsigned char *cpf_sqlite = sqlite3_column_text(stmt, 0);
    strncpy(cpf_out, (const char *)cpf_sqlite, cpf_out_size - 1);
    cpf_out[cpf_out_size - 1] = '\0'; // Garantir null terminator
    // printf("✅ CPF encontrado: %s\n", cpf_out);
  } else {
    // printf("❌ Nenhum usuário encontrado com nome '%s'\n", nome);
    cpf_out[0] = '\0'; // Limpa se não encontrar
  }

  sqlite3_finalize(stmt);
  sqlite3_close(db);
}
