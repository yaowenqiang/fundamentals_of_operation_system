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

