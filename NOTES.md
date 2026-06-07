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

Virtual Memory


Limitations of Physical memory

+ Fragmentation
+ Shared Memory
+ Isolation
+ Large Programs

Fragmentation

+ One space
+ Memory must be contiguous

External vs Internal Fragmentation

+ Memory allocation happens in blocks
+ External fragmentation
+ Internal fragmentation


Internal fragmentation

+ Fixed-allocated blocks
+ Internal space is wasted
+ OS doesn't know the space is unused
+ Happens with fixed-size blocks,especially large size

Virtual memory and fragmentation

+ Let us use fixed block size call it paging
+ Each process has virtual address space
+ We map logical page to physical page
+ Mapping stored in process page table
+ Page size is often 4kb
+ Many to 1

 Page Tables

+ Another layer requires translation
+ Map virtual address to physical
+ Page table has its Mapping
+ Each process has its own page table
+ Page table is stored in memory

> translation lookaside buffer

Shared Memory

+ Sharing memory is a challenage
+ Spin 5 processes of the same program
+ All Processes have same code
+ Losts of duplicated memory

Share memory and Virtual Memory

+ With virtual memory, we load th code once and we map all virtual pages to the same physical address!

Shared Libraries

+ Most processes use Libraries
+ OS loads the library code once
+ Map the virtual page to the library physical code
+ Libc
+ /proc/[iid]/maps

Use cases for shared memory

+ Multi-processes/multi-threading
+ Databases shared buffers
+ NGINX/PROXIES
+ forking
+ CoW - copy on write

> each thread has its own stack when multi-threading


Isolation

+ Physical memory addresses tells process where it is
+ Process can attempte to load an address they aren't supposed to
+ Virtual memory solves this
+ Each process has full virtual address
+ Most of it isn't mapped

Isolation with Virtual Memory

+ Process A address 1000 is different from Process B's 1000
+ They point to different physical address
+ Process has no way to reference specific physical addresses directly

Not enough memory

+ Physical memory has a limit
+ If i load too many processes, we ran out of memory
+ So we fail to spin up new processes
+ But virtual memory helps

Limitation of Virtual Memory

