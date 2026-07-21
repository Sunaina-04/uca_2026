// takes string "C,C++,Java,Python,Rust"

#include <stdio.h>
#include <string.h>

int main() {
    // strtok modifies the string, so it must be stored in a mutable char array, NOT a string literal 
    char str[] = "C,C++,Java,Python,Rust";

    // Delimiter is a comma
    const char delim[] = ",";

    // Get the first token
    char *token = strtok(str, delim);

    // Continue extracting tokens until strtok returns NULL
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, delim); // Pass NULL to continue parsing the same string
    }

    return 0;
}

