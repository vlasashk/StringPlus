#include "../s21_string.h"
#include <stdio.h>
#include <string.h>

int main() {
  char *line = "infinity.004324Erinf";
  // char line2[20] = "H 1 \t4\t    \n2";
  // // s21_sprintf(line, "Hello", "Little", "Little");
  // // s21_sscanf(line, "Hello", "Little", "Little");
  char hel[20] = {0};
  double w = 0;
  double gop = 0;
  int res = sscanf(line, "%lf \t\t%lf%s", &w, &gop, hel);
  printf("%lf|\n%lf|\n%s|\n", w, gop, hel);
  printf("res: %d\n", res);
  return 0;
}
