# 📚 Sistema de Reservas de Voo

Projeto utilizado como trabalho final do curso de Algoritmos e Programação do curso de Análise e Desenvolvimento de Sistemas do IFPI-CACOR.

## Integrantes:  
***Mauro Gutemberg***  
***Ray Arthur***  
***Breno Guedes***  
***Iasmin***  
***Gabriel Barreira***  

---

## 📂 Estrutura de Pastas

```
.
├── .git/
├── db/
│   ├── dbCONN/
│   │   ├── dbFetch.c
│   │   └── dbFetch.h
│   └── dbFUNC/
│       ├── flights.c
│       ├── flights.h
│       ├── users.c
│       └── users.h
├── SQLdata/
│   ├── data.c
│   └── data.h
├── src/
│   ├── funcs.c
│   └── funcs.h
├── UI/
│   ├── ui.c
│   └── ui.h
├── main.c
├── Makefile
└── README.md
```

---

## ⚙️ Como Compilar

### Bibliotecas principais

- **GCC** (ou Clang) — compilador C.
- **ncurses** — interface em modo texto no terminal.
- **SQLite3** — banco de dados embutido.
- **make** — compilador automatizado de projetos.


2. **Compile o projeto** (na raiz):

   ```bash
   make
   ```

   Isso gera o executável `./main`.

3. **Execute**:

   ```bash
   ./main
   ```

4. **Limpe os arquivos gerados**:

   ```bash
   make clean
   ```

---

## 🗑️ Limpeza

Use `make clean` para remover todos os arquivos objeto (`*.o`) e o executável.
