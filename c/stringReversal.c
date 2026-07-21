#include <stdio.h>
#include <string.h>

// Function to reverse a string in-place
void reverse_string(char *str) {
    if (str == NULL) return;

    int start = 0;
    int end = strlen(str) - 1;

    // Swap characters from outer bounds moving inward
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main() {
    // Must be a mutable character array to allow in-place modification
    char str[] = "Data Structures";

    printf("Original: %s\n", str);
    
    reverse_string(str);
    
    printf("Reversed: %s\n", str);

    return 0;
}

