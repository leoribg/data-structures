#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// Fibonacci recursive implementation with memoization (dynamic programming)
// https://en.wikipedia.org/wiki/Memoization

int fib(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int fib_memo(int n) {
    static int memo[1000];
    // if n exists in memo, return it
    if (memo[n] != 0) {
        return memo[n];
    } else {
        if (n <= 1) {
            memo[n] = n;
        } else {
            memo[n] = fib_memo(n - 1) + fib_memo(n - 2);
        }
        return memo[n];
    }
}