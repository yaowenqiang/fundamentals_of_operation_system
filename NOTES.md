> Mysql InnoDB I/O Capacity

> https://blog.codingconfessions.com/p/a-war-story-involving-a-python-a

> https://blog.codingconfessions.com/t/cpython-internals


CPU 

+ Central Processing Unit
+ Consists of cores
+ Each core has a clock speed
+ Executes machine level instructions
+ Fast Caches

Memory

+ Random Access Memory
+ Fast but Volatile
+ Store Process states and data
+ Limited
+ Slower than CPU cache



LBA(Logical Block Addressing)

File System

zfs
btrfs
ext4
fat32
ntfs
tmpfs(inmemroy)

Partitions

+ Disks are exposed as big array of LBAS(logical section)
+ partitions start from LBA and end en an LBA
+ Provides logical segmentation
+ E.g. Partition 1 is LBA 1 - LBA.4
+ Each partition can have its own FS
+ Each FS different Block size(cluster)

Executable File Formats


> https://www.linkedin.com/posts/hnaser_recently-learned-that-compiled-executable-activity-7125897574854610944-5S05


The anatomy(剖析) of the process

> linkerd

java -> rust

Program

+ Code is compiled and linked for a CPU
+ Produces executable file program
+ Only works on that CPU architecture
+ At rest it follows an executable file format
+ Lives on disk

Process

+ When a program is run,we get a process
+ Process lives in Memory
+ Uniquely identified with an id
+ Instruction pointer/Program counter
+ Process Control Block(PCB)






mold A Modern Linker

> https://github.com/rui314/mold

> clang -S -O0 demo.c
> b main 然后 run
> (lldb) disassemble
> disassemble -b -m

> gcc -S test.c -o test.s
> gcc -g -S test.c -o test.s # enable debug

> gdb test
> gdb> info registers
> gdb> pc # program counter

Cost time

+ Register access 1ns
+ L1 Cache - 1ns
+ L2 Cache - 2ns
+ L3 Cache - 7ns
+ L4 Cache - 15ns
+ Main Memory - 100ns
+ SSD - 150us
+ HDD - 10ms

Stack 

+ Stack is a brilliant data structure
+ Function has local variables
+ Each function gets a frame
+ Grows from high to low
+ Stack space is limited

Stack Pointer

+ Move using pointers
+ Stack Pointer(CPU Register)
+ Allocate,deallocate memory
+ Points at the end

Base Pointer

+ Stack pointer changes
+ Need a fixec reference
+ Base Pointer(frame pointer)
  + Also a CPU register
+ To reference variable a, use bp
+ Varible b is bp -4

Nested Calls

+ Main calls func1
+ Main pauses, func1 executes
+ Base and stack pointer change

Function returns

+ Set sp back
+ Deallocate , sp = sp + 12
+ Main is now active
+ But where in main should we go?

Return Address

+ Main has still work to do 
+ It called func1 but lost it's place
+ Need to store return address
+ Which becomes the pc
+ Stored in link register in CPU

Summary

+ Stack grous from high to low
+ Used for function calls
+ Stack variables die quickly.(Watch out for pointers)
+ Works with CPU registers, bp(base pointer), sp(stack pointer), lr(link pointer), pc(program counter)




Stack overflow

+ Protect against infinite function calls
  + Recursion
  + Large local variables
+ Stack has a limit
+ Limit can be overridden by compiler

Data Section

+ Stores static and global variables
+ Refreenced directly by memory address
+ Read only and read write 
+ All functions can access
+ Fixed size, like code setion

> erlang hot swap

Heap section

+ Store large data
+ Remain until explicitly removed
+ A llfunctions can access
+ Dynamic, grows low to high
+ malloc, free ,new

Pointers

+ Point to a memory address in th heap
+ A pointer can in stack, data or heap
+ Stores the address of first byte
+ Pointer type helps determine size



Memory leaks

+ Free the heap memory is important
+ We get memory leak in the heap
+ Losing a pointer in the stack when function returns
+ Refcounting, Garbage collection

Dangling pointers(double free)

+ Memory freed but active pointers exist
+ Leads to errors segfault
+ fun2 frees *b 0x333333 and returns
+ func1 tries to use *a but fails

Performance

+ Stack has built in memory menagement
+ Stack variables are close together
+ Stack space Limited
+ Heap is random
+ Cache locality in Stack


> CPU cache line

> https://www.youtube.com/watch?v=qo1FFNUVB-Q
> Google Patches Linux kernel with 40% TCP performance
> https://www.phoronix.com/news/Linux-6.8-Networking


Escape analysis

+ allocates in the stack when possible
+ Go ,Java

Program Break

+ Where the process ends
+ Points to the top of the heap
+ Using brk, sbrk to allocate/deallocate

Summary

+ Stores large data
+ Remain until explicitly removed

> https://www.youtube.com/watch?v=UH7wkvcf0ys
> Facebook and memcached - Tech Talk

> https://www.calculator.net/



Memory Management

Memory

+ Store data
+ Volatile
  + RAM - Random access memory
+ No-Volatile
  + ROM - Read Only Memory

Static RAM

+ SRAM
+ Complex, expensive but fast
  + 1 bit -> 1 flip flop -> 6 transistors
+ Flip-flops, constant power
+ Used in CPU caches, SSDs
+ Access is always fast

Dynamic RAM

+ DRAM
+ Abundant, cheapter, but slower
  + 1 bit -> 1 capacitor, 1 transistor
+ Capacitors, lose their state
+ Need to be refreshed
+ Access is slow

> sense amplifier


Asynchronous DRAM

+ Asynchronous is slow(missed cycles)
+ Wasted clock signals
+ Cycle wasted on refresh





Sasynchronous DRAM

+ SDRAM

Double Data Rate

+ DDR SDRAM
+ Two transfers per cycle
+ Up and down

DDR4 SDRAM

+ 64 data lines, 64 pins
+ DDR4 Prefetch buffer = 8 bit per io pin
+ CPU often needs 64 bytes min
+ Called a burst

DDR5 SDRAM

+ Two channels, 32 pins each
+ DDR5 Prefetch buffer = 16 bit per pin

DRAM Internals

+ DIMM
+ Bank
+ Rows
+ Cells(1 cell 1 bit)

> https://arxiv.org/abs/2004.02354
> https://github.com/dramdig/DRAMDig


Open a row

+ Bank has many rows(e.g. 32K)
+ A row has many columns(e.g. ~1024)
+ A column has many cells(e.g. ,16,32 bits)
+ Each cell is a capacitor storing 1 bit(0, or 1)
+ Can only have one opened row in a bank
+ Slow
+ Many banks help


Read/Write from memory

> MMU

Note about Allignment

+ Data types are aligned
+ 1,4, or 8 bytes
+ Certain sizes are placed in specific addresses
+ E.e. 4 bytes place in addressed divisible by 4

> objdump -t a.out
> otool -L a.out
> readelf -d ./a.out 
