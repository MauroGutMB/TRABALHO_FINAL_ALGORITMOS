# 📚 Meu Projeto em C

Este projeto é um exemplo simples de como organizar um programa em **C** com múltiplos arquivos e um **Makefile** para automatizar a compilação.

---

## 📂 Estrutura de Pastas

```
.
├── .git/
├── Makefile
├── main.c
└── src/
    ├── funcs.c
    └──funcs.h
```

---

## ⚙️ Como Compilar

1. **Instale o GCC** (se ainda não tiver):

   ```bash
   sudo apt install build-essential   # Debian/Ubuntu
   ```

   ```bash
   sxcode-select --instal   # MacOS
   ```

2. **Compile o projeto** (na raiz):

   ```bash
   make
   ```

   Isso gera o executável `src/main`.

3. **Execute**:

   ```bash
   .main
   ```

4. **Limpe os arquivos gerados**:

   ```bash
   make clean
   ```

---

## 🗑️ Limpeza

Use `make clean` para remover todos os arquivos objeto (`*.o`) e o executável.
