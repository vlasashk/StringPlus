#ifndef SRC_HEADERS_S21_SPRINTF_H_
#define SRC_HEADERS_S21_SPRINTF_H_

typedef struct {
  char flags[10];
  int width;
  int accuracy;
  char type;
} FormatFlags;

int s21_sprintf(char *str, const char *format, ...);

#endif //  SRC_HEADERS_S21_SPRINTF_H_