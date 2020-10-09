- In order to choose a value representation we need to answer two key questions:

  - How do we represent the type of a value?
  - How do we store the value itself(i.e. How do we represent 3 from 4)?

- A classic solution to solve the above problem is a **Tagged Union**. A value contains two parts:

  - A type "tag" (An enum stores all kinds of values the VM supports)
  - Payload for actual value

- The size of union is the size of the largest field. Since, all the fields reuse the same bits we have to be very careful while working with them. If we store data using one field and access it using another, we will essentially reinterpret what the bits mean.

- In the internal representation of Tagged Union, value types come first. Then there is the union. But, between those two parts the compiler may add padding since most architectures prefer values to be aligned to their size.Size the union field contains eight byte double the compiler adds 4 bytes padding after value type.
