#include <stdio.h>
#include <stdlib.h>

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command-line argument
    if (argc != 2) {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    // Open the specified file for reading
    FILE* file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    // Seek to the end of the file to determine its size
    if (fseek(file, 0, SEEK_END) != 0) {
        perror("Error seeking in file");
        fclose(file);
        return -1;
    }

    // Get the size of the file
    long file_size = ftell(file);
    if (file_size == -1) {
        perror("Error telling file size");
        fclose(file);
        return -1;
    }

    fclose(file);

    // Print the size of the file
    printf("The size of the file is: %ld bytes\n", file_size);

    return 0;
}
