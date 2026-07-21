//function returns the starting index of first occurence of substring
#include <stdio.h>

int find_substring(const char *haystack, const char *needle) {
    if (*needle == '\0') {
        return 0;
    }

    // Outer loop traverses each character in haystack
    for (int i = 0; haystack[i] != '\0'; i++) {
        int j = 0;

        // Inner loop checks if needle matches starting at haystack[i]
        while (needle[j] != '\0' && haystack[i + j] != '\0' && haystack[i + j] == needle[j]) {
            j++;
        }

        // If we reached the end of needle, a full match was found
        if (needle[j] == '\0') {
            return i;
        }
    }

    // Needle was not found in haystack
    return -1;
}

int main() {
    const char *haystack = "Embedded Systems";
    const char *needle = "bed";

    int index = find_substring(haystack, needle);

    printf("Haystack: \"%s\"\n", haystack);
    printf("Needle:   \"%s\"\n", needle);
    printf("Output:   %d\n", index);

    return 0;
}

