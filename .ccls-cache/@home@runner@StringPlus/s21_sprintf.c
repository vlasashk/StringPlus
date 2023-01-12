#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  str[0] = '\0';
  va_list paramList;
  va_start(paramList, format);
  for (int j = 0; j < 2; j++) {
    printf("%s\n", va_arg(paramList, char *));
  }

  va_end(paramList);
  return s21_strlen(str);
}
