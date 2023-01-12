#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

typedef struct {
  char flags[10];
  int width;
  int accuracy;
  char type;
} FormatFlags;

int s21_sprintf(char *str, const char *format, ...);

#endif //  SRC_S21_STRING_H_