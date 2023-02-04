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
  int width;      // просто инт?
  int precision;  // просто инт?
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
int processSpecifier(char **str, struct FormatData *formatData, va_list va,
                     int res);
int processChar(char **str, va_list va, struct FormatData *formatData);
int processString(char *str, va_list va, struct FormatData *formatData);
int setSpaces(char *str, struct FormatData *formatData);
int processD(char *str, struct FormatData *formatData, va_list va);
int numberOfSymbolsInInt(long long int value);
int intToStr(char *valueStr, long long int value,
             struct FormatData *formatData);
int setSign(char *str, long double value, struct FormatData *formatData);
int addZeroes(char *str, struct FormatData *formatData);
int decreaseSignWidth(long double value, struct FormatData *formatData);
int decreaseZeroesWidth(struct FormatData *formatData);
int processUnsigned(char *str, struct FormatData *formatData, va_list va);
int processN(va_list va, int res);
int writeInt(char *str, struct FormatData *formatData, long long value);
int setZeroes(char *str, struct FormatData *formatData);
int processP(char *str, struct FormatData *formatData, va_list va);
int decToHexOct(char *valueStr, unsigned long long value,
                struct FormatData *formatData, int base);
int processFloat(char *str, struct FormatData *formatData, va_list va);
int floatToStr(char *valueStr, struct FormatData *formatData,
               long double value);
int writeFloat(char *str, struct FormatData *formatData, long double value);
void putPoint(char **valueStr, struct FormatData *formatData);
long double decimalPartFloat(char **valueStr, long double right_side,
                             long long *precision,
                             struct FormatData *formatData);
void floatConverter(char *valueStr, long double value,
                    struct FormatData *formatData);
int numberOfSymbolsInFloat(long double value);
int writeUnsigned(char *str, struct FormatData *formatData,
                  unsigned long long value);
int numberOfSymbolsInUnsigned(unsigned long long value);
int unsignedToStr(char *valueStr, unsigned long long value,
                  struct FormatData *formatData);
int processX(char *str, struct FormatData *formatData, unsigned long value);
void upperStrX(char *valueStr);
void handleSpacesPrefix(char **str, struct FormatData *formatData,
                        unsigned long long value);
int processO(char *str, struct FormatData *formatData,
             unsigned long long value);
void writeE_Value(char *str, struct FormatData *formatData, long double value);
void expToStr(char *valueStr, struct FormatData *formatData, int exp_counter,
              long double value);
void writeG_Value(char *str, struct FormatData *formatData, long double value);
void remove_zero(char *str, struct FormatData *formatData);
void helperSpecG(char *valueStr, struct FormatData *formatData);
int checkIfNanOrInf(char *valueStr, struct FormatData *formatData,
                    long double value);
void flagMinusHendler(char *str, char *valueStr, struct FormatData *formatData,
                      long double value);

#endif  //  SRC_HEADERS_S21_SPRINTF_H_
