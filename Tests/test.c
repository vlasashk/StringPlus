#include "../s21_string.h"
#include <stdio.h>
#include <string.h>

int main() {
  char line[40] = "-9223372036854775806 WOPPER -949";
  // char line2[20] = "H 1 \t4\t    \n2";
  // // s21_sprintf(line, "Hello", "Little", "Little");
  // // s21_sscanf(line, "Hello", "Little", "Little");
  char hel[20] = {0};
  long int w = 0;
  int gop = 0;
  // int ch = 0;
  int res = s21_sscanf(line, "%ld \t\t%s %3d", &w, hel, &gop);
  printf("%ld|\n%s|\n%d|\n", w, hel, gop);
  printf("res: %d\n", res);
  return 0;
}