//calculates and return length of string

#include <stdio.h>

// Custom function to calculate string length
int my_strlen(const char *str) {
    int length = 0;

    // Loop through the string until the null terminator ('\0') is reached
    while (str[length] != '\0') {
        length++;
    }

    return length;
}

int main() {
    const char *text = "Hello, World!";
    
    printf("String: %s\n", text);
    printf("Length: %d\n", my_strlen(text));

    return 0;
}

