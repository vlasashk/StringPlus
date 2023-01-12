#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *pointer = s21_NULL;
  s21_size_t len = s21_strlen(str);
  pointer = calloc((len + 1), sizeof(char));
  if (pointer != s21_NULL) {
    for (s21_size_t i = 0; i < len; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        pointer[i] = (char)(str[i] - 32);
      } else {
        pointer[i] = (char)(str[i]);
      }
    }
  }
  return pointer;
}

void *s21_to_lower(const char *str) {
  char *pointer = s21_NULL;
  s21_size_t len = s21_strlen(str);
  pointer = calloc((len + 1), sizeof(char));
  if (pointer != s21_NULL) {
    for (s21_size_t i = 0; i < len; i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        pointer[i] = (char)(str[i] + 32);
      } else {
        pointer[i] = (char)(str[i]);
      }
    }
  }
  return pointer;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *pointer = s21_NULL;
  if (src != s21_NULL) {
    if (str != s21_NULL) {
      s21_size_t src_len = s21_strlen(src);
      s21_size_t str_len = s21_strlen(str);
      s21_size_t new_len = src_len + str_len;
      if (start_index <= src_len) {
        pointer = calloc((new_len + 1), sizeof(char));
        if (pointer != s21_NULL) {
          for (s21_size_t i = 0; i < start_index; i++) {
            pointer[i] = src[i];
          }
          for (s21_size_t i = 0; i < str_len; i++) {
            pointer[i + start_index] = str[i];
          }
          for (s21_size_t i = start_index; i < src_len; i++) {
            pointer[i + str_len] = src[i];
          }
        }
      }
    } else {
      s21_size_t src_len = s21_strlen(src);
      pointer = calloc((src_len + 1), sizeof(char));
      if (pointer != s21_NULL) {
        s21_strcpy(pointer, src);
      }
    }
  }
  return pointer;
}
void *s21_trim(const char *src, const char *trim_chars) {
  char *pointer = s21_NULL;
  if (src != s21_NULL) {
    s21_size_t src_len = s21_strlen(src);
    if (trim_chars == s21_NULL || s21_strlen(trim_chars) == 0) {
      trim_chars = " \n\t\v\f\r";
    }
    s21_size_t trim_from_start = s21_strspn(src, trim_chars);
    s21_size_t trim_from_end = s21_strspn_reverse(src, trim_chars);
    s21_size_t new_len = src_len - trim_from_start - trim_from_end;
    if (src_len != trim_from_start) {
      pointer = calloc(new_len + 1, sizeof(char));
      if (pointer != s21_NULL) {
        for (s21_size_t i = 0; i < new_len; i++) {
          pointer[i] = src[i + trim_from_start];
        }
      }
    } else {
      pointer = calloc(1, sizeof(char));
    }
  }
  return pointer;
}

s21_size_t s21_strspn_reverse(const char *str1, const char *str2) {
  s21_size_t len = 0;
  if ((str1 != NULL) && (str2 != NULL)) {
    s21_size_t str1_len = s21_strlen(str1);
    s21_size_t str2_len = s21_strlen(str2);
    for (s21_size_t i = str1_len - 1;; i--) {
      int flag = 0;
      for (s21_size_t j = 0; j < str2_len; j++) {
        if (str1[i] == str2[j]) {
          flag = 1;
          break;
        }
      }
      if (flag != 0) {
        len++;
      } else {
        break;
      }
    }
  }
  return len;
}
