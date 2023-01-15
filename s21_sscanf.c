#include "s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {
  int res;
  if (*str) {
    res = 0;
  } else {
    res = -1;
  }

  char *formatPointer = (char *)format;
  char *strPointer = (char *)str;
  va_list paramList;
  va_start(paramList, format);
  while (*formatPointer && *strPointer) {
    formatPointer = trim_start(formatPointer);
    strPointer = trim_start(strPointer);
    if (*formatPointer == '%') {
      formatPointer++;
      specInfo specs = {0};
      if (*formatPointer != '%') {
        if (spec_parse(&formatPointer, &specs) != 0) {
          if (spec_processing(&strPointer, &specs, paramList, str) == 1) {
            res += specs.success;
          } else {
            break;
          }
        } else {
          res = -1;
          break;
        }
      } else if (*strPointer == '%') {
        strPointer++;
        formatPointer++;
      } else {
        res = -1;
        break;
      }
    } else {
      if (*strPointer == *formatPointer) {
        strPointer++;
        formatPointer++;
      } else {
        break;
      }
    }
  }
  va_end(paramList);
  return res;
}

int spec_processing(char **strPointer, specInfo *specs, va_list paramList,
                    const char *str) {
  int res = 0;
  if (**strPointer) {
    switch (specs->specArg) {
    case 'c':
      if (process_c(strPointer, specs, paramList) == 1) {
        res = 1;
      }
      break;
    case 'd':
      if (process_d(strPointer, specs, paramList) == 1) {
        res = 1;
      }
      break;
    case 'i':
      break;
    case 'e':
      if (process_float(strPointer, specs, paramList) == 1) {
        res = 1;
      }
      break;
    case 'E':
      if (process_float(strPointer, specs, paramList) == 1) {
        res = 1;
      }
      break;
    case 'f':
      if (process_float(strPointer, specs, paramList) == 1) {
        res = 1;
      }
      break;
    case 'g':
      if (process_float(strPointer, specs, paramList) == 1) {
        res = 1;
      }
      break;
    case 'G':
      if (process_float(strPointer, specs, paramList) == 1) {
        res = 1;
      }
      break;
    case 'o':
      break;
    case 's':
      if (process_s(strPointer, specs, paramList) == 1) {
        res = 1;
      }
      break;
    case 'u':
      break;
    case 'x':
      break;
    case 'X':
      break;
    case 'p':
      break;
    case 'n':
      if (process_n(strPointer, specs, paramList, str) == 1) {
        res = 1;
      }
      break;
    default:
      break;
    }
  }
  return res;
}

int process_float(char **strPointer, specInfo *specs, va_list paramList) {
  int flag = 0;
  long double result = 0;
  if (**strPointer) {
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

int scanf_atold(char **str, int width, long double *result) {
  if (width == 0) {
    width = INT_MAX;
  }
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
    }
  }
  res *= coef;
  *result = res;
  return flag;
}

long double atold_process(char **str, int *width) {
  long double res = 0;
  long double frac = 0.0;
  while (**str >= '0' && **str <= '9' && *width > 0) {
    res = res * 10 + (**str - '0');
    (*str)++;
    (*width)--;
  }
  if (**str == '.') {
    (*str)++;
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

int process_s(char **strPointer, specInfo *specs, va_list paramList) {
  int res = 1;
  if (**strPointer && specs->lenArg == '0') {
    if (specs->widthArg == 0) {
      specs->widthArg = INT_MAX;
    }
    if (specs->skip != 1) {
      char *temp = va_arg(paramList, char *);
      while (**strPointer && specs->widthArg > 0 && **strPointer != ' ') {
        *temp++ = **strPointer;
        (*strPointer)++;
        specs->widthArg--;
      }
      *temp = '\0';
      specs->success = 1;
    } else {
      while (**strPointer && specs->widthArg > 0 && **strPointer != ' ') {
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
    if ((flag = scanf_atoi(strPointer, specs->widthArg, &result)) == 1) {
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

int process_n(char **strPointer, specInfo *specs, va_list paramList,
              const char *str) {
  int res = 0;
  if (**strPointer && specs->lenArg == '0') {
    if (specs->skip != 1) {
      *(va_arg(paramList, int *)) = *strPointer - str;
      specs->success = 1;
    }
  } else {
    res = 0;
  }
  return res;
}

int scanf_atoi(char **str, int width, long long *result) {
  if (width == 0) {
    width = INT_MAX;
  }
  int flag = 0;
  str += s21_strspn(*str, TRIM);
  int coef = check_operator(str, &width);
  if (**str >= '0' && **str <= '9' && width > 0) {
    long long res = 0;
    flag = 1;
    while (**str >= '0' && **str <= '9' && width > 0) {
      if ((LLONG_MAX - (**str - '0')) / 10 >= res) {
        res = res * 10 + (**str - '0');
        (*str)++;
        width--;
      } else {
        if (coef == -1) {
          if ((LLONG_MIN + (**str - '0')) / 10 < -res) {
            res = LLONG_MIN + 1;
          } else {
            res = LLONG_MIN;
          }
          coef = 1;
        } else {
          res = LLONG_MAX;
        }
        while (**str >= '0' && **str <= '9' && width > 0) {
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

char lower_char(char c) {
  char res = c;
  if (c >= 'A' && c <= 'Z') {
    res += 32;
  }
  return res;
}
int scan_nan_inf(char *str, char *comp, int abort, int *width) {
  int res = 1;
  char cmp;
  if (str) {
    while (abort != 0 && *width != 0) {
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

int spec_validation(char c) {
  int flag = 0;
  if (s21_strchr(OPT, c) != s21_NULL) {
    flag = 1;
  }
  return flag;
}

char *trim_start(char *str) {
  str += s21_strspn(str, TRIM);
  return str;
}