+ Additional layer of translation(CPU can't read virtual addresses)
+ More maintenance(page tables)
+ Page faults(Kernel mode switch)
+ More complex CPU architecture(MMU/TLB)
+ TLB cache misses(MySQL 8.x vs 5.x)


DMA(Direct Memory Access)

Peripherals  Read

+ Data from network/disk must pass through CPU
+ Keyboard -> CPU -> RAM
+ Network -> CPU -> RAM
+ Slow at times with large transfers


> interrupt service routine

DMA

+ Allow direct access from network/disk to RAM
+ DMA controller initializeds the operation
+ Start the direct transfer

Note about DMA

+ Must be Physical addresses
+ DMA doesn't often have MMU
+ Knows nothing of the virtual memory
+ kernel allocated memory must not be swapped
+ IOMMU(allows IO)

O_DIRECT

+ Very important option in file systems and Databases
+ Allows bypassing the file system cache
+ Direct from disk to user-space(database)
+ Uses DMA

Pros and Cons

+ Efficient transfers
+ No VM Management
+ Less CPU overhead
+ But security concerns and complexity
+ Initialization Cost
+ Can't be used for interrupts(Keyboard/mouse), CPU is faster


> DMA Attack
> SAP hana


Inside the CPU

> ALU

CPU Components


+ ALU(Arthmetic logic unit)
+ CU(Control Unit)
+ MMU(Memory management Unit)
+ Registers
+ Caches(L1, L2, L3)
+ Bus 

> DSM(Distributed Shared memory)

> Non-uniform memory access

ALU

+ Arithmetic Logic Unit
+ Arithmetic +-*/
+ Logic XOR/OR/AND
+ Core of compute

CU

+ Control Unit
+ Fetches Instructions
+ Decodes Instructions
+ Executes Instructions

Registers

+ Small ultrafast unit of storeage
  + 32 or 64 bit
+ In the CPU core
+ Many registers types
+ PC, IR, SP, BP
+ General purpose

MMU

+ Memory management Unit
+ Responsible for memory access
+ translating virtual to physical address
  + TLP translation Lookaside buffer
  + TLB must* be flushed on context switch


> memchr

> zns

> zoned Namespaces SSDs disrupting the storage industry


L caches

+ L1,L2,L3
+ L1 local to core
  + 1 ns, ~128kb
+ L2 local to core
  + 5 ns, ~256~2MB
+ L3 shared between all cores
  + 15 ns, ~64 MB
+ Main Memory
  + 50-100 ns
+ Memory reads are cached at all levels
+ L1 cache is two types
  + L!D(Data) and L1I(instructions)
  + CU can fetch data and instructions at same time
+ L2, L3 unified
+ Cache invalidation challenges
+ Some CPUs only have L1, and L2(shared)


> 查看 L1 数据缓存大小
> sysctl hw.l1dcachesize

> 查看 L1 指令缓存大小

> sysctl hw.l1icachesize

> 查看 L2 缓存大小：

> sysctl hw.l2cachesize

> sysctl -n machdep.cpu.brand_string

> system_profiler SPHardwareDataType
 

> lscpu | grep -i "cache" # on linux 

> download intel processor identification utility on windows


Show L caches

> sysctl -a | grep cachesize

Show number of cores

> sysctl -n hw.physicalcpu

Show CPU architecture

> uname -m



CPU architecture

+ RISC - Reduced Instruction Set
  + Simple instructions - each single task - singel cycle
  + Low power, predictable
  + Use registers
  + Arm
+ CISC - Complex Instruction Set
  + One instruction, lots of tasks, multiple cycle
  + More power, unpredictable
  + x86(Intel/AMD)

CISC vs RISC - Example

+ Example a = a + b, where b and a are integers
+ CISC - 1 instruction
  + ADD a,b (a and b haere are addresses)
  + Takes two memory locations
  + Reads, adds then store in a 
+ RISC - 4 instructions
  + ldr r0,a
  + ldr 41, b
  + add r0,r1
  + str a1, r0

Clock Speed

+ How many cycles per second
+ e.g. 3GHz = 3 billion clock cycles per second
+ In RISC could mean 3 billion instructions per second
+ Less then CISC
+ Remember cost of fetching/decoding(pipelining helps)


Instruction Life Cycle

Fetch, Decode, Execute, Read, Write

Instruction

+ Fetch from memory(MMU)
+ Decode(CU)
+ Execute(ALU)
+ Memory read(optional)
+ Write(to register/memory)

Registers

Basic General purpose registers

32-bits

+ EAX
+ EBX
+ ECX
+ EDX


EAX is a dword which is 4 bytes(32 bits)
AX is a word which is 2 bytes(16 bits)
AH is a byte(8 bits)
AL is also a byte(8 bits)

If EAX = 0x12345678

AX = 5678
AH = 56
AL = 78


64 bits

+ RAX
+ RBX
+ RCX
+ RDX

RAX is qword which is 8 bytes(64 bits)
EAX is a dword which is 4 bytes(32 bits)
AX is a word which is 2 bytes(16 bits)
AH is a byte (8 bits)
AL is also a byte (8 bits)


+ String Index registers
  + ESI - Source Index
  + EDI - Destination Index
+ Instruction pointers
  + EIP - indicates the memory current address of current instruction
+ Stack Frame Pointers
  + ESP - address of top of stack
  + EBP - address of bottom of stack

MOV Instructions

syntax

+ MOV(mnemonic 记忆的，助记的) Destination, Source
+ Copies data from Source to Destination
+ Example:
  + mov eax, 0x3A
  + mov al, 0x8
  + mov ebx, eax
  + mov cx, bx
  + mov ah, cl


Basic Arithmetic


+ Add Destination, source 
+ Destination <- Destination + source
+ add eax, ecx
+ add edi, 0x2a
+ add cs, si  - partical register

Dword registers

+ mov esi, 0x1
+ mov eax, 0x2
+ mov ebx, 0x3
+ add eax, ebx
+ add eax, eax
+ mov esi, 0xffffff 
+ add ebx, esi # 3 + ffffffff = 100000002 ,1 will be dropped
+ add esi, eax # 1 0000 0009 1 will be truncated

> wrap-around 

Partial Registers

+ mov edi, 0xab29ffff
+ mov ecx, 0x00000703
+ mov eax, 0x000000ff
+ add al, ch # 07 + ff = 106 = 06 in al,1 will be dropped
+ add di, cx # 0703 + ffff = 10702 = 0702 
+ mov edi, 0xAB29ffff
+ add edi, ecx # 0x00000703 + 0xAB29ffff = 0xab2a0702

Basic Arithmetric SUB instruction

+ Sub  Destination, sourceo
+ Destination <- Destination - source
+ sub eax, edx
+ sub edi, 0x2a
+ sub cl, dl


+ mov eax, 0x1a
+ mov ebx, 0x3
+ mov ecx, 0x2
+ sub eax, ebx 
+ add eax, ebx
+ sub ecx, ebx # ffffffff
+ add ecx, eax
+ sub cl,al

INC and DEC instruction

+ INC register
+ register <- register - 1
+ inc eax
+ eax <- eax + 1

+ DEC register
+ register <- register - 1
+ dec si
+ si <- si - 1


+ mov eax, 0xfffffffe
+ inc eax
+ inc al
+ dec al
+ inc ax
+ dec ax
+ inc eax
+ inc eax

MUL(multiply) instructions

+ mul register
+ ax <- al . register
+ dx:ax <- ax. register
+ edx:eax <- eax . register

> edx:eax means that edx and eax are concatenated together
+ Note that the size of the result is twice the size of the argument

+ mul ecx
  + edx:eax <- eax * ecx
+ mul si
  + dx:ax <- ax * si
+ mul al
  + ax <- al * al
+ mul 0x6b <- invalid


```
mov edx, 0xAB1e2fff
mov eax, 0x3
mov ecx, 0x2
mul ecx #( eax * ecx ) = 6 = edx:eax  = 00000000 00000006
mul ecx #( eax * ecx ) = 12 = 00000000 0000000c
mov ax, 0xeeee 
mul ax # eeee * eeee - deff6544 = dx:ax
mul cl # cl * cl = ax = 00000088 
```

DIv (divide) Instructions

(byte reg)

+ DIV register
+ al <- ax / register
+ ah <- ax % register


Word reg

+ ax <- dx:ax / register
+ dx <- dx:ax % register

dWord reg

eax <- edx:eax / register
edx <- edx:eax % register

div ch

al <- ax / ch (quotient)商
ah <- ax / ch (remainder)

div esi

eax <- edx: eax / esi(quotient)
edx <- edx:eax % esi (remainder)

div di

ax <- dx:ax / di(qoutient) 商
dx <- dx:ax % di(remainder)

div 0x8c Invalid


Exceptions

division by 0

eg mov eax, 0x3
   mov edx, 0x0
   mov ecx, 0x0
   div ECX

qoutient overflow - if qoutient is too large

eg mov eax, 0x00005678
   mov edx, 0xffffffff edx:eax is qword ( 8 bytes), very big number   
   mov ecx, 0x2
   div ecx


```
mov ecx, 0x2
mov edx, 0x0
mov eax, 0x8
div ecx # ecx/edx:eax rax (qoutient) + edx(remainder)
inc ecx
div ecx

```

```
mov ebx, 0x3a
mov edx, 0x20
mov eax, 0x0
div ebx # edx:eax / ebx = 8d30 cb0b  eax=8d30cb0b edx=00000030
div bx # dx:ax / bx = ax(qoutient) dx(remainder)
mov bl,0xfe
div bl = ax / bl = al(qoutient) + ah(remainder)


```

How to write to write to memory and from memory(date segment)

mov eax, 0x2

mov dword ptr ds:[0xmemory address], eax # move the value of eax into the memory address

mov ebx, dword ptr ds:[0xmemory address] # read from memory


> ds means data segment

inc eax
mov dword ptr ds:[0xmemory address], eax

> little endian 


mov eax, 0x11223344
mov dword ptr ds:[0xmemory address], eax # 44332211
mov ebx, dword ptr ds:[0xmemory address] 
inc eax # 11223345
mov dword ptr ds:[0xmemory address], eax # 54332211


Moving data to memory and patchin memory

mov dword ptr ds:[0xmemory address], 0x2

patch memory

二进制 -> 编辑 

Stack

PUSH value 

esp <- esp -4

dword [esp] -< value


POP register

register <- dword[esp]
esp <- esp + 4



```
mov eax, 0x35a626
mov ebx, 0x100404
mov ecx, 0x000047
push eax
push ebx
push ecx
```



```
mov eax, 0x35a626
mov ebx, 0x100404
mov ecx, 0x000047
push eax
push ebx
push ecx
inc eax
inc ebx
inc ecx
pop ecx
pop ebx
pop eax
```
> (last in first out)

Pushing constants and strings to the stack

> https://www.asciitable.com/

```
push 0x1234567

# null terminator 00

first select the memory address and edit the content of the memory then
push 0x1234567 # the string address

```

Intro to Function Calls

> https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm


x86 calling convention(1 parameter)

c 

function(parameter 1);

Assembly:

push parameter1
call function


```
call 0x11111111 # the addres of print function

```

Calling with 2 parameters

C

function(parameter1,parameter2)

Assembly

push parameter2
push parameter1
call function

printf("hello, %s", string);

push string
push "hello, %s"
call printf


```
1337 (10) -> 539 (16) -> 37 05 (in memory) -> 537 (in stack)

```

x86 calling convertion(3 parameters)

C

function (parameter1, parameter2, parameter3);

Assembly

push parameter3
push parameter2
push parameter1
call function

Getting input using sanf() function

scanf() for input of numbers

int number:

scaf("%d", number);

"%d" = format specifiter

%&number = address-of number variable


scanf() for input of strings

char str[32];
scanf("%s", %str);


"%s" = format specifiter

str = address-of str

Code caves

What is a code cave?

+ blank memory area in the .TEXT segment
+ .TEXT segment is Executable region
+ Therefore any code injected here will execute

> HxD 
> PE-bear

> virtual memory > raw ( file memory)

> 0000 = null bytes 



jmp 0xcodecaveaddress

code cave example


```
push 0xaddressofstring
call addressofprintfunction

```

```
printf(" Enter firstname:");
scanf("%s\n", firstname);
printf(" Enter lastname:");
scanf("%s\n", lastname);
printf("Hello, %s, %s", firstname, lastname)

```

> 0A is new line hex code

intro to functions that returns a value


function return values normals stored at EAX register

```
push "hello world"
call strlen
```


Flags Registers

CF = Carry Flag(进位/借位标志)
ZF = Zero Flag(溢出标志)
SF = Sign Flag（符号标志)
OF = Overflow Flag(零标志)


