#include <stdio.h>
__attribute__((constructor))
void customFunction() {
  printf("This will run before the constructor\n");
}
int main() {
  printf("This will run in the main function\n");
  return 0;
}
