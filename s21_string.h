#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define ONE_PAGE 4096
#define s21_NULL ((void *)0)
typedef long unsigned s21_size_t;

void *s21_memchr(const void *str, int c, s21_size_t n); // DONE -- TEST
int s21_memcmp(const void *str1, const void *str2,
               s21_size_t n); // DONE -- TEST 1 0 -1 or...
void *s21_memcpy(void *dest, const void *src, s21_size_t n);  // DONE
void *s21_memmove(void *dest, const void *src, s21_size_t n); // DONE -- TEST
void *s21_memset(void *str, int c, s21_size_t n);             // DONE
char *s21_strcat(char *dest, const char *src);                // DONE
char *s21_strncat(char *dest, const char *src, s21_size_t n); // DONE
char *s21_strchr(const char *str, int c);                     // DONE
int s21_strcmp(const char *str1, const char *str2); // DONE -- TEST 1 0 -1 or...
int s21_strncmp(const char *str1, const char *str2,
                s21_size_t n);                 // DONE -- TEST 1 0 -1 or...
char *s21_strcpy(char *dest, const char *src); // DONE
char *s21_strncpy(char *dest, const char *src, s21_size_t n); // DONE
s21_size_t s21_strcspn(const char *str1,
                       const char *str2); // DONE test when NULL str
char *s21_strerror(int errnum);           // REPLACE sprintf to s21_sprintf
s21_size_t s21_strlen(const char *str);   // DONE
char *s21_strpbrk(const char *str1, const char *str2);      // DONE
char *s21_strrchr(const char *str, int c);                  // DONE
s21_size_t s21_strspn(const char *str1, const char *str2);  // DONE
char *s21_strstr(const char *haystack, const char *needle); // DONE -- TEST
char *s21_strtok(char *str, const char *delim);             // WTF NEEDS CHECK

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
s21_size_t s21_strspn_reverse(const char *str1, const char *str2);
int s21_atoi(char *str);
long s21_atol(char *str);

#include "Headers/s21_sprintf.h"
#include "Headers/s21_sscanf.h"

#endif //  SRC_S21_STRING_H_
