#include "../s21_string.h"
#include <stdio.h>
#include <string.h>

int main() {
  char line[20] = "Hello World";
  // char line2[20] = "H 1 \t4\t    \n2";
  // // s21_sprintf(line, "Hello", "Little", "Little");
  // // s21_sscanf(line, "Hello", "Little", "Little");
  char hel[20] = {0};
  char w = '0';
  char gop = '0';
  int res = s21_sscanf(line, "%s \t\t%c %c", hel, &w, &gop);
  printf("%s|\n%c|\n%c|\n", hel, w, gop);
  printf("res: %d\n", res);
  return 0;
}