#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// Reverse a string in C recursively

void reverseString(char *str, char *rev_str) {
    static int index = 0;

    if (str == NULL) {
        return;
    }
    else if (str[0] == '\0') {
        return;
    }
    else {
        reverseString(str + 1, rev_str);
        rev_str[index] = str[0];
        index++;
    }
}

void main () {
    static char str[100];
    static char rev_str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    reverseString(str, rev_str);
    printf("Reversed string: %s\n", rev_str);
}