#ifndef SRC_HEADERS_S21_SSCANF_H_
#define SRC_HEADERS_S21_SSCANF_H_

#define OPT "cdieEfgGosuxXpn"
#define TRIM " \n\t\v\f\r"

typedef struct {
  char specArg;
  int success;
  int widthArg;
  char lenArg;
  int skip;
} specInfo;

int s21_sscanf(const char *str, const char *format, ...);
char *trim_start(char *str);
int spec_validation(char c);
int spec_parse(char **format, specInfo *specs);
int get_width(char **format);
int check_digit(char c);
void check_lenArg(specInfo *specs, char **format);
int spec_processing(char **strPointer, specInfo *specs, va_list paramList);
int process_c(char **strPointer, specInfo *specs, va_list paramList);

#endif //  SRC_HEADERS_S21_SSCANF_H_