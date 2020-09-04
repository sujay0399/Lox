- Lox has three parts:

  - Scanner
  - Compiler
  - Virtual machine

- Tokens flow from Scanner to Compiler.
- Chunks of bytecode flow from Compiler to Virtual machine.

### Source code ==> Scanner ==> Tokens ==> Compiler ==> Bytecode Chunk ==> VM(runs the program)

- fprintf is used to print content in file instead of stdout console.
  ```
      int fprintf(FILE *fptr, const char *str, ...);
  ```
