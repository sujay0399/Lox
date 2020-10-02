- For executing a program, we first create an empty chuck and pass it over to the compiler.
- The compiler will take the chuck and fill it up with bytecode. If there is an error, we will discard the unsable chuck.

## Single-Pass compilation

- A compiler roughly has two jobs. It should to look at the source code and figure out what it means and then take that knowledge and output low-level instructions that produce same semantics. Many compilers split those roles into two seperate passes in the implementation.A parser produces AST and a code generator traverses the AST and produce Output code.
- In, Clox we perform Single Pass compilation.

- We generally report errors, at the location of the token we just consumed.
