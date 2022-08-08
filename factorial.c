#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// Factorial implementation in C

int findFactorialIterative(int n) {
    int factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}

int findFactorialRecursive(int n) {
    /* Base case */
    if (n == 1) {
        printf("Factorial of %d is 1\n", n);
        return 1;
    }
    /* Recursive case */
    printf("n = %d\n", n);
    return n * findFactorialRecursive(n - 1);
}

int main() {
    static int factorial;

    factorial = findFactorialIterative(5);
    printf("Factorial of 5 is %d\n", factorial);
    factorial = findFactorialRecursive(5);
    printf("Factorial of 5 is %d\n", factorial);
    return 0;
}