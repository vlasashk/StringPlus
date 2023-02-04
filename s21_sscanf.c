#include "s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {
  int res = 0;
  int eof_flag = EOF_check(str);
  char *formatPointer = (char *)format;
  char *strPointer = (char *)str;
  va_list paramList;
  va_start(paramList, format);
  while (*formatPointer && res != -1) {
    if (*formatPointer == '%') {
      formatPointer++;
      specInfo specs = {0};
      if (*formatPointer != '%') {
        if (spec_parse(&formatPointer, &specs) != 0) {
          if (eof_flag == -1) {
            res = eof_flag;
          }
          if (spec_processing(&strPointer, &specs, paramList, str) == 1) {
            res += specs.success;
          } else {
            break;
          }
        } else {
          break;
        }
      } else {
        strPointer = trim_start(strPointer);
        if (*strPointer == '%') {
          strPointer++;
          formatPointer++;
        } else {
          break;
        }
      }
    } else {
      if (*strPointer == *formatPointer && *formatPointer != ' ') {
        strPointer++;
        formatPointer++;
      } else if (s21_strchr(TRIM, *formatPointer) != S21_NULL) {
        formatPointer = trim_start(formatPointer);
        strPointer = trim_start(strPointer);
      } else {
        break;
      }
    }
  }
  va_end(paramList);
  return res;
}

int spec_parse(char **format, specInfo *specs) {
  int res = 1;
  if (**format == '*') {
    specs->skip = 1;
    (*format)++;
  }
  if (check_digit(**format) == 1) {
    specs->widthArg = get_width(format);
  }
  check_lenArg(specs, format);
  if (spec_validation(**format)) {
    specs->specArg = **format;
  } else {
    specs->specArg = '0';
    res = 0;
  }

  (*format)++;
  return res;
}

int check_digit(char c) {
  int res = 0;
  if (c >= '0' && c <= '9') {
    res = 1;
  }
  return res;
}

int get_width(char **format) {
  int res = 0;
  while (**format >= '0' && **format <= '9') {
    res = res * 10 + **format - '0';
    (*format)++;
  }
  return res;
}

void check_lenArg(specInfo *specs, char **format) {
  if (**format == 'l') {
    specs->lenArg = 'l';
    (*format)++;
    if (**format == 'l') {
      specs->lenArg = 'L';
      (*format)++;
    }
  } else if (**format == 'h') {
    specs->lenArg = 'h';
    (*format)++;
  } else if (**format == 'L') {
    specs->lenArg = 'L';
    (*format)++;
  } else {
    specs->lenArg = '0';
  }
}

int spec_validation(char c) {
  int flag = 0;
  if (s21_strchr(OPT, c) != S21_NULL) {
    flag = 1;
  }
  return flag;
}

int spec_processing(char **strPointer, specInfo *specs, va_list paramList,
                    const char *str) {
  int res = 0;
  if (strPointer != S21_NULL) {
    switch (specs->specArg) {
    case 'c':
      res = process_c(strPointer, specs, paramList);
      break;
    case 'd':
      (*strPointer) = trim_start(*strPointer);
      res = process_d(strPointer, specs, paramList);
      break;
    case 'i':
      (*strPointer) = trim_start(*strPointer);
      res = process_i(strPointer, specs, paramList);
      break;
    case 'e':
      (*strPointer) = trim_start(*strPointer);
      res = process_float(strPointer, specs, paramList);
      break;
    case 'E':
      (*strPointer) = trim_start(*strPointer);
      res = process_float(strPointer, specs, paramList);
      break;
    case 'f':
      (*strPointer) = trim_start(*strPointer);
      res = process_float(strPointer, specs, paramList);
      break;
    case 'g':
      (*strPointer) = trim_start(*strPointer);
      res = process_float(strPointer, specs, paramList);
      break;
    case 'G':
      (*strPointer) = trim_start(*strPointer);
      res = process_float(strPointer, specs, paramList);
      break;
    case 'o':
      (*strPointer) = trim_start(*strPointer);
      res = process_unsigned(strPointer, specs, paramList, 8);
      break;
    case 's':
      (*strPointer) = trim_start(*strPointer);
      res = process_s(strPointer, specs, paramList);
      break;
    case 'u':
      (*strPointer) = trim_start(*strPointer);
      res = process_unsigned(strPointer, specs, paramList, 10);
      break;
    case 'x':
      (*strPointer) = trim_start(*strPointer);
      res = process_unsigned(strPointer, specs, paramList, 16);
      break;
    case 'X':
      (*strPointer) = trim_start(*strPointer);
      res = process_unsigned(strPointer, specs, paramList, 16);
      break;
    case 'p':
      specs->lenArg = 'L';
      (*strPointer) = trim_start(*strPointer);
      res = process_unsigned(strPointer, specs, paramList, 16);
      break;
    case 'n':
      res = process_n(strPointer, specs, paramList, str);
      break;
    default:
      break;
    }
  }
  return res;
}