Each flag can only be either 1 or 0


ZF(The Zero Flag)

+ ZF is set to 1 when the last calculation results is zero
+ ZF is clared to 0 when the last calculation results is non-zero
+ For example:
  + mov eax, 0x8
  + mov ecx, 0x8
  + sub eax, ecx
+ After the sub instruction, ZF is set to 0
+ Another example:
  + mov eax,0x6
  + mov ecx,0x6
  + add eax,ecx
+ After the add instruction, ZF will be cleared to 0

SF(The Sign Flag)

+ SF equals the most significant bit of the last calculation
+ Use in Two's Complement Number Representation
  + SF = 0 mean positive
  + SF = 1 means negative
+ For example:
  + move edx, 0
  + dec eds
+ SF = 1, because edx = 0xffffffff = 1111....1111
+ Anothe example:
  + mov edx, 0
  + inc edx
+ SF = 0 because edx =0x00000001 = 0000...0001

CF(The Carry Flag)

+ CF=1, if the addition of two numbers causes a carry out of the most significant bit, A wrap-around has occurred.
+ Example:
  + mov eax, 0xffffffff
  + add eax, 0x1
+ eax = 0
+ CF = 1
+ Means the result you get from the addition is wrong
+ The CF will also be set to 1 if a substraction requires a borrow from the most significant bit, a wrap-around also occurs.    
+ Example:
  + mov ecx, 0x0
  + mov edx, 0x3
  + sub ecx, edx
