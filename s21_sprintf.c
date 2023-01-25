#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list va;
  va_start(va, format);
  int flag = 1;
  int res = 0;
  struct FormatData formatData = {0};
  str[0] = '\0';
  char *start = str;
  while (*format) {
    if (flag) {
      s21_memset(&formatData, 0, sizeof(formatData));
      if (*format == '%') {
        format++;
        format = formatParser(format, &formatData, &flag, va);
        processSpecifier(&str, &formatData, va);
        res += formatData.counter;
      } else {
        writeToStr(str, format);
        res++;
        format++;
      }
    } else {
      printf("error");
      *str = '\0';
      break;
    }
  }
  va_end(va);
  return str - start;
}

int writeToStr(char *str, const char *format) {
  char *pointer = str;
  while (*pointer) {
    pointer++;
  }
  *pointer++ = *format++;
  *pointer = '\0';
  return 0;
}

const char *formatParser(const char *format, struct FormatData *formatData,
                         int *flag, va_list va) {
  format = getFlags(format, formatData);
  format = getWidth(format, formatData, va);
  format = getPrecision(format, formatData, va);
  format = getLength(format, formatData);
  format = getSpecifier(format, formatData, flag);
  return format;
}

const char *getFlags(const char *format, struct FormatData *formatData) {
  while (*format == '-' || *format == '+' || *format == ' ' || *format == '#' ||
         *format == '0') {
    switch (*format++) {
    case '-':
      formatData->flags.minus++;
      break;
    case '+':
      formatData->flags.plus++;
      break;
    case ' ':
      formatData->flags.spase++;
      break;
    case '#':
      formatData->flags.grid++;
      break;
    case '0':
      formatData->flags.zero++;
      break;
    }
  }
  return format;
}

const char *getWidth(const char *format, struct FormatData *formatData,
                     va_list va) {
  char widthBuff[100] = ""; //максимальное число не займет более 20 символов
  int k = 0;
  if (*format == '*') {
    formatData->width = va_arg(va, int);
    format++;
  } else {
    while (*format >= '0' && *format <= '9') {
      widthBuff[k++] = *format++;
    }
    formatData->width = s21_atoi(widthBuff);
  }
  return format;
}

const char *getPrecision(const char *format, struct FormatData *formatData,
                         va_list va) {
  char precisionBuff[100] = ""; //максимальное число не займет более 20 символов
  int k = 0;
  if (*format == '.') {
    formatData->has_precision = 1;
    format++;
    if (*format == '*') {
      formatData->precision = va_arg(va, int);
      format++;
    } else {
      while (*format >= '0' && *format <= '9') {
        precisionBuff[k++] = *format++;
      }
      formatData->precision = s21_atoi(precisionBuff);
    }
  }
  return format;
}

const char *getLength(const char *format, struct FormatData *formatData) {
  if (*format == 'h' || *format == 'l' || *format == 'L') {
    formatData->length = *format++;
  }
  return format;
}

const char *getSpecifier(const char *format, struct FormatData *formatData,
                         int *flag) {
  char s = *format;
  char *pattern = "cdieEfgGosuxXpn";
  if (s != '\0') {
    if (s21_strchr(pattern, s) != s21_NULL) {
      formatData->specifier = *format++;
    } else {
      *flag = 0;
    }
  }
  return format;
}

int processSpecifier(char **str, struct FormatData *formatData, va_list va) {
  switch (formatData->specifier) {
  case 'c':
    processChar(str, va, formatData);
    break;
  case 'd':
  case 'i':
    // processD(str, formatData, va);
    break;
  case 's':
    processString(*str, va, formatData);
    break;
  case 'f':
    // processF(str, formatData, va);
    break;
  case 'u':
    // processU(str, formatData, va);
    break;
  case 'n':
    // processN(str, va);
    break;
  case 'p':
    // processP(str, formatData, va);
    break;
  default:
    break;
  }
  return 0;
}

// int processF(char **str, va_list va, struct FormatData *formatData) {

//   return;
// }

int processChar(char **str, va_list va, struct FormatData *formatData) {
  char c = va_arg(va, int);
  char *pointer = *str;
  while (*pointer) {
    pointer++;
  }
  formatData->width--; //т.к один символ
  if (formatData->flags.minus != 0) {
    *pointer++ = c;
    formatData->counter++;
    *pointer = '\0';
    *str = pointer;
    setSpaces(str, formatData);
    setZeroes(*str, formatData);
  } else {
    setSpaces(str, formatData);
    setZeroes(*str, formatData);
    while (*pointer) {
      pointer++;
    }
    *pointer++ = c;
    formatData->counter++;
    *pointer = '\0';
    *str = pointer;
  }
  return 0;
}

int setSpaces(char **str, struct FormatData *formatData) {
  if (formatData->flags.zero == 0 || formatData->flags.minus != 0 ||
      formatData->has_precision != 0) {
    while (formatData->width-- > 0) {
      s21_strcat(*str, " ");
      (*str)++;
      formatData->counter++;
    }
  }
  return 0;
}

int setZeroes(char *str, struct FormatData *formatData) {
  if (formatData->flags.zero != 0 && formatData->flags.minus == 0 &&
      formatData->has_precision == 0) {
    while (formatData->width-- > 0) {
      s21_strcat(str, "0");
      formatData->counter++;
    }
  }
  return 0;
}

int processString(char *str, va_list va, struct FormatData *formatData) {
  char *s = va_arg(va, char *);
  if (formatData->has_precision == 0) {
    formatData->precision = s21_strlen(s);
  }
  if (formatData->width > 0 &&
      (formatData->width - formatData->precision) <= 0 &&
      formatData->has_precision != 0) {
    formatData->width = 1;
    formatData->counter = s21_strlen(s);
  } else {
    formatData->width -= formatData->precision;
    formatData->counter += formatData->precision;
  }

  if (formatData->flags.minus != 0) {
    s21_strncat(str, s, formatData->precision);
    setSpaces(&str, formatData);
    setZeroes(str, formatData);
  } else {
    setSpaces(&str, formatData);
    setZeroes(str, formatData);
    s21_strncat(str, s, formatData->precision);
  }
  return 0;
}

int processD(char *str, struct FormatData formatData, va_list va) {
  long long value = (long long)va_arg(va, long long int);

  switch (formatData.length) {
  case 'h':
    value = (short int)value;
    break;
  case '0':
    value = (int)value;
    break;
  case 'l':
    value = (long)value;
    break;
  default:
    break;
  }

  writeInt(str, &formatData, value);
  return 0;
}

int writeInt(char *str, struct FormatData *formatData, long long value) {
  char valueStr[100] = {'\0'}; //число
  if (formatData->flags.minus != 0) {
    intToStr(valueStr, value, formatData);
    setSign(str, value, *formatData);
    decreaseSignWidth(value, formatData);
    addZeroes(str, *formatData);
    decreaseZeroesWidth(formatData);
    setZeroes(str, formatData);
    s21_strcat(str, valueStr);
    setSpaces(&str, formatData);
  } else {
    intToStr(valueStr, value, formatData);
    decreaseSignWidth(value, formatData);
    decreaseZeroesWidth(formatData);
    setSpaces(&str, formatData);
    setSign(str, value, *formatData);
    addZeroes(str, *formatData);
    setZeroes(str, formatData);
    s21_strcat(str, valueStr);
  }
  return 0;
}

int processU(char *str, struct FormatData formatData, va_list va) {
  long long unsigned int value =
      (long long int)va_arg(va, long long unsigned int);
  switch (formatData.length) {
  case 'h':
    value = (short unsigned int)value;
    break;
  case '0':
    value = (unsigned)value;
    break;
  case 'l':
    value = (long unsigned int)value;
    break;
  default:
    break;
  }

  writeInt(str, &formatData, value);
  return 0;
}

int processN(char *str, va_list va) {
  int *value = va_arg(va, int *);
  *value = s21_strlen(str);
  return 0;
}

int processP(char *str, struct FormatData formatData, va_list va) {
  char valueStr[100] = {'\0'};
  long long unsigned int value =
      (long long unsigned int)va_arg(va, long long unsigned int);
  DecToHex(valueStr, value);
  formatData.width -= (s21_strlen(valueStr) + 2);
  if (formatData.flags.minus != 0) {
    s21_strcat(str, "0x");
    s21_strcat(str, valueStr);
    setSpaces(&str, &formatData);
  } else {
    setSpaces(&str, &formatData);
    s21_strcat(str, "0x");
    s21_strcat(str, valueStr);
  }
  return 0;
}

int setSign(char *str, long long int value, struct FormatData formatData) {
  if (formatData.specifier != 'u') {
    if (value < 0) {
      s21_strcat(str, "-");
    } else if (formatData.flags.plus != 0 && value >= 0) {
      s21_strcat(str, "+");
    } else if (formatData.flags.spase != 0) {
      s21_strcat(str, " ");
    }
  }
  return 0;
}

int decreaseSignWidth(long long int value, struct FormatData *formatData) {
  if (formatData->specifier != 'u') {
    if (value < 0 || (formatData->flags.plus != 0 && value >= 0) ||
        formatData->flags.spase != 0) {
      formatData->width--;
    }
  }
  return 0;
}

int addZeroes(char *str, struct FormatData formatData) {
  while (formatData.precision-- > 0) {
    s21_strcat(str, "0");
  }
  return 0;
}

int decreaseZeroesWidth(struct FormatData *formatData) {
  if (formatData->precision > 0) {
    formatData->width -= formatData->precision;
  }
  return 0;
}

int intToStr(char *valueStr, long long int value,
             struct FormatData *formatData) {
  int i = 0;
  if (value == 0 &&
      (formatData->has_precision == 0 ||
       (formatData->has_precision && formatData->precision != 0))) {
    valueStr[0] = '0';
    formatData->precision--;
  } else {
    if (value < 0) {
      value *= -1;
    }
    int num = NumberOfSymbolsInInt(value);
    i += num - 1;
    formatData->precision -= num;

    while (value != 0) {
      char ost = (value % 10) + 48;
      valueStr[i] = ost;
      value /= 10;
      i--;
    }
  }
  formatData->width -= s21_strlen(valueStr);
  return 0;
}

int NumberOfSymbolsInInt(long long int value) {
  int num = 0;
  while (value != 0) {
    num++;
    value /= 10;
  }
  return num;
}

int DecToHex(char *valueStr, long long int value) {
  char pattern[16] = {"0123456789abcdef"};
  char tempStr[100] = {'\0'};
  int i = 0;
  while (value != 0) {
    int remainder = value % 16;
    value = value / 16;
    tempStr[i++] = pattern[remainder];
  }
  i--;

  int k = 0;
  while (i >= 0) {
    valueStr[k++] = tempStr[i--];
  }
  return 0;
}
