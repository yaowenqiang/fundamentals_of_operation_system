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
    Packet *packets[1000000];
    for (int i = 0; i < 1000000; i++) {
        packets[i] = (Packet *)malloc(sizeof(Packet));
        // you can initialize the packet fields here, if needed
    }

    // use the packets here
    // free the allocated memory
    for (int i = 0; i < 1000000; i++) {
        free(packets[i]);
    }

    return 0;
}
