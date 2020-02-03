#include "stdio.h"
#include "stdbool.h"

int main(int argc, char const *argv[]) {
  bool b = true;
  if (b) printf("if0\n");
  else printf("else0\n");
  if (!b) printf("if1\n");
  else printf("else1\n");
  return 0;
}