+ ecx=0xfffffffD
+ CF = 1
+ The CF will be cleared to 0 if no Carry occurs, No wrap-arounds
+ Example:
  + mov eax, 0x2
  + mov ecx, 0x8
  + add eax, ecx
+ eax=0xa
+ CF = 0

OF(The Overflow Flag)

+ if we assume the number are two complements representation (signed numbers), then
+ The OF is set to 1 if:
  + the addition of two positive numbers -> negative result
  + The addition of two negative numbers -> positive result
  + positive - negative -> negative result
  + negative - positive -> positive result
+ If the OF = 1, it means the result you get from the calculation is wrong
+ Another example:
+ mov eax, 0x7fffffff 0111 1111 1111 1111 1111 1111 1111 1111
+ mov edx, 0x1        0000 0000 0000 0000 0000 0000 0000 0001
+ add eax, edx        1000 0000 0000 0000 0000 0000 0000 0000
+ eax = 0x80000000
+ OF = 1

+ Another example:
+ mov eax, 0x7fffffff 0111 1111 1111 1111 1111 1111 1111 1111
+ mov edx, 0x1        0000 0000 0000 0000 0000 0000 0000 0001
+ sub eax, edx        0111 1111 1111 1111 1111 1111 1111 1110
+ eax = 0x7ffffffe
+ OF = 0

 When to look at CF or OF

