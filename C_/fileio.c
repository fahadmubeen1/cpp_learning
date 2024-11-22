#include <stdio.h>

int main() {
    FILE *file_pointer; // File pointer
    char data[] = "Hello, world! This is some data to write to the file.\n"; // Data to write

    // Open a file in write mode ("w")
    file_pointer = fopen("example.txt", "w");

    // Check if the file opened successfully
    if (file_pointer == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write data to the file
    fputs(data, file_pointer);

    // Close the file
    fclose(file_pointer);

    printf("Data written to file successfully!\n");

    return 0;
}




//.............................









//.............................









//.............................