int process_c(char **strPointer, specInfo *specs, va_list paramList) {
  int res = 1;
  if (**strPointer && specs->lenArg == '0') {
    if (specs->skip != 1) {
      *(va_arg(paramList, char *)) = **strPointer;
      specs->success = 1;
    }
    (*strPointer)++;
  } else {
    res = 0;
  }
  return res;
}

int process_s(char **strPointer, specInfo *specs, va_list paramList) {
  int res = 1;
  if (**strPointer && specs->lenArg == '0') {
    if (specs->widthArg == 0) {
      specs->widthArg = INT_MAX;
    }
    if (specs->skip != 1) {
      char *temp = va_arg(paramList, char *);
      while (**strPointer && specs->widthArg > 0 &&
             s21_strchr(TRIM, **strPointer) == S21_NULL) {
        *temp++ = **strPointer;
        (*strPointer)++;
        specs->widthArg--;
      }
      *temp = '\0';
      specs->success = 1;
    } else {
      while (**strPointer && specs->widthArg > 0 &&
             s21_strchr(TRIM, **strPointer) == S21_NULL) {
        (*strPointer)++;
        specs->widthArg--;
      }
    }
  } else {
    res = 0;
  }
  return res;
}

int process_d(char **strPointer, specInfo *specs, va_list paramList) {
  int flag = 0;
  long long result = 0;
  if (**strPointer) {
    if (specs->widthArg == 0) {
      specs->widthArg = INT_MAX;
    }
    strPointer += s21_strspn(*strPointer, TRIM);
    int coef = check_operator(strPointer, &specs->widthArg);
    if ((flag = scanf_atoi(strPointer, specs->widthArg, &result, 10, coef)) ==
        1) {
      if (specs->skip != 1) {
        switch (specs->lenArg) {
        case 'h':
          *(va_arg(paramList, short *)) = (short)result;
          break;
        case 'l':
          *(va_arg(paramList, long *)) = (long)result;
          break;
        case 'L':
          *(va_arg(paramList, long long *)) = result;
          break;
        default:
          *(va_arg(paramList, int *)) = (int)result;
          break;
        }
        specs->success = 1;
      }
    }
  }
  return flag;
}

int process_i(char **strPointer, specInfo *specs, va_list paramList) {
  int flag = 0;
  long long result = 0;
  if (**strPointer) {
    if (specs->widthArg == 0) {
      specs->widthArg = INT_MAX;
    }
    if ((flag = any_numeral(strPointer, specs->widthArg, &result)) == 1) {
      if (specs->skip != 1) {
        switch (specs->lenArg) {
        case 'h':
          *(va_arg(paramList, short *)) = (short)result;
          break;
        case 'l':
          *(va_arg(paramList, long *)) = (long)result;
          break;
        case 'L':
          *(va_arg(paramList, long long *)) = result;
          break;
        default:
          *(va_arg(paramList, int *)) = (int)result;
          break;
        }
        specs->success = 1;
      }
    }
  }
  return flag;
}

int process_unsigned(char **strPointer, specInfo *specs, va_list paramList,
                     int base) {
  int flag = 0;
  unsigned long long result = 0;
  if (**strPointer) {
    if (specs->widthArg == 0) {
      specs->widthArg = INT_MAX;
    }
    if ((flag = s21_strtoull(strPointer, specs->widthArg, &result, base)) ==
        1) {
      if (specs->skip != 1) {
        switch (specs->lenArg) {
        case 'h':
          *(va_arg(paramList, unsigned short *)) = (unsigned short)result;
          break;
        case 'l':
          *(va_arg(paramList, unsigned long *)) = (unsigned long)result;
          break;
        case 'L':
          *(va_arg(paramList, unsigned long long *)) = result;
          break;
        default:
          *(va_arg(paramList, unsigned int *)) = (unsigned int)result;
          break;
        }
        specs->success = 1;
      }
    }
  }
  return flag;
}

int process_float(char **strPointer, specInfo *specs, va_list paramList) {
  int flag = 0;
  long double result = 0;
  if (**strPointer) {
    if (specs->widthArg == 0) {
      specs->widthArg = INT_MAX;
    }
    if ((flag = scanf_atold(strPointer, specs->widthArg, &result)) == 1) {
      if (specs->skip != 1) {
        switch (specs->lenArg) {
        case 'h':
          flag = 0;
          break;
        case 'l':
          *(va_arg(paramList, double *)) = (double)result;
          break;
        case 'L':
          *(va_arg(paramList, long double *)) = result;
          break;
        default:
          *(va_arg(paramList, float *)) = (float)result;
          break;
        }
        specs->success = 1;
      }
    }
  }
  return flag;
}

