#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define LOG_FILE "/var/log/syscall_logs.txt"

int main() {
    FILE *log = fopen(LOG_FILE, "a");
    if (!log) {
        perror("Error opening log file");
        return 1;
    }

    fprintf(log, "System call accessed by user ID: %d\n", getuid());
    fclose(log);

    return 0;
}
