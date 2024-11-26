#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        // If fork() returns a negative value, it means creation of child process was unsuccessful
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child Process: PID = %d\n", getpid());

        // 1. Same Program, Same Code
        printf("Child: Executing same code as parent.\n");

        // 2. Same Program, Different Code using exec()
        execlp("/bin/echo", "echo", "Child: Executing different code using exec()", NULL);

        // If execlp() fails
        fprintf(stderr, "Exec Failed\n");
    } else {
        // Parent process
        printf("Parent Process: PID = %d\n", getpid());

        // 3. Parent waits for child to finish
        wait(NULL);
        printf("Parent: Child has finished execution.\n");
    }

    return 0;
}