int trim_hex_start(char **str, int *width, int *zero_stat) {
  int res = 10;
  int local_width = *width;
  char *pointer = *str;
  if (*pointer == '0' && local_width > 0) {
    pointer++;
    local_width--;
    res = 8;
    if ((*pointer == 'x' || *pointer == 'X') && local_width > 0) {
      pointer++;
      local_width--;
      res = 16;
      if (base_check(*pointer, 16) || *pointer == ' ' || local_width == 0) {
        (*str) += 2;
        (*width) -= 2;
        if (*pointer == ' ' || local_width == 0) {
          *zero_stat = 1;
        }
      }
    }
  }
  return res;
}

int base_convert(char c, int base) {
  int res = 0;
  if (base <= 10) {
    res = c - '0';
  } else {
    if (c >= '0' && c <= '9') {
      res = c - '0';
    } else if (c >= 'A' && c <= 'F') {
      res = c - 'A' + 10;
    } else {
      res = c - 'a' + 10;
    }
  }
  return res;
}

int base_check(char c, int base) {
  int res = 0;
  if (base == 10) {
    if (c >= '0' && c <= '9') {
      res = 1;
    }
  } else if (base == 8) {
    if (c >= '0' && c <= '7') {
      res = 1;
    }
  } else {
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') ||
        (c >= 'a' && c <= 'f')) {
      res = 1;
    }
  }
  return res;
}

int process_n(char **strPointer, specInfo *specs, va_list paramList,
              const char *str) {
  int res = 0;
  if (strPointer != S21_NULL) {
    if (specs->skip != 1) {
      switch (specs->lenArg) {
      case 'h':
        *(va_arg(paramList, short *)) = (short)(*strPointer - str);
        break;
      case 'l':
        *(va_arg(paramList, long *)) = (long)(*strPointer - str);
        break;
      case 'L':
        *(va_arg(paramList, long long *)) = (long long)(*strPointer - str);
        break;
      default:
        *(va_arg(paramList, int *)) = (int)(*strPointer - str);
        break;
      }
      res = 1;
    }
  } else {
    res = 0;
  }
  return res;
}

int s21_strtoull(char **str, int width, unsigned long long *result, int base) {
  int flag = 0;
  str += s21_strspn(*str, TRIM);
  int coef = check_operator(str, &width);
  int zero_stat = 0;
  unsigned long long res = 0;
  if (base == 16) {
    trim_hex_start(str, &width, &zero_stat);
  }
  if (zero_stat == 1) {
    flag = 1;
    res = 0;
  } else if (base_check(**str, base) && width > 0) {
    flag = 1;
    while (base_check(**str, base) && width > 0) {
      int converted = 0;
      converted = base_convert(**str, base);
      if ((ULLONG_MAX - converted) / base >= res) {
        res = res * base + converted;
        (*str)++;
        width--;
      } else {
        res = ULLONG_MAX;
        while (base_check(**str, base) && width > 0) {
          (*str)++;
          width--;
        }
        break;
      }
    }
  }
  res *= coef;
  *result = res;
  return flag;
}

int scanf_atold(char **str, int width, long double *result) {
  long double res = 0;
  int flag = 0;
  str += s21_strspn(*str, TRIM);
  int coef = check_operator(str, &width);
  if (inf_or_nan(str, &res, &width) == 1) {
    flag = 1;
  } else if (((**str >= '0' && **str <= '9') || **str == '.') && width > 0) {
    flag = 1;
    if (**str == '.') {
      flag = 0;
      char *pointer = *str;
      pointer++;
      if (*pointer >= '0' && *pointer <= '9') {
        flag = 1;
      }
    }
    if (flag == 1) {
      res = atold_process(str, &width);
      if (width > 0) {
        handle_exp(str, &width, &res);
      }
    }
  }
  res *= coef;
  *result = res;
  return flag;
}

long double atold_process(char **str, int *width) {
  long double res = 0;
  while (**str >= '0' && **str <= '9' && *width > 0) {
    res = res * 10 + (**str - '0');
    (*str)++;
    (*width)--;
  }
  if (**str == '.' && *width > 0) {
    long double frac = 0.0;
    (*str)++;
    (*width)--;
    int frac_pow = 1;
    while (**str >= '0' && **str <= '9' && *width > 0) {
      frac += (long double)(**str - '0') / powl(10., frac_pow++);
      (*str)++;
      (*width)--;
    }
    res += frac;
  }
  return res;
}

