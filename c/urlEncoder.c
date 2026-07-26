// replace all spaces in a string   with "%20"
#include <stdio.h>

void url_encode(char *str, int true_length) {
    int space_count = 0;

    // Pass 1: Count the number of spaces in the original string
    for (int i = 0; i < true_length; i++) {
        if (str[i] == ' ') {
            space_count++;
        }
    }

    // Each space ' ' (1 char) is replaced by "%20" (3 chars), adding 2 extra chars per space
    int new_index = true_length + space_count * 2;

    // Null-terminate the new longer string
    str[new_index] = '\0';

    // Pass 2: Work backwards to shift characters into their new positions
    for (int i = true_length - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[new_index - 1] = '0';
            str[new_index - 2] = '2';
            str[new_index - 3] = '%';
            new_index -= 3;
        } else {
            str[new_index - 1] = str[i];
            new_index--;
        }
    }
}

int main() {
    // Allocate extra buffer space at the end to hold the extra '%20' characters
    char str[100] = "Hello World    "; 
    int true_length = 11; // Length of "Hello World"

    printf("Original: \"%s\"\n", "Hello World");

    url_encode(str, true_length);

    printf("Encoded:  \"%s\"\n", str);

    return 0;
}

