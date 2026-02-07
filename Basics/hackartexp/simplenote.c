#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     // open, write, close
#include <fcntl.h>      // O_WRONLY, O_CREAT, O_APPEND
#include <sys/stat.h>

void usage(char *prog_name, char *filename) {
    printf("Usage: %s <data to add to %s>\n", prog_name, filename);
    exit(0);
}

void *ec_malloc(unsigned int size);

int main(int argc, char *argv[]) {
    int fd;
    char *buffer, *datafile;

    buffer = (char *)ec_malloc(100);
    datafile = (char *)ec_malloc(20);

    strcpy(datafile, "/tmp/notes");

    if (argc < 2)
        usage(argv[0], datafile);

    strncpy(buffer, argv[1], 99);
    buffer[99] = '\0';   // safety

    printf("[DEBUG] buffer @ %p: '%s'\n", buffer, buffer);

    strncat(buffer, "\n", 1);

    fd = open(datafile, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    if (write(fd, buffer, strlen(buffer)) == -1) {
        perror("write");
        close(fd);
        exit(1);
    }

    if (close(fd) == -1) {
        perror("close");
        exit(1);
    }

    printf("Note has been saved.\n");

    free(buffer);
    free(datafile);

    return 0;
}

void *ec_malloc(unsigned int size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        perror("malloc");
        exit(1);
    }
    return ptr;
}

