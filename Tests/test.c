#include "../s21_string.h"
#include <stdio.h>
//#include <string.h>

int main() {
  char line[30] = "\t\t213123abc32111233\n";
  char line2[30] = "\t\t2313321a32bF321c331221\t\t";
  char *test = "\t123\n";
  char *test1 = s21_trim(line, test);
  char *test2 = s21_trim(line2, test);
  printf("%s\n", test1);
  printf("%s\n", test2);
  free(test1);
  free(test2);
  return 0;
}