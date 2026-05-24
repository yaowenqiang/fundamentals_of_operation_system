#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char source_ip[16];
    char destination_ip[16];
    int source_port;
    int  destination_port;
    int packet_length;
} Packet;

int main() {
    Packet *packets = (Packet *)malloc(100000 * sizeof(Packet));

    // second packet address
    Packet *p2 = (packets + 1);

    // use the packets here
    // free the allocated memory
    free(packets);

    return 0;
}
