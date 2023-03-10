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
int spec_processing(char **strPointer, specInfo *specs, va_list paramList,
                    const char *str);
int process_c(char **strPointer, specInfo *specs, va_list paramList);
int process_s(char **strPointer, specInfo *specs, va_list paramList);
int process_n(char **strPointer, specInfo *specs, va_list paramList,
              const char *str);
int process_d(char **strPointer, specInfo *specs, va_list paramList);
int scanf_atoi(char **str, int width, long long *result, int base, int coef);
int scanf_atold(char **str, int width, long double *result);
int check_operator(char **str, int *width);
int process_float(char **strPointer, specInfo *specs, va_list paramList);
char lower_char(char c);
int scan_nan_inf(char *str, char *comp, int abort, int *width);
int inf_or_nan(char **str, long double *result, int *width);
long double atold_process(char **str, int *width);
void handle_exp(char **str, int *width, long double *res);
int process_unsigned(char **strPointer, specInfo *specs, va_list paramList,
                     int base);
int s21_strtoull(char **str, int width, unsigned long long *result, int base);
int base_check(char c, int base);
int base_convert(char c, int base);
int trim_hex_start(char **str, int *width, int *zero_stat);
int any_numeral(char **str, int width, long long *result);
int process_i(char **strPointer, specInfo *specs, va_list paramList);
int EOF_check(const char *src);

#endif  //  SRC_HEADERS_S21_SSCANF_H_
