#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *pointer = str;
  void *res = s21_NULL;
  while ((pointer != s21_NULL) && ((n--) > 0)) {
    if (*pointer != (unsigned char)c) {
      pointer++;
    } else {
      res = (void *)pointer;
      break;
    }
  }
  return res;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *ch1 = str1;
  const unsigned char *ch2 = str2;
  int diff = 0;
  if (str1 == str2) {
    diff = 0;
  } else {
    while (n > 0) {
      n--;
      diff = *ch1++ - *ch2++;
      if (diff != 0) {
        break;
      }
    }
  }
  return diff;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *ch1 = dest;
  const unsigned char *ch2 = src;
  for (s21_size_t i = 0; i < n; i++) {
    ch1[i] = ch2[i];
  }
  return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  unsigned char *pntr1 = dest;
  const unsigned char *pntr2 = src;
  unsigned char temp_arr[n];
  for (s21_size_t i = 0; i < n; i++) {
    temp_arr[i] = pntr2[i];
  }
  for (s21_size_t i = 0; i < n; i++) {
    pntr1[i] = temp_arr[i];
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *pointer = str;
  while (n > 0) {
    n--;
    *pointer++ = (unsigned char)c;
  }
  return str;
}

char *s21_strcat(char *dest, const char *src) {
  char *pointer = dest;
  while (*pointer) {
    pointer++;
  }
  while (*src != '\0') {
    *pointer++ = *src++;
  }
  *pointer = *src;
  return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *pointer = dest;
  while (*pointer) {
    pointer++;
  }
  s21_size_t src_len = s21_strlen(src);
  for (s21_size_t i = 0; i < n; i++) {
    if (i == src_len) {
      break;
    }
    *pointer++ = src[i];
  }
  *pointer = '\0';
  return dest;
}

char *s21_strchr(const char *str, int c) {
  s21_size_t length_str = s21_strlen(str);
  char *pointer = s21_NULL;
  for (s21_size_t i = 0; i < length_str + 1; i++) {
    if (str[i] == c) {
      pointer = (char *)&str[i];
      break;
    }
  }
  return pointer;
}

int s21_strcmp(const char *str1, const char *str2) {
  s21_size_t i = 0;
  int diff = 0;
  while (str1[i] != '\0' || str2[i] != '\0') {
    diff = str1[i] - str2[i];
    if (diff != 0) {
      break;
    }
    i++;
  }
  return diff;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int diff = 0;
  for (s21_size_t i = 0; i < n; i++) {
    diff = str1[i] - str2[i];
    if (diff != 0) {
      break;
    }
  }
  return diff;
}

char *s21_strcpy(char *dest, const char *src) {
  char *pointer = dest;
  while (*src != '\0') {
    *pointer++ = *src++;
  }
  *pointer = *src;
  return dest;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *pointer = dest;
  s21_size_t src_len = s21_strlen(src);
  for (s21_size_t i = 0; i < n; i++) {
    if (i >= src_len) {
      pointer[i] = '\0';
    } else {
      pointer[i] = src[i];
    }
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  if ((str1 != s21_NULL) && (str2 != s21_NULL)) {
    while (*str1 != '\0') {
      if (s21_strchr(str2, *str1) != s21_NULL) {
        break;
      } else {
        str1++;
        len++;
      }
    }
  }
  return len;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t lenght = 0;
  if (str) {
    for (s21_size_t i = 0; str[i]; i++) {
      lenght++;
    }
  }
  return lenght;
}
char *s21_strpbrk(const char *str1, const char *str2) {
  char *pointer = s21_NULL;
  if ((str1 != s21_NULL) && (str2 != s21_NULL)) {
    while (*str1 != '\0') {
      if (s21_strchr(str2, *str1) != s21_NULL) {
        pointer = (char *)str1;
        break;
      } else {
        str1++;
      }
    }
  }
  return pointer;
}
char *s21_strrchr(const char *str, int c) {
  s21_size_t length_str = s21_strlen(str);
  char *pointer = s21_NULL;
  for (s21_size_t i = 0; i < length_str + 1; i++) {
    if (str[i] == c) {
      pointer = (char *)&str[i];
    }
  }
  return pointer;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  if ((str1 != s21_NULL) && (str2 != s21_NULL)) {
    while (*str1 != '\0') {
      if (s21_strchr(str2, *str1) == s21_NULL) {
        break;
      } else {
        str1++;
        len++;
      }
    }
  }
  return len;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *pointer = s21_NULL;
  s21_size_t needle_len = s21_strlen(needle);
  if (needle_len == 0) {
    pointer = (char *)haystack;
  }
  while (*haystack != '\0') {
    if ((*haystack == *needle) &&
        s21_strncmp(haystack, needle, needle_len) == 0) {
      pointer = (char *)haystack;
      break;
    }
    haystack++;
  }
  return pointer;
}

char *s21_strtok(char *str, const char *delim) {
  static char *index = s21_NULL;
  if (str != s21_NULL) {
    str += s21_strspn(str, delim);
    index = str;
  } else {
    if (*delim == '\0') {
      str = s21_NULL;
    } else {
      index += s21_strspn(index, delim);
      str = index;
    }
  }
  if (index != s21_NULL) {
    if (*index != '\0') {
      while (*index != '\0') {
        for (int i = 0; delim[i] != '\0'; i++) {
          if (*index == delim[i]) {
            if (index == str) {
              index++;
              str++;
            } else {
              *index = '\0';
              break;
            }
          }
        }
        if (*index == '\0') {
          if (*str == '\0') {
            str = s21_NULL;
          }
          index++;
          break;
        }
        index++;
      }
    } else {
      str = s21_NULL;
    }
  } else {
    str = s21_NULL;
  }
  return str;
}

int s21_atoi(char *str) {
  int res = 0;
  int coef = 1;
  str += s21_strspn(str, TRIM);
  if (*str == '+') {
    str++;
  }
  if (*str == '-') {
    coef = -1;
    str++;
  }
  while (*str >= '0' && *str <= '9') {
    res = res * 10 + *str++ - '0';
  }
  return res * coef;
}

long s21_atol(char *str) {
  long res = 0;
  int coef = 1;
  str += s21_strspn(str, TRIM);
  if (*str == '+') {
    str++;
  }
  if (*str == '-') {
    coef = -1;
    str++;
  }
  while (*str >= '0' && *str <= '9') {
    res = res * 10 + *str++ - '0';
  }
  return res * coef;
}
