#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 256

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command-line argument
    if (argc != 2) {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    // Ensure the command buffer has sufficient space and prevent overflow
    char cmd[BUFSIZE] = "wc -c < ";
    if (strlen(argv[1]) >= (BUFSIZE - strlen(cmd) - 1)) {
        fprintf(stderr, "File path is too long.\n");
        return -1;
    }

    // Safely concatenate the file path to the command
    strncat(cmd, argv[1], BUFSIZE - strlen(cmd) - 1);

    // Execute the command to get the file size
    int result = system(cmd);

    // Check if the system call was successful
    if (result != 0) {
        fprintf(stderr, "Error executing the command.\n");
        return -1;
    }

    return 0;
}
