#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char buff[50];
    int n;
    
    int fd1 = open("source.txt", O_RDONLY);
    int fd2 = open("target.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    
    if (fd1 < 0) {
        printf("\nSource File not opened successfully.\n");
        return 1; // Exit with error code
    } else if (fd2 < 0) {
        printf("\nTarget File not opened successfully.\n");
        close(fd1); // Close the source file before exiting
        return 1; // Exit with error code
    }
    
    while ((n = read(fd1, buff, sizeof(buff))) > 0) {
        write(fd2, buff, n);
    }

    close(fd1); // Close the source file
    close(fd2); // Close the target file

    return 0; // Successful execution
}