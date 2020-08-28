# Problems with Tree-Walk Interpreter

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

- Bytecode is similar to machine code. It is a dense linear sequence of binary sequence.This keeps the overhead low and plays nice with cache.However, it is simpler than other high-level instruction set of real chip. In most bytecode formats, each instruction is only one byte long.Hence, it is called bytecode.
- To execute these instructions, we need to simulate a chip, which is essentially an emulator. It is a virtual machine which interprets bytecode on instruction at a time.
- This emulation can add a little overhead, hence, it is slower than native code, but is much faster than, a tree walk interpreter.But in return we can preserve portability.
- In our bytecode format, each instruction has a one-byte operation code (universally shortened to “opcode”). That number controls what kind of instruction we’re dealing with—add, subtract, look up variable, etc.

## Advantages for using dynamic arrays to store information:

- Cache-friendly, dense storage
- Constant-time indexed element lookup
- Constant-time appending to the end of the array

### Dynamic arrays:

- We keep two numbers: T
  - The number of elements in the array we have allocated (“capacity”).
  - How many of those allocated entries are actually in use (“count”).
  - If the count is less than the capacity, then there is already available space in the array. We store the new element right in there and bump the count.
  - If the current array already has capacity for the new byte. If it doesn’t, then we first need to grow the array to make room.

### Custom reallocate( ) function

- A wrapper around C standard library's **realloc()** function.
- This reallocate() function is the single function we’ll use for all dynamic memory management in clox—allocating memory, freeing it, and changing the size of an existing allocation. Routing all of those operations through a single function will be important later when we add a garbage collector that needs to keep track of how much memory is in use.
- The two size arguments passed to reallocate() control which operation to perform:
  | oldSize | newSize | Operation |
  |----------|----------------------|----------------------------|
  | 0 | Non‑zero | Allocate new block. |
  | Non‑zero | 0 | Free allocation |
  | Non‑zero | Smaller than oldSize | Shrink existing allocation |
  | Non‑zero | Larger than oldSize | Grow existing allocation. |
- The interesting cases are when both oldSize and newSize are not zero. Those tell realloc() to resize the previously-allocated block. If the new size is smaller than the existing block of memory, it simply updates the size of the block and returns the same pointer you gave it. If the new size is larger, it attempts to grow the existing block of memory.

It can only do that if the memory after that block isn’t already in use. If there isn’t room to grow the block, realloc() instead allocates a new block of memory of the desired size, copies over the old bytes, frees the old block, and then returns a pointer to the new block. Remember, that’s exactly the behavior we want for our dynamic array.

Because computers are finite lumps of matter and not the perfect mathematical abstractions computer science theory would have us believe, allocation can fail if there isn’t enough memory and realloc() will return NULL.

#### Disassembler
A disassembler takes a blob of machine code, it spits out a textual listing of the instructions.s