+ Both CF (Carry Flag) and OF(Overflow Flag) will change in every arithmetic operation
+ Depending on how the numbers are being interpreted, you will then look either at the CF flag or the OF flag
+ If you program is using unsigned numbers, then you will be concerned with the CF flag
+ But if your program works with signed numbers, then you will care about the OF flag

In summary

+ The ZF flag set to 1 if the last result was zero
+ The SF flag is set to 1 if the last result was negative
+ The CF flag is set to 1 if the result (assuming you interpret the numbers as unsignedA is wrong)
+ The OF flag is set to 1 if the result (assuming you interpret the numbers as signed) is wrong




## Pipelining and Parallelism - Making CPU efficient

CPU mostly idle

+ Notice how parts of the CPU are mostly idle
+ Pipeling helps
+ While decoding, we can fetch another instruction
+ While ALU executing, we can decode another instruction

## Parallelism


+ App can spin multiple processes/threads
+ Each go into it in a CPU core


## Hyper threading

+ Sharing cores
+ Hyper threading exposes a single core as multiple logical cores
+ Dedicated registers(e.g pc) shared CPU/ALU、L Cache

SIMD

+ Single Instruction Multiple data
+ With a single instruction add multiple values
+ Vectors
+ Instead of executing 4 instructions
  + 1 in struction on 4
+ Gaming/DB Btrees
+ E.G. ARM Neon

Traditional

Add a1, b1
Add a2, b2
Add a3, b3
Add a4, b4

SIMD

add [a1, a2,s3, a4] ， [b1,b2, b3, b4]


### Enabling auto-vectorization in GCC compiler

To enable automatic vectorization in GCC, use the command line options:

> -ftree-vectorize
> -mfcpu=neon
> -mcpu to specify the core or architecture

Compiling at optimization level -o3 implies -ftree-vectorize 

If you do not specify an -mcpu option, then GCC will use its built-in default one, The resulting code might run slowly or not run at all.The option -ftree-vectorize is available for many architecture that support SIMD operations

