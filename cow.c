#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main() {
    size_t tenMB = 10 * 1024 * 1024;
    char *buffer = (char *) malloc(tenMB);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    memset(buffer, 0, tenMB);

    pid_t pid = fork();
    int i = 0;

    if (pid == -1) {
        perror("Failed to fork");
        free(buffer);
        return 1;
    } else if (pid > 0) {
        while (1) {
            printf("Parent process: PID = %d, buffer[0] = %d\n", getpid(), buffer[0]);
            buffer[0]++;
            sleep(1);
        }
        free(buffer);
    } else {
        int Y = 20;
        while (1) {
            printf("Child process: PID = %d,Y = %d, bubber[0] = %d\n", getpid(), Y, buffer[0]);
            buffer[(i++)*1000]++;
            sleep(1);
        }
    }

    return 0;
}

