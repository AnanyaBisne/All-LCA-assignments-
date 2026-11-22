#include <stdio.h>

unsigned long long factorial_iterative(int n) {
    if (n < 0) return 0;
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

unsigned long long factorial_recursive(int n) {
    if (n < 0) return 0;
    if (n == 0 || n == 1) return 1;
    return n * factorial_recursive(n - 1);
}

int main() {
    int number;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Iterative Factorial of %d: %llu\n", number, factorial_iterative(number));
        printf("Recursive Factorial of %d: %llu\n", number, factorial_recursive(number));
    }

    return 0;
}