### PSI - Perssure Stall Information

> postgres# insert into test select * from generate_series(10000000000);

PI, EMMC


## Process vs Thread

Process

+ An instance of a program
+ Has Dedicated code, stack, heap, data section
+ Has context in the CPU(pc, lr, etc.)
+ Process Control Block

Process Control Block(PCB)

+ Kernel needs metadata about the process
+ PCP contains
  + PID, Process state, Program counter, registers
  + Process control info(running/stopped, priority)
  + Page Table(Virtual memory to pyhsical mapping)
  + Accounting(CPU/Memory usage)
  + Memory management info(Pointer to code/stack, etc)
  + IO info(File desceriptors)
  + IPC info, semaphores, mutexes, shared memory,messages,

Kernel Process Table

+ Kernel needs to menage processes
+ A mapping table from PID to PCB
+ Process Table
+ Quick lookup
+ In kernel space

Thread

+ A thread is a light weight process
+ Shared code/heap,data and PCB
+ stack is different and PC
+ Thread Stack lives in same VM

> Why Threads are a bad idea(for most purposes)

> https://web.stanford.edu/~ouster/cgi-bin/papers/threads.pdf

Thread Control Block(TCP)

+ Kernel needs metadata about the thread
+ TCP contains:
  + TID, Thread state, Program counter, registers
  + Process Control info(running/stopped, priority)
  + Accounting(CPU/memory usage)
  + Memory management info(Pointer to stack, etc.)
  + Pointer to parent PCB

Kernel Thread Table

+ Kernel needs to manage threads
+ A mapping table from TID to TCB
+ Thread Table
+ Quick lookup
+ In kernel space

Shared Memory

+ Multiple processes/threads can share memory
+ mmap
+ Virtual memory different, physical memory same
+ Shared Buffers in databases

Postgres Processes


+ Postgres uses processes
+ Should Postgres move to threads?
+ Long running discussions


Fork

+ Fork creates a new process
+ Child must have new virtual memory
+ But OS use COW so pages can be shared unless a write happens
+ Redis Asynchronous durability

> Shared memory is another exception. If the parent mmap with shared memory, the fork will not do a CoW but share the same memory instead


Python CoW Bug

+ Python bug None,True, False
+ Refcounting was constantly updated
+ Forks were triggering CoW


## Context Switching - A critical OS function

CPU Process

+ CPU doesn't really know what a process is
+ OS loads data into CPU registers.(pc,sp, bp, etc.)
+ Pointer to Page Table mapping(pbr)
+ Called "Context"
+ Executes instructions

Context Switching

+ To switch "context" we save current context and load new context
+ "Save" the current registers to current process PCB(Memory write)
+ "Load" the new process PCB to CPU registers(Memory load)
+ pc, bp, sp, lr, ptbr and more

TLB flush

+ TLB stores virtual memory mapping cache
+ Processes CANNOT share VM mapping
+ Slow
+ Threads of same process are faster to switch
  + Same memory, paging
  + As long as threads of the same process 

TLB(Translation Lookaside Buffer，转换后备缓冲器) ASID(地址空间标识符)

+ Address space id
+ Identify the process in the TLB
+ 255 values
+ Avoid TLB flushing on context switch 
+ ARM/Intel

When does context switch happens

+ Scheduling algorithms
+ Preemptive multitasking
+ IO wait

Preemptive multitasking(抢占式多任务处理)

+ Some processes run for a long time
+ OS must switch those out
+ Time slice
+ Windows 3.1 bug where other processes starve

Scheduling algorithms

+ What processes/threads get what CPU core for how long
+ Many papers have been written on this topic
+ Complex and hard to find a faire algorithm
+ You want to schedule threads of same process on the same core
+ First come first serve
+ Shortest Job First
+ Round Robin

Summary

+ Context is an OS concept
+ CPU execute instructions only
+ Context is saved or loaded(thus switched)
+ Threads are more efficient in context switch


