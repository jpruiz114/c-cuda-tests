#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char** argv) {
    int result = fibonacci(atoi(argv[1]));
    printf("fibonacci(%d) = %d\n", atoi(argv[1]), result);
    return 0;
}