void handle_exp(char **str, int *width, long double *res) {
  long long exp = 0;
  if (**str == 'e' || **str == 'E') {
    (*str)++;
    (*width)--;
    str += s21_strspn(*str, TRIM);
    int coef = check_operator(str, width);
    if (scanf_atoi(str, *width, &exp, 10, coef) == 1) {
      *res *= powl(10.0, (long double)exp);
    }
  }
}

int check_operator(char **str, int *width) {
  int coef = 1;
  if (**str == '+') {
    (*str)++;
    (*width)--;
  }
  if (**str == '-') {
    coef = -1;
    (*str)++;
    (*width)--;
  }
  return coef;
}

int any_numeral(char **str, int width, long long *result) {
  int flag = 0;
  long long res = 0;
  int zero_stat = 0;
  str += s21_strspn(*str, TRIM);
  int coef = check_operator(str, &width);
  int base = trim_hex_start(str, &width, &zero_stat);
  char sign_check = **str;
  sign_check++;
  if (zero_stat == 1) {
    flag = 1;
    res = 0;
  } else if (base_check(**str, base) && width > 0 && sign_check != '-' &&
             sign_check != '+') {
    flag = scanf_atoi(str, width, &res, base, coef);
  }
  *result = res;
  return flag;
}

int scanf_atoi(char **str, int width, long long *result, int base, int coef) {
  int flag = 0;
  if (base_check(**str, base) && width > 0) {
    long long res = 0;
    flag = 1;
    while (base_check(**str, base) && width > 0) {
      int converted = 0;
      converted = base_convert(**str, base);
      if ((LLONG_MAX - converted) / base >= res) {
        res = res * base + converted;
        (*str)++;
        width--;
      } else {
        if (coef == -1) {
          if ((LLONG_MIN + converted) / base < -res) {
            res = LLONG_MIN + 1;
          } else {
            res = LLONG_MIN;
          }
          coef = 1;
        } else {
          res = LLONG_MAX;
        }
        while (base_check(**str, base) && width > 0) {
          (*str)++;
          width--;
        }
        break;
      }
    }
    res *= coef;
    *result = res;
  }
  return flag;
}

char lower_char(char c) {
  char res = c;
  if (c >= 'A' && c <= 'Z') {
    res += 32;
  }
  return res;
}

int scan_nan_inf(char *str, char *comp, int abort, int *width) {
  int res = 1;
  if (str) {
    while (abort != 0 && *width != 0) {
      char cmp;
      cmp = lower_char(*str);
      if (cmp != *comp) {
        res = 0;
        break;
      }
      abort--;
      str++;
      comp++;
      (*width)--;
    }
    if (*width == 0 && abort != 0) {
      res = 0;
    }
  } else {
    res = 0;
  }
  return res;
}

int inf_or_nan(char **str, long double *result, int *width) {
  int res = 1;
  int abort;
  char *local_s = *str;
  int local_width = *width;
  char *nan_str = "nan";
  char *inf_str = "inf";
  char *inf_full = "infinity";
  char cmp = lower_char(*local_s);
  switch (cmp) {
  case 'n':
    local_s++;
    local_width--;
    nan_str++;
    abort = 2;
    if ((res = scan_nan_inf(local_s, nan_str, abort, &local_width)) == 1) {
      (*str) += 3;
      *width = local_width;
      *result = NAN;
    }
    break;
  case 'i':
    local_s++;
    local_width--;
    inf_str++;
    inf_full++;
    abort = 2;
    if (scan_nan_inf(local_s, inf_str, abort, &local_width) == 1) {
      local_s += abort;
      inf_full += abort;
      cmp = lower_char(*local_s);
      if (local_width == 0) {
        (*str) += 3;
        *width = local_width;
        *result = INFINITY;
      } else if (cmp == 'i') {
        abort = 5;
        if ((res = scan_nan_inf(local_s, inf_full, abort, &local_width)) == 1) {
          (*str) += 8;
          *width = local_width;
          *result = INFINITY;
        }
      } else {
        (*str) += 3;
        *width = local_width;
        *result = INFINITY;
      }
    } else {
      res = 0;
    }
    break;
  default:
    res = 0;
    break;
  }
  return res;
}

char *trim_start(char *str) {
  str += s21_strspn(str, TRIM);
  return str;
}

int EOF_check(const char *src) {
  int res = 0;
  char *pointer = (char *)src;
  pointer = trim_start(pointer);
  if (*pointer == '\0') {
    res = -1;
  }
  return res;
}
