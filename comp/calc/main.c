#include "errors.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if(argc!=2){
        char* message = "Incorrect Usage";
        causeError(message);
    }
    FILE *file_ptr;
    char ch;

    // Opening file in reading mode
    file_ptr = fopen(argv[1], "r");

    if (NULL == file_ptr) {
        causeError("File could not be opened");
    }

    printf("Content of the file are:-: \n");

    // Printing what is written in file
    // character by character using loop.
    while ((ch = fgetc(file_ptr)) != EOF) {
        printf("%c", ch);
    }

    // Closing the file
    fclose(file_ptr);
    return 0;
}
