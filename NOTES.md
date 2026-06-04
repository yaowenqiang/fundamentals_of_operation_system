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
