#ifndef SRC_HEADERS_S21_SPRINTF_H_
#define SRC_HEADERS_S21_SPRINTF_H_

#define BUFF_SIZE 4096

struct Flags {
  int plus;
  int minus;
  int spase;
  int grid;
  int zero;
};

struct FormatData {
  struct Flags flags;
  int counter;
  int width;     // просто инт?
  int precision; //просто инт?
  int has_precision;
  char length;
  char specifier;
};

int s21_sprintf(char *str, const char *format, ...);
int writeToStr(char *str, const char *format);
const char *formatParser(const char *format, struct FormatData *formatData,
                         int *flag, va_list va);
const char *getFlags(const char *format, struct FormatData *formatData);
const char *getWidth(const char *format, struct FormatData *formatData,
                     va_list va);
const char *getPrecision(const char *format, struct FormatData *formatData,
                         va_list va);
const char *getLength(const char *format, struct FormatData *formatData);
const char *getSpecifier(const char *format, struct FormatData *formatData,
                         int *flag);
int processSpecifier(char **str, struct FormatData *formatData, va_list va);
int processChar(char **str, va_list va, struct FormatData *formatData);
int processString(char *str, va_list va, struct FormatData *formatData);
int setSpaces(char **str, struct FormatData *formatData);
int processD(char *str, struct FormatData formatData, va_list va);
int NumberOfSymbolsInInt(long long int value);
int intToStr(char *valueStr, long long int value,
             struct FormatData *formatData);
int setSign(char *str, long long int value, struct FormatData formatData);
int addZeroes(char *str, struct FormatData formatData);
int decreaseSignWidth(long long int value, struct FormatData *formatData);
int decreaseZeroesWidth(struct FormatData *formatData);
int processU(char *str, struct FormatData formatData, va_list va);
int processN(char *str, va_list va);
int writeInt(char *str, struct FormatData *formatData, long long value);
int setZeroes(char *str, struct FormatData *formatData);
int processP(char *str, struct FormatData formatData, va_list va);
int DecToHex(char *valueStr, long long int value);
int processF(char **str, va_list va, struct FormatData *formatData);

#endif //  SRC_HEADERS_S21_SPRINTF_H_
