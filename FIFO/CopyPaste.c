#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <sourcefile> <destinationfile>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *sourcefile = argv[1];
    const char *destinationfile = argv[2];

    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { 
        close(pipefd[1]); 
        int dest_fd = open(destinationfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
        if (dest_fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        char buffer[BUFFER_SIZE];
        ssize_t bytes_read;

        while ((bytes_read = read(pipefd[0], buffer, BUFFER_SIZE)) > 0) {
            if (write(dest_fd, buffer, bytes_read) == -1) {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }

        if (bytes_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        close(dest_fd);
        close(pipefd[0]);

        exit(EXIT_SUCCESS);
    } else { 
        close(pipefd[0]); 

        
        int source_fd = open(sourcefile, O_RDONLY);
        if (source_fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        char buffer[BUFFER_SIZE];
        ssize_t bytes_read;

        
        while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
            if (write(pipefd[1], buffer, bytes_read) == -1) {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }

        if (bytes_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        close(source_fd);
        close(pipefd[1]);

        wait(NULL);

        exit(EXIT_SUCCESS);
    }
}