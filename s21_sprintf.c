#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list va;
  va_start(va, format);
  int flag = 1;
  int res = 0;
  struct FormatData formatData = {0};
  str[0] = '\0';
  while (*format) {
    if (flag) {
      s21_memset(&formatData, 0, sizeof(formatData));
      if (*format == '%') {
        format++;
        format = formatParser(format, &formatData, &flag, va);
        processSpecifier(&str, &formatData, va, res);
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
  return res;
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
  if (*format == '*') {
    formatData->width = va_arg(va, int);
    format++;
  } else {
    char widthBuff[1024] = ""; //максимальное число не займет более 20 символов
    int k = 0;
    while (*format >= '0' && *format <= '9') {
      widthBuff[k++] = *format++;
    }
    formatData->width = s21_atoi(widthBuff);
  }
  return format;
}

const char *getPrecision(const char *format, struct FormatData *formatData,
                         va_list va) {
  if (*format == '.') {
    formatData->has_precision = 1;
    format++;
    if (*format == '*') {
      formatData->precision = va_arg(va, int);
      format++;
    } else {
      char precisionBuff[1024] =
          ""; //максимальное число не займет более 20 символов
      int k = 0;
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
  if (s != '\0') {
    char *pattern = "cdieEfgGosuxXpn";
    if (s21_strchr(pattern, s) != S21_NULL) {
      formatData->specifier = *format++;
    } else if (s == '%') {
      formatData->specifier = *format++;
    } else {
      *flag = 0;
    }
  }
  return format;
}

int processSpecifier(char **str, struct FormatData *formatData, va_list va,
                     int res) {
  switch (formatData->specifier) {
  case 'c':
  case '%':
    processChar(str, va, formatData);
    break;
  case 'd':
  case 'i':
    processD(*str, formatData, va);
    break;
  case 's':
    processString(*str, va, formatData);
    break;
  case 'f':
  case 'e':
  case 'E':
  case 'g':
  case 'G':
    processFloat(*str, formatData, va);
    break;
  case 'u':
  case 'x':
  case 'X':
  case 'o':
    processUnsigned(*str, formatData, va);
    break;
  case 'n':
    processN(va, res);
    break;
  case 'p':
    processP(*str, formatData, va);
    break;
  default:
    break;
  }
  return 0;
}

int processFloat(char *str, struct FormatData *formatData, va_list va) {
  long double value = 0;

  switch (formatData->length) {
  case 'l':
    value = (double)va_arg(va, double);
    break;
  case '\0':
    value = va_arg(va, double);
    break;
  case 'L':
    value = (long double)va_arg(va, long double);
    break;
  default:
    break;
  }
  switch (formatData->specifier) {
  case 'f':
    writeFloat(str, formatData, value);
    break;
  case 'e':
  case 'E':
    writeE_Value(str, formatData, value);
    break;
  case 'g':
  case 'G':
    writeG_Value(str, formatData, value);
    break;
  }

  return 0;
}

void writeG_Value(char *str, struct FormatData *formatData, long double value) {
  if (formatData->has_precision == 0) {
    formatData->precision = 6;
  }
  formatData->has_precision = 1;
  if ((fabsl(value) / powl(10, formatData->precision) > 1) ||
      (((fabsl(value) * (powl(10, 4))) < 1) && value != 0)) {
    if (formatData->precision != 0) {
      formatData->precision--;
    }
    writeE_Value(str, formatData, value);
  } else {
    if (fabsl(value) < 0.1 && value != 0) {
      int j = 1;
      if (formatData->precision == 0) {
        formatData->precision++;
      }
      while ((fabsl(value) * (powl(10, j))) < 1) {
        formatData->precision++;
        j++;
      }
    } else if (value != 0) {
      if (formatData->precision == 0) {
        formatData->precision++;
      } else {
        formatData->precision -= numberOfSymbolsInFloat(value);
      }
    } else {
      formatData->precision--;
    }
    writeFloat(str, formatData, value);
  }
}
void remove_zero(char *str, struct FormatData *formatData) {
  int pos = (int)s21_strlen(str) - 1;
  if (pos > 0) {
    while (str[pos] == '0' && !formatData->flags.grid &&
           formatData->has_precision) {
      str[pos] = '\0';
      pos--;
      formatData->counter--;
      formatData->width++;
    }
    if (!formatData->flags.grid && str[pos] == '.') {
      str[pos] = '\0';
      formatData->counter--;
      formatData->width++;
    }
  }
}

void writeE_Value(char *str, struct FormatData *formatData, long double value) {
  char valueStr[1024] = {'\0'}; //число
  int exp_counter = 0;
  int infNan = checkIfNanOrInf(valueStr, formatData, value);
  if (fabsl(value) >= 1.0 && infNan == 0) {
    while (floorl(fabsl(roundl(value * powl(10, formatData->precision + 1)) /
                        powl(10, formatData->precision + 1))) >= 10) {
      value = value / 10;
      exp_counter++;
    }
  } else if (value != 0 && infNan == 0) {
    while (fabsl(value) < 1) {
      value = value * 10;
      exp_counter--;
    }
  }
  if (infNan == 0) {
    floatToStr(valueStr, formatData, value);
    helperSpecG(valueStr, formatData); // for -g and -G
    if (s21_strchr("gG", formatData->specifier) != S21_NULL) {
      if (formatData->specifier == 'g') {
        formatData->specifier = 'e';
      } else {
        formatData->specifier = 'E';
      }
    }
    expToStr(valueStr, formatData, exp_counter, value);
  }
  flagMinusHendler(str, valueStr, formatData, value);
}

void expToStr(char *valueStr, struct FormatData *formatData, int exp_counter,
              long double value) {
  (void)value;
  while (*valueStr) {
    valueStr++;
  }
  char *start = valueStr;
  *valueStr = formatData->specifier;
  valueStr++;
  if (exp_counter < 0) {
    *valueStr = '-';
  } else {
    *valueStr = '+';
  }
  valueStr++;
  if (abs(exp_counter) < 10) {
    *valueStr = '0';
    valueStr++;
    if (exp_counter == 0) {
      *valueStr = '0';
      valueStr++;
    }
  }
  formatData->counter += valueStr - start;
  formatData->width -= valueStr - start;
  int i = 0;
  int coef = 1;
  if (exp_counter < 0) {
    coef *= -1;
  }
  int num = numberOfSymbolsInInt(exp_counter);
  i += num - 1;
  while (exp_counter != 0) {
    char ost = (exp_counter % 10) * coef + 48;
    valueStr[i] = ost;
    exp_counter /= 10;
    i--;
    formatData->counter++;
    formatData->width--;
  }
}

int writeFloat(char *str, struct FormatData *formatData, long double value) {
  char valueStr[1024] = {'\0'}; //число
  int infNan = checkIfNanOrInf(valueStr, formatData, value);
  if (infNan == 0) {
    floatToStr(valueStr, formatData, value);
    helperSpecG(valueStr, formatData); // for -g and -G
  }
  flagMinusHendler(str, valueStr, formatData, value);
  return 0;
}

void helperSpecG(char *valueStr, struct FormatData *formatData) {
  if (s21_strchr("gG", formatData->specifier) != S21_NULL) {
    remove_zero(valueStr, formatData);
  }
}

int checkIfNanOrInf(char *valueStr, struct FormatData *formatData,
                    long double value) {
  int flag = 0;
  if (fabsl(value) == INFINITY) {
    valueStr[0] = 'i';
    valueStr[1] = 'n';
    valueStr[2] = 'f';
    formatData->counter += 3;
    formatData->width -= 3;
    formatData->precision = 0;
    flag = 1;
  } else if (s21_isNan(value)) {
    valueStr[0] = 'n';
    valueStr[1] = 'a';
    valueStr[2] = 'n';

    formatData->counter += 3;
    formatData->width -= 3;
    formatData->precision = 0;
    flag = 1;
  }
  return flag;
}

int floatToStr(char *valueStr, struct FormatData *formatData,
               long double value) {
  long double buf = floorl(fabsl(value));
  if (value < 0) {
    buf = -buf;
  }
  long double right_side = value - buf;
  long long precision = 6;
  int flag = 1;
  if (formatData->has_precision != 0) {
    precision = formatData->precision;
    if (formatData->precision == 0) {
      formatData->has_precision = 0;
      buf = roundl(value);
      flag = 0;
    } else {
      buf = floorl(fabsl(roundl(value * powl(10, precision + 1)) /
                         powl(10, precision + 1)));
      if (value < 0) {
        buf = -buf;
      }
    }
  }
  floatConverter(valueStr, buf, formatData);
  if (flag == 1) {
    putPoint(&valueStr, formatData);
    buf = decimalPartFloat(&valueStr, right_side, &precision, formatData);
    if (buf == 0) {
      for (int i = 0; i < precision; i++) {
        *valueStr = '0';
        formatData->counter++;
        formatData->width--;
        formatData->precision--;
        valueStr++;
      }
    } else {
      floatConverter(valueStr, buf, formatData);
    }

  } else if (formatData->flags.grid == 1) {
    putPoint(&valueStr, formatData);
  }
  return 0;
}

void floatConverter(char *valueStr, long double value,
                    struct FormatData *formatData) {
  if (value == 0.0 &&
      (formatData->has_precision == 0 ||
       (formatData->has_precision && formatData->precision != 0))) {
    valueStr[0] = '0';
    formatData->precision--;
    formatData->counter++;
  } else {
    int i = 0;
    int coef = 1;
    if (value < 0.0) {
      coef *= -1;
    }
    int num = numberOfSymbolsInFloat(value);
    i += num - 1;
    formatData->precision -= num;

    while (fabsl(value) >= 1) {
      char ost = ((int)fmodl(value, 10)) * coef + 48;
      valueStr[i] = ost;
      value /= 10;
      i--;
      formatData->counter++;
    }
  }
  formatData->width -= s21_strlen(valueStr);
}

int numberOfSymbolsInFloat(long double value) {
  int num = 0;
  while (fabsl(value) >= 1) {
    num++;
    value /= 10;
  }
  return num;
}

long double decimalPartFloat(char **valueStr, long double right_side,
                             long long *precision,
                             struct FormatData *formatData) {
  long double res = fabsl(right_side) * powl(10, *precision);
  if (res != 0) {
    long double flag = fabsl(right_side) * 10;
    while (flag < 1 && (*precision)-- > 0) {
      flag = flag * 10;
      **valueStr = '0';
      (*valueStr)++;
      formatData->counter++;
      formatData->width--;
    }
  }
  if (numberOfSymbolsInFloat(roundl(res)) > numberOfSymbolsInFloat(res)) {
    res = 0;
  } else {
    res = roundl(res);
  }
  return res;
}

void putPoint(char **valueStr, struct FormatData *formatData) {
  while (**valueStr) {
    (*valueStr)++;
  }
  **valueStr = '.';
  (*valueStr)++;
  **valueStr = '\0';
  formatData->counter++;
  formatData->width--;
  formatData->precision--;
}

int processChar(char **str, va_list va, struct FormatData *formatData) {
  char c;
  if (formatData->specifier == '%') {
    c = '%';
  } else {
    c = va_arg(va, int);
  }
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
    setSpaces(*str, formatData);
    setZeroes(*str, formatData);
  } else {
    setSpaces(*str, formatData);
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

int setSpaces(char *str, struct FormatData *formatData) {
  if (formatData->flags.zero == 0 || formatData->flags.minus != 0) {
    while (formatData->width-- > 0) {
      s21_strcat(str, " ");
      formatData->counter++;
    }
  }
  return 0;
}

int setZeroes(char *str, struct FormatData *formatData) {
  if (formatData->flags.zero != 0 && formatData->flags.minus == 0) {
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
    if (formatData->width > (int)s21_strlen(s)) {
      formatData->width -= (int)s21_strlen(s);
    } else {
      formatData->width = 0;
    }
    formatData->counter = s21_strlen(s);
  } else {
    formatData->width -= formatData->precision;
    formatData->counter += formatData->precision;
  }

  if (formatData->flags.minus != 0) {
    s21_strncat(str, s, formatData->precision);
    setSpaces(str, formatData);
    setZeroes(str, formatData);
  } else {
    setSpaces(str, formatData);
    setZeroes(str, formatData);
    s21_strncat(str, s, formatData->precision);
  }
  return 0;
}

int processD(char *str, struct FormatData *formatData, va_list va) {
  long long value = 0;

  switch (formatData->length) {
  case 'h':
    value = (short int)va_arg(va, int);
    break;
  case '\0':
    value = (int)va_arg(va, int);
    break;
  case 'l':
    value = (long long)va_arg(va, long long int);
    break;
  default:
    break;
  }

  writeInt(str, formatData, value);
  return 0;
}

void flagMinusHendler(char *str, char *valueStr, struct FormatData *formatData,
                      long double value) {
  if (formatData->flags.minus != 0) {
    setSign(str, value, formatData);
    decreaseSignWidth(value, formatData);
    addZeroes(str, formatData);
    decreaseZeroesWidth(formatData);
    setZeroes(str, formatData);
    s21_strcat(str, valueStr);
    setSpaces(str, formatData);
  } else {
    decreaseSignWidth(value, formatData);
    decreaseZeroesWidth(formatData);
    setSpaces(str, formatData);
    setSign(str, value, formatData);
    addZeroes(str, formatData);
    setZeroes(str, formatData);
    s21_strcat(str, valueStr);
  }
}

int writeInt(char *str, struct FormatData *formatData, long long value) {
  char valueStr[1024] = {'\0'}; //число
  intToStr(valueStr, value, formatData);
  flagMinusHendler(str, valueStr, formatData, (long double)value);
  return 0;
}

int processUnsigned(char *str, struct FormatData *formatData, va_list va) {
  unsigned long long value = 0;
  switch (formatData->length) {
  case 'h':
    value = (short unsigned)va_arg(va, unsigned int);
    break;
  case '\0':
    value = (unsigned)va_arg(va, unsigned int);
    break;
  case 'l':
    value = (unsigned long)va_arg(va, unsigned long int);
    break;
  default:
    break;
  }
  switch (formatData->specifier) {
  case 'u':
    writeUnsigned(str, formatData, value);
    break;
  case 'x':
  case 'X':
    processX(str, formatData, value);
    break;
  case 'o':
    processO(str, formatData, value);
    break;
  }

  return 0;
}

int writeUnsigned(char *str, struct FormatData *formatData,
                  unsigned long long value) {
  char valueStr[1024] = {'\0'}; //число
  unsignedToStr(valueStr, value, formatData);
  flagMinusHendler(str, valueStr, formatData, (long double)value);
  return 0;
}

int unsignedToStr(char *valueStr, unsigned long long value,
                  struct FormatData *formatData) {
  if (value == 0 &&
      (formatData->has_precision == 0 ||
       (formatData->has_precision && formatData->precision != 0))) {
    valueStr[0] = '0';
    formatData->precision--;
    formatData->counter++;
  } else {
    int i = 0;
    int num = numberOfSymbolsInUnsigned(value);
    i += num - 1;
    formatData->precision -= num;

    while (value != 0) {
      char ost = (value % 10) + 48;
      valueStr[i] = ost;
      value /= 10;
      i--;
      formatData->counter++;
    }
  }
  formatData->width -= s21_strlen(valueStr);
  return 0;
}

int numberOfSymbolsInUnsigned(unsigned long long value) {
  int num = 0;
  while (value != 0) {
    num++;
    value /= 10;
  }
  return num;
}

int processN(va_list va, int res) {
  int *value = va_arg(va, int *);
  *value = res;
  return 0;
}

int processX(char *str, struct FormatData *formatData, unsigned long value) {
  char valueStr[1024] = {'\0'};
  decToHexOct(valueStr, value, formatData, 16);
  if (formatData->specifier == 'X') {
    upperStrX(valueStr);
  }
  int valueLen = s21_strlen(valueStr);
  formatData->precision -= valueLen;
  if (formatData->precision <= 0) {
    formatData->width -= valueLen;
  } else {
    formatData->width -= valueLen + formatData->precision;
  }
  formatData->counter += valueLen;
  if (formatData->flags.minus != 0) {
    handleSpacesPrefix(&str, formatData, value);
    addZeroes(str, formatData);
    setZeroes(str, formatData);
    s21_strcat(str, valueStr);
    setSpaces(str, formatData);
  } else {
    handleSpacesPrefix(&str, formatData, value);
    addZeroes(str, formatData);
    setZeroes(str, formatData);
    s21_strcat(str, valueStr);
  }
  return 0;
}

int processO(char *str, struct FormatData *formatData,
             unsigned long long value) {
  char valueStr[1024] = {'\0'};
  decToHexOct(valueStr, value, formatData, 8);
  int valueLen = s21_strlen(valueStr);
  formatData->precision -= valueLen;
  if (formatData->precision <= 0) {
    formatData->width -= valueLen;
  } else {
    formatData->width -= valueLen + formatData->precision;
  }
  formatData->counter += valueLen;
  if (formatData->flags.minus != 0) {
    handleSpacesPrefix(&str, formatData, value);
    addZeroes(str, formatData);
    setZeroes(str, formatData);
    s21_strcat(str, valueStr);
    setSpaces(str, formatData);
  } else {
    handleSpacesPrefix(&str, formatData, value);
    addZeroes(str, formatData);
    setZeroes(str, formatData);
    s21_strcat(str, valueStr);
  }
  return 0;
}
void handleSpacesPrefix(char **str, struct FormatData *formatData,
                        unsigned long long value) {
  if (formatData->specifier != 'o') {
    if (formatData->flags.minus != 0) {
      if (formatData->flags.grid == 1 && value != 0) {
        formatData->width -= 2;
        formatData->counter += 2;
        if (formatData->specifier == 'x') {
          s21_strcat(*str, "0x");
        } else {
          s21_strcat(*str, "0X");
        }
      }
    } else {
      if (formatData->flags.grid == 1 && value != 0) {
        formatData->width -= 2;
        formatData->counter += 2;
        setSpaces(*str, formatData);
        if (formatData->specifier == 'x') {
          s21_strcat(*str, "0x");
        } else {
          s21_strcat(*str, "0X");
        }
      } else {
        setSpaces(*str, formatData);
      }
    }
  } else {
    if (formatData->flags.minus != 0) {
      if (formatData->flags.grid == 1 && formatData->precision < 0 &&
          value != 0) {
        formatData->width--;
        formatData->counter++;
        // formatData->precision--;
        s21_strcat(*str, "0");
      }
    } else {
      if (formatData->flags.grid == 1 && value != 0) {
        setSpaces(*str, formatData);
        formatData->width--;
        formatData->counter++;
        formatData->precision--;
        s21_strcat(*str, "0");
      } else {
        setSpaces(*str, formatData);
      }
    }
  }
}

int processP(char *str, struct FormatData *formatData, va_list va) {
  char valueStr[1024] = {'\0'};
  long long unsigned int value =
      (long long unsigned int)va_arg(va, long long unsigned int);
  decToHexOct(valueStr, value, formatData, 16);
  int valueLen = s21_strlen(valueStr) + 2;
  formatData->precision -= valueLen - 2;
  if (formatData->precision <= 0) {
    formatData->width -= valueLen;
  } else {
    formatData->width -= valueLen + formatData->precision;
  }
  formatData->counter += valueLen;
  if (formatData->flags.minus != 0) {
    s21_strcat(str, "0x");
    addZeroes(str, formatData);
    s21_strcat(str, valueStr);
    setSpaces(str, formatData);
  } else {
    setSpaces(str, formatData);
    s21_strcat(str, "0x");
    addZeroes(str, formatData);
    s21_strcat(str, valueStr);
  }
  return 0;
}

int setSign(char *str, long double value, struct FormatData *formatData) {
  if (formatData->specifier != 'u') {
    if (value < 0) {
      s21_strcat(str, "-");
      formatData->counter++;
    } else if (formatData->flags.plus != 0) {
      s21_strcat(str, "+");
      formatData->counter++;
    } else if (formatData->flags.spase != 0) {
      s21_strcat(str, " ");
      formatData->counter++;
    }
  }
  return 0;
}

int decreaseSignWidth(long double value, struct FormatData *formatData) {
  if (formatData->specifier != 'u') {
    if (value < 0 || (formatData->flags.plus != 0 && value >= 0) ||
        formatData->flags.spase != 0) {
      formatData->width--;
    }
  }
  return 0;
}

int addZeroes(char *str, struct FormatData *formatData) {
  int buf = formatData->precision;
  const char ignore[] = "feEgG";
  while (buf-- > 0 && s21_strchr(ignore, formatData->specifier) == S21_NULL) {
    s21_strcat(str, "0");
    formatData->counter++;
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
  if (value == 0 &&
      (formatData->has_precision == 0 ||
       (formatData->has_precision && formatData->precision != 0))) {
    valueStr[0] = '0';
    formatData->precision--;
    formatData->counter++;
  } else {
    int i = 0;
    int coef = 1;
    if (value < 0) {
      coef *= -1;
    }
    int num = numberOfSymbolsInInt(value);
    i += num - 1;
    formatData->precision -= num;

    while (value != 0) {
      char ost = (value % 10) * coef + 48;
      valueStr[i] = ost;
      value /= 10;
      i--;
      formatData->counter++;
    }
  }
  formatData->width -= s21_strlen(valueStr);
  return 0;
}

int numberOfSymbolsInInt(long long int value) {
  int num = 0;
  while (value != 0) {
    num++;
    value /= 10;
  }
  return num;
}

int decToHexOct(char *valueStr, unsigned long long value,
                struct FormatData *formatData, int base) {
  const char pattern[17] = {"0123456789abcdef"};
  char tempStr[1024] = {'\0'};
  int i = 0;
  if (value == 0 &&
      ((formatData->has_precision == 1 && formatData->precision > 0) ||
       (formatData->has_precision == 0))) {
    int remainder = value % base;
    value = value / base;
    tempStr[i++] = pattern[remainder];
  } else if (value == 0 && formatData->specifier == 'o' &&
             ((formatData->has_precision == 1 && formatData->precision > 0) ||
              (formatData->has_precision == 0))) {
    tempStr[i++] = '0';
  }
  while (value != 0) {
    int remainder = value % base;
    value = value / base;
    tempStr[i++] = pattern[remainder];
  }
  i--;

  int k = 0;
  while (i >= 0) {
    valueStr[k++] = tempStr[i--];
  }
  return 0;
}

void upperStrX(char *valueStr) {
  for (s21_size_t i = 0; i < s21_strlen(valueStr); i++) {
    if (valueStr[i] >= 'a' && valueStr[i] <= 'z') {
      valueStr[i] -= 32;
    }
  }
}
