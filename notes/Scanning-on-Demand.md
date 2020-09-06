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
- During lexical analysis use the source program as character store.We can do this if we represent a lexeme by using a pointer to its first character and the number of characters it contains. By doing so we don't need to manage memory as free pass the tokens around.So it is really important to make sure that the original source code string has a long enough lifetime.That’s why **runFile()** doesn’t free the string until **interpret()** finishes executing the code and returns.

-
