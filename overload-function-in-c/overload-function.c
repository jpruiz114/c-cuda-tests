#include <stdio.h>
#define print(x) _Generic((x), \
    int: print_int,            \
    double: print_double,      \
    char*: print_string        \
)(x)
void print_int(int x) {
  printf("Integer: %d\n", x);
}
void print_double(double x) {
  printf("Double: %f\n", x);
}
void print_string(char* x) {
  printf("String: %s\n", x);
}
int main() {
  print(34);
  print(3.14);
  print("Hello World!");
  return 0;
}
