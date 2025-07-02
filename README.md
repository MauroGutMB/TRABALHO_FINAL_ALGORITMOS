# 📚 Meu Projeto em C

Este projeto é um exemplo simples de como organizar um programa em **C** com múltiplos arquivos e um **Makefile** para automatizar a compilação.

---

## 📂 Estrutura de Pastas

```
.
├── .git/
├── Makefile
└── src/
    ├── main.c
    ├── funcs.c
    ├── funcs.h
    ├── main      # (executável gerado pelo make)
    ├── main.o    # (gerado)
    └── funcs.o   # (gerado)
```

---

## ⚙️ Como Compilar

1. **Instale o GCC** (se ainda não tiver):

   ```bash
   sudo apt install build-essential   # Debian/Ubuntu
   ```

2. **Compile o projeto** (na raiz):

   ```bash
   make
   ```

   Isso gera o executável `src/main`.

3. **Execute**:

   ```bash
   ./src/main
   ```

4. **Limpe os arquivos gerados**:

   ```bash
   make clean
   ```

---

## 📄 Como funciona o `Makefile`

- **Compila cada `.c` em `.o`** automaticamente.
- Liga os objetos no executável final.
- Guarda tudo dentro da pasta `src/`.

---

## 🗑️ Limpeza

Use `make clean` para remover todos os arquivos objeto (`*.o`) e o executável.

---

## ✅ Dicas

- Edite seus arquivos fonte dentro de `src/`.
- Mantenha o `Makefile` na raiz para organização.
- Use `-Wall` para ver todos os warnings do compilador.

---

## 🚀 Sobre

Este é apenas um exemplo didático. Expanda como quiser! 🔧✨
