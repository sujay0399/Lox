# Problems with Tree-Walk interpreter
- Tree walk interpreters are very slow, especially for high level programming languages.
- Tree walk interpreters written in a high level programming language are very inefficinet in terms of memory.A simple expression like 1 + 2 will be turned into a objects, to represent a node in a parser. Hence, each node will add a memory overhead(32 or 64 bits) to represent a simpleobject.
- The objects(nodes) are sprinkled all over heap in a loosely connected web of objects and does bad things for spatial locality.
- Modern CPU's can process data way faster than they can pull it from RAM. To compensate for this overhead chips have multiple layers of caching.
- The machine automatically puts in data in cache. When the CPU reads data from the RAM, it pulls in a little bundle of adjacent of bits and stuffs them into cache.
- If a piece of memory it needs is already memory, it can be loaded more quickly. 
- This cannot be done in jlox, because of garbage collector and automatic memory management of JVM. The objects of the nodes can be anywhere in the memory, and the reference to the child node can be outside the bounds of cache. This causes the CPU to stall, until new data can grabbed from RAM.
- Just the overhead around each tree node with all their pointer fields and object headers(For ex, for each object java adds addational headers which the java uses for memory management and tracking object types) will push objects away from each other and out of the cache.
- There is also overhead from interface dispatch and the visitor pattern.

# Why not compile to native code?
- It is not easy to compile to native code. Modern name computer chips have complicated architecture and large instructions sets to support backward compatibility. They require sophisticated register allocation, pipelining and instruction scheduling.
- Also, this also rises the problem of portability. To write for each architecture you master their instruction sets.(LLVM may actually help with this).

# What is bytecode?
- Bytecode is similar to machine code.It is a dense linear sequence of binary sequence.This keeps the overhead low and plays nice with cache.However, it is simpler than other high-level instruction set of real chip.In most bytecode formats, each instruction is only one byte long.Hence, it is called bytecode.
- To execute these instructions, we need to simulate a chip, which is essentially an emulator. It is a virtual machine which interprets bytecode on instruction at a time.
- This emulation can add a little overhead, hence, it is slower than native code, but is much faster than, a tree walk interpreter.But in return we can preserve portability.
 
