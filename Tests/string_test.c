#include "test.h"

/*-----MEMCHR-----*/
START_TEST(memchr_empty_str) {
  s21_size_t size_str = 0;
  char str[10] = "";
  int find = '\0';

  ck_assert_ptr_eq(s21_memchr(str, find, size_str),
                   memchr(str, find, size_str));
}
END_TEST

START_TEST(memchr_find_zero_in_string) {
  s21_size_t size_str = 10;
  char str[10] = "find here";
  int find = '\0';

  ck_assert_ptr_eq(s21_memchr(str, find, size_str),
                   memchr(str, find, size_str));
}
END_TEST

START_TEST(memchr_find_space_in_str) {
  s21_size_t size_str = 10;
  char str[10] = "find here";
  int find = ' ';

  ck_assert_ptr_eq(s21_memchr(str, find, size_str),
                   memchr(str, find, size_str));
}
END_TEST

START_TEST(memchr_find_end_sym) {
  s21_size_t size_str = 10;
  char str[10] = "find herE";
  int find = 'E';

  ck_assert_ptr_eq(s21_memchr(str, find, size_str),
                   memchr(str, find, size_str));
}
END_TEST

START_TEST(memchr_find_dig_str) {
  s21_size_t size_str = 10;
  char str[10] = "find 5her";
  int find = 'E';

  ck_assert_ptr_eq(s21_memchr(str, find, size_str),
                   memchr(str, find, size_str));
}
END_TEST

START_TEST(memchr_find_int_array) {
  int array[] = {68, 76, 56, 4, 23, 64, 2};
  s21_size_t size_str = sizeof(int) * 7;
  int find = 64;

  ck_assert_ptr_eq(s21_memchr(array, find, size_str),
                   memchr(array, find, size_str));
}
END_TEST

START_TEST(memchr_find_fail) {
  int array[] = {68, 76, 56, 4, 23, 64, 2};
  s21_size_t size_str = sizeof(int) * 7;
  int find = 0;

  ck_assert_ptr_eq(s21_memchr(array, find, size_str),
                   memchr(array, find, size_str));
}
END_TEST

/*-----MEMCMP-----*/

START_TEST(memcmp_empty_str) {
  char str1[] = "";
  char str2[] = "";
  int n = 1;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_same_str) {
  char *str1 = "lol it's the same";
  char *str2 = str1;
  int n = 18;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_zero_size_same) {
  char str1[] = "compare";
  char str2[] = "compare";
  int n = 0;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_full_size_same) {
  char str1[] = "compare";
  char str2[] = "compare";
  int n = 7;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_full_size_diff_reg) {
  char str1[] = "compare";
  char str2[] = "COMPARE";
  int n = 7;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_zero_one_empty) {
  char str1[] = "";
  char str2[] = "compare";
  int n = 0;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_long_same) {
  char str1[] = "1234567890qwer\n\tTyUIoP[]AsdFghJkL;|Zxcvbnm,>/?";
  char str2[] = "1234567890qwer\n\tTyUIoP[]AsdFghJkL;|Zxcvbnm,>/?";
  int n = 44;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_long_diff) {
  char str1[] = "1234567890qwerTyUIoP[]AsdFghJkL;|Zxcvbnm,>/?";
  char str2[] = "1234567890qwerTyUIoP[]AsdFghJkL;|Ztwwxcvbnm,>/?";
  int n = 44;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

/*-----MEMCPY-----*/

START_TEST(memcpy_simple_test) {
  char copy[] = "simple copy";
  s21_size_t size = 12;
  char got[30];
  char must[30];

  s21_memcpy(got, copy, size);
  memcpy(must, copy, size);

  ck_assert_mem_eq(got, must, size);
}
END_TEST

START_TEST(memcpy_rewrite_copy) {
  char copy[] = "simple copy";
  s21_size_t size = 12;
  char got[30] = "Rewrite me pls";
  char must[30] = "Please me too";

  s21_memcpy(got, copy, size);
  memcpy(must, copy, size);

  ck_assert_mem_eq(got, must, size);
}
END_TEST

START_TEST(memcpy_copy_empty) {
  char copy[] = "";
  s21_size_t size = 1;
  char got[30] = "Rewrite me pls";
  char must[30] = "Please me too";

  s21_memcpy(got, copy, size);
  memcpy(must, copy, size);

  ck_assert_mem_eq(got, must, size);
}
END_TEST

START_TEST(memcpy_long_full_test) {
  char copy[] =
      "1234567890qwertyuiop[]asdfghjkl;zxcvbnm,./"
      "\n\tQWERTYUIOPASDFGHJKLZXCVBNM";
  s21_size_t size = 71;
  char got[100] = "Rewrite me pls";
  char must[100] = "Please me too";

  s21_memcpy(got, copy, size);
  memcpy(must, copy, size);

  ck_assert_mem_eq(got, must, size);
}
END_TEST

START_TEST(memcpy_long_with_zero) {
  char copy[] =
      "1234567890qwertyuiop[]asdfghjkl;zxcv\0bnm,./"
      "\n\tQWERTYUIOPASDFGHJ\0KLZXCVBNM";
  s21_size_t size = 73;
  char got[100] = "Rewrite me pls";
  char must[100] = "Please me too";

  s21_memcpy(got, copy, size);
  memcpy(must, copy, size);

  ck_assert_mem_eq(got, must, size);
}
END_TEST

/*-----MEMMOVE-----*/

START_TEST(memmove_simple_test) {
  char copy[] = "simple copy";
  s21_size_t size = 12;
  char got[30];
  char must[30];

  s21_memmove(got, copy, size);
  memmove(must, copy, size);

  ck_assert_mem_eq(got, must, size);
}
END_TEST

START_TEST(memmove_rewrite_copy) {
  char copy[] = "simple copy";
  s21_size_t size = 12;
  char got[30] = "Rewrite me pls";
  char must[30] = "Please me too";

  s21_memmove(got, copy, size);
  memmove(must, copy, size);

  ck_assert_mem_eq(got, must, size);
}
END_TEST

START_TEST(memmove_copy_empty) {
  char copy[] = "";
  s21_size_t size = 1;
  char got[30] = "Rewrite me pls";
  char must[30] = "Please me too";

  s21_memmove(got, copy, size);
  memmove(must, copy, size);

  ck_assert_mem_eq(got, must, size);
}
END_TEST

START_TEST(memmove_long_full_test) {
  char copy[] =
      "1234567890qwertyuiop[]\0asdfghjkl;zxcvbnm,./"
      "\n\tQWERTYUIOPASDFGHJ\0KLZXCVBNM";
  s21_size_t size = 73;
  char got[100] = "Rewrite me pls";
  char must[100] = "Please me too";

  s21_memmove(got, copy, size);
  memmove(must, copy, size);

  ck_assert_mem_eq(got, must, size);
}
END_TEST

START_TEST(memmove_overlap_test) {
  char copy1[] =
      "1234567890\0qwertyuiop[]asdfghjk\0l;zxcvbnm,./"
      "\n\tQWERTYUIOPASDFGHJKLZXCVBNM";
  char copy2[] =
      "1234567890\0qwertyuiop[]asdfghjk\0l;zxcvbnm,./"
      "\n\tQWERTYUIOPASDFGHJKLZXCVBNM";
  s21_size_t size = 24;
  char *got = copy1 + 9;
  char *must = copy2 + 9;

  s21_memmove(got, copy1, size);
  memmove(must, copy2, size);

  ck_assert_mem_eq(got, must, size);
}
END_TEST

START_TEST(memmove_int) {
  int copy[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_size_t size = 5;
  char got[6];
  char must[6];

  s21_memmove(got, copy, size);
  memmove(must, copy, size);

  ck_assert_mem_eq(got, must, size);
}
END_TEST

/*-----MEMSET-----*/

START_TEST(memset_null_simple_fill) {
  char symb = '\0';
  s21_size_t size = 6;
  char got[] = "String";
  char must[] = "String";

  s21_memset(got, symb, size);
  memset(must, symb, size);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(memset_char_simple_fill) {
  char symb = 'A';
  s21_size_t size = 5;
  char got[] = "String";
  char must[] = "String";

  s21_memset(got, symb, size);
  memset(must, symb, size);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(memset_char_diff_str_refill) {
  char symb = 'A';
  s21_size_t size = 29;
  char got[] = "replace me pls XDXDXDXDXDXDXD";
  char must[] = "I want to be replaced tooXDXD";

  s21_memset(got, symb, size);
  memset(must, symb, size);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(memset_char_partial_refill) {
  char symb = 'A';
  s21_size_t size = 9;
  char got[] = "Same line is here";
  char must[] = "Same line is here";

  s21_memset(got, symb, size);
  memset(must, symb, size);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(memset_zero_size) {
  char symb = 'A';
  s21_size_t size = 0;
  char got[] = "Same line is here";
  char must[] = "Same line is here";

  s21_memset(got, symb, size);
  memset(must, symb, size);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(memset_empty_str) {
  char symb = 'A';
  s21_size_t size = 0;
  char got[] = "";
  char must[] = "";

  s21_memset(got, symb, size);
  memset(must, symb, size);

  ck_assert_str_eq(got, must);
}
END_TEST

/*-----STRCAT-----*/

START_TEST(strcat_simple) {
  char cat[] = " World!";
  char got[5 + 8] = "Hello";
  char must[5 + 8] = "Hello";

  s21_strcat(got, cat);
  strcat(must, cat);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(strcat_empty_dest) {
  char cat[] = " World!";
  char got[8] = "";
  char must[8] = "";

  s21_strcat(got, cat);
  strcat(must, cat);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(strcat_empty_src) {
  char cat[] = "";
  char got[5 + 1] = "Hello";
  char must[5 + 1] = "Hello";

  s21_strcat(got, cat);
  strcat(must, cat);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(strcat_any_symb) {
  char cat[] =
      "123456789  qwertyuiop[]asdfghjkl;zxcvbnm,./\n\t\\ "
      "QWERTYUIOP{}ASDFGHJKL:ZXCVBNM<>?%\v";
  char got[5 + 82] = "Hello";
  char must[5 + 82] = "Hello";

  s21_strcat(got, cat);
  strcat(must, cat);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(strcat_empty_all) {
  char cat[] = "";
  char got[2] = "";
  char must[2] = "";

  s21_strcat(got, cat);
  strcat(must, cat);

  ck_assert_str_eq(got, must);
}
END_TEST

/*-----STRNCAT-----*/

START_TEST(strncat_empty_all) {
  char cat[] = "";
  char got[2] = "";
  char must[2] = "";

  s21_size_t size = 0;
  s21_strncat(got, cat, size);
  strncat(must, cat, size);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(strncat_simple) {
  char cat[] = " World!";
  char got[5 + 8] = "Hello";
  char must[5 + 8] = "Hello";

  s21_size_t size = 8;
  s21_strncat(got, cat, size);
  strncat(must, cat, size);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(strncat_empty_dest) {
  char cat[] = " World!";
  char got[8] = "";
  char must[8] = "";

  s21_size_t size = 8;
  s21_strncat(got, cat, size);
  strncat(must, cat, size);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(strncat_empty_src) {
  char cat[] = "";
  char got[5 + 1] = "Hello";
  char must[5 + 1] = "Hello";

  s21_size_t size = 1;
  s21_strncat(got, cat, size);
  strncat(must, cat, size);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(strncat_any_symb) {
  char cat[] =
      "123456789  qwertyuiop[]asdfghjkl;zxcvbnm,./\n\t\\ "
      "QWERTYUIOP{}ASDFGHJKL:ZXCVBNM<>?%\v";
  char got[5 + 82] = "Hello";
  char must[5 + 82] = "Hello";

  s21_size_t size = 82;
  s21_strncat(got, cat, size);
  strncat(must, cat, size);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(strncat_cat_some_symb) {
  char cat[] = " World!LMAOxd";
  char *got = calloc(100, sizeof(char));
  char *must = calloc(100, sizeof(char));
  for (s21_size_t size = 0; size < 13; size++) {
    s21_strncat(got, cat, size);
    strncat(must, cat, size);
    ck_assert_str_eq(got, must);
  }
  free(got);
  free(must);
}
END_TEST

/*-----STRCHR-----*/

START_TEST(strchr_simple) {
  char c = '1';
  char line[] = "find 1 here";

  ck_assert_str_eq(s21_strchr(line, c), strchr(line, c));
}
END_TEST

START_TEST(strchr_zero_term) {
  char c = '\0';
  char line[] = "find 1 here";

  ck_assert_str_eq(s21_strchr(line, c), strchr(line, c));
}
END_TEST

START_TEST(strchr_empty_zero) {
  char c = '\0';
  char line[] = "";

  ck_assert_str_eq(s21_strchr(line, c), strchr(line, c));
}
END_TEST

START_TEST(strchr_fail_find) {
  char c = 'L';
  char line[] = "I'm not hereXD";

  ck_assert_ptr_eq(s21_strchr(line, c), strchr(line, c));
}
END_TEST

START_TEST(strchr_multiple_occur) {
  char c = 'L';
  char line[] = "alllllllcoooholllLLLL XDXD";

  ck_assert_str_eq(s21_strchr(line, c), strchr(line, c));
}
END_TEST

START_TEST(strchr_lase_occur) {
  char c = '!';
  char line[] = "alllllllcoooholllLLLL XDXD!";

  ck_assert_str_eq(s21_strchr(line, c), strchr(line, c));
}
END_TEST

/*-----STRCMP-----*/

START_TEST(strcmp_simple) {
  char src1[] = "Same strings";
  char src2[] = "Same strings";

  int got = s21_strcmp(src1, src2);
  int must = strcmp(src1, src2);

  if (got > 0) got = 1;
  if (must > 0) must = 1;

  if (got < 0) got = -1;
  if (must < 0) must = -1;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(strcmp_diff) {
  char src1[] = "Same ztrings";
  char src2[] = "Same strings";

  int got = s21_strcmp(src1, src2);
  int must = strcmp(src1, src2);

  if (got > 0) got = 1;
  if (must > 0) must = 1;

  if (got < 0) got = -1;
  if (must < 0) must = -1;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(strcmp_capital) {
  char src1[] = "Same STRINGS";
  char src2[] = "Same strings";

  int got = s21_strcmp(src1, src2);
  int must = strcmp(src1, src2);

  if (got > 0) got = 1;
  if (must > 0) must = 1;

  if (got < 0) got = -1;
  if (must < 0) must = -1;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(strcmp_diff_size) {
  char src1[] = "Same strings but not";
  char src2[] = "Same strings";

  int got = s21_strcmp(src1, src2);
  int must = strcmp(src1, src2);

  if (got > 0) got = 1;
  if (must > 0) must = 1;

  if (got < 0) got = -1;
  if (must < 0) must = -1;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(strcmp_empty) {
  char src1[] = "";
  char src2[] = "";

  int got = s21_strcmp(src1, src2);
  int must = strcmp(src1, src2);

  if (got > 0) got = 1;
  if (must > 0) must = 1;

  if (got < 0) got = -1;
  if (must < 0) must = -1;

  ck_assert_int_eq(got, must);
}
END_TEST

/*-----STRNCMP-----*/

START_TEST(strncmp_simple) {
  char src1[] = "Same strings";
  char src2[] = "Same strings";
  s21_size_t size = 13;

  int got = s21_strncmp(src1, src2, size);
  int must = strncmp(src1, src2, size);

  if (got > 0) got = 1;
  if (must > 0) must = 1;

  if (got < 0) got = -1;
  if (must < 0) must = -1;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(strncmp_diff) {
  char src1[] = "Same ztrings";
  char src2[] = "Same strings";
  s21_size_t size = 8;

  int got = s21_strncmp(src1, src2, size);
  int must = strncmp(src1, src2, size);

  if (got > 0) got = 1;
  if (must > 0) must = 1;

  if (got < 0) got = -1;
  if (must < 0) must = -1;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(strncmp_skip) {
  char src1[] = "Same STRINGS";
  char src2[] = "Same strings";
  s21_size_t size = 5;

  int got = s21_strncmp(src1, src2, size);
  int must = strncmp(src1, src2, size);

  if (got > 0) got = 1;
  if (must > 0) must = 1;

  if (got < 0) got = -1;
  if (must < 0) must = -1;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(strncmp_diff_size) {
  char src1[] = "Same strings but not";
  char src2[] = "Same strings";
  s21_size_t size = 13;

  int got = s21_strncmp(src1, src2, size);
  int must = strncmp(src1, src2, size);

  if (got > 0) got = 1;
  if (must > 0) must = 1;

  if (got < 0) got = -1;
  if (must < 0) must = -1;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(strncmp_empty_zero) {
  char src1[] = "";
  char src2[] = "";
  s21_size_t size = 0;

  int got = s21_strncmp(src1, src2, size);
  int must = strncmp(src1, src2, size);

  if (got > 0) got = 1;
  if (must > 0) must = 1;

  if (got < 0) got = -1;
  if (must < 0) must = -1;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(strncmp_loop_check) {
  char src1[] = "Same string 1234 \n until Here";
  char src2[] = "Same string 1234 \n until blop";

  for (s21_size_t size = 0; size < 30; size++) {
    int got = s21_strncmp(src1, src2, size);
    int must = strncmp(src1, src2, size);

    if (got > 0) got = 1;
    if (must > 0) must = 1;

    if (got < 0) got = -1;
    if (must < 0) must = -1;

    ck_assert_int_eq(got, must);
  }
}
END_TEST

/*-----STRCPY-----*/

START_TEST(strcpy_simple_test) {
  char copy[] = "simple copy";
  char got[30];
  char must[30];

  s21_strcpy(got, copy);
  strcpy(must, copy);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(strcpy_rewrite_copy) {
  char copy[] = "simple copy";
  char got[30] = "Rewrite me pls";
  char must[30] = "Please me too";

  s21_strcpy(got, copy);
  strcpy(must, copy);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(strcpy_copy_empty) {
  char copy[] = "";
  char got[30] = "Rewrite me pls";
  char must[30] = "Please me too";

  s21_strcpy(got, copy);
  strcpy(must, copy);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(strcpy_long_full_test) {
  char copy[] =
      "1234567890qwertyuiop[]asdfghjkl;zxcvbnm,./"
      "\n\tQWERTYUIOPASDFGHJKLZXCVBNM";
  char got[100] = "Rewrite me pls";
  char must[100] = "Please me too";

  s21_strcpy(got, copy);
  strcpy(must, copy);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(strcpy_long_with_zero) {
  char copy[] =
      "1234567890qwertyuiop[]asdfghjkl;zxcv\0bnm,./"
      "\n\tQWERTYUIOPASDFGHJ\0KLZXCVBNM";
  char got[100] = "Rewrite me pls";
  char must[100] = "Please me too";

  s21_strcpy(got, copy);
  strcpy(must, copy);

  ck_assert_str_eq(got, must);
}
END_TEST

/*-----STRNCPY-----*/

START_TEST(strncpy_simple_test) {
  char copy[] = "simple copy";
  char got[30];
  char must[30];
  s21_size_t size = 12;

  s21_strncpy(got, copy, size);
  strncpy(must, copy, size);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(strncpy_rewrite_copy) {
  char copy[] = "simple copy";
  char got[30] = "Rewrite me pls";
  char must[30] = "Please me too";
  s21_size_t size = 12;

  s21_strncpy(got, copy, size);
  strncpy(must, copy, size);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(strncpy_copy_empty) {
  char copy[] = "";
  char got[30] = "Rewrite me pls";
  char must[30] = "Please me too";
  s21_size_t size = 1;

  s21_strncpy(got, copy, size);
  strncpy(must, copy, size);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(strncpy_all_empty) {
  char copy[] = "";
  char got[] = "";
  char must[] = "";
  s21_size_t size = 0;

  s21_strncpy(got, copy, size);
  strncpy(must, copy, size);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(strncpy_long_full_test) {
  char copy[] =
      "1234567890qwertyuiop[]asdfghjkl;zxcvbnm,./"
      "\n\tQWERTYUIOPASDFGHJKLZXCVBNM";
  char got[100] = "Rewrite me pls";
  char must[100] = "Please me too";
  s21_size_t size = 71;

  s21_strncpy(got, copy, size);
  strncpy(must, copy, size);

  ck_assert_str_eq(got, must);
}
END_TEST

START_TEST(strncpy_loop_check) {
  char copy[] =
      "1234567890qwertyuiop[]asdfghjkl;zxcv\0bnm,./"
      "\n\tQWERTYUIOPASDFGHJ\0KLZXCVBNM";
  char got[100] = "Rewrite me pls";
  char must[100] = "Rewrite me pls";
  for (s21_size_t size = 0; size < 71; size++) {
    s21_strncpy(got, copy, size);
    strncpy(must, copy, size);
    ck_assert_str_eq(got, must);
  }
}
END_TEST

/*-----STRCSPN-----*/

START_TEST(strcspn_empty) {
  char src[] = "";
  char exclude[] = "";

  ck_assert_int_eq(s21_strcspn(src, exclude), strcspn(src, exclude));
}
END_TEST

START_TEST(strcspn_src_empty) {
  char src[] = "";
  char exclude[] = "1234567890";

  ck_assert_int_eq(s21_strcspn(src, exclude), strcspn(src, exclude));
}
END_TEST

START_TEST(strcspn_exclude_empty) {
  char src[] = "1234567890";
  char exclude[] = "";

  ck_assert_int_eq(s21_strcspn(src, exclude), strcspn(src, exclude));
}
END_TEST

START_TEST(strcspn_simple) {
  char src[] = "Hello94";
  char exclude[] = "1234567890";

  ck_assert_int_eq(s21_strcspn(src, exclude), strcspn(src, exclude));
}
END_TEST

START_TEST(strcspn_capital) {
  char src[] = "HELLO BINGO";
  char exclude[] = "helobing";

  ck_assert_int_eq(s21_strcspn(src, exclude), strcspn(src, exclude));
}
END_TEST

START_TEST(strcspn_last_found) {
  char src[] = "HELLO BINGO sfsdgweeg ewrwe23 234 3143425345320";
  char exclude[] = "0";

  ck_assert_int_eq(s21_strcspn(src, exclude), strcspn(src, exclude));
}
END_TEST

/*-----STRERROR-----*/

START_TEST(strerror_test) {
  // 41 WTF
  for (int i = -200; i < 200; i++) {
    char *got = s21_strerror(i);
    char *must = strerror(i);
    ck_assert_str_eq(got, must);
  }
}
END_TEST

/*-----STRLEN-----*/

START_TEST(strlen_empty) {
  char src[] = "";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_simple) {
  char src[] = "Find len";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_specail_symb) {
  char src[] = "Find len\n\t\\here?";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_null_term) {
  char src[] = "Find l\0en\n\t\\here?";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

/*-----STRPBRK-----*/

START_TEST(strpbrk_empty) {
  char str[] = "";
  char find[] = "";

  ck_assert_pstr_eq(s21_strpbrk(str, find), strpbrk(str, find));
}
END_TEST

START_TEST(strpbrk_str_empty) {
  char str[] = "";
  char find[] = "1";

  ck_assert_pstr_eq(s21_strpbrk(str, find), strpbrk(str, find));
}
END_TEST

START_TEST(strpbrk_find_empty) {
  char str[] = "Find me if you can";
  char find[] = "";

  ck_assert_pstr_eq(s21_strpbrk(str, find), strpbrk(str, find));
}
END_TEST

START_TEST(strpbrk_find_digit) {
  char str[] = "Find me 1 if you can";
  char find[] = "1234564879";

  ck_assert_pstr_eq(s21_strpbrk(str, find), strpbrk(str, find));
}
END_TEST

START_TEST(strpbrk_same) {
  char str[] = "hello";
  char find[] = "hello";

  ck_assert_pstr_eq(s21_strpbrk(str, find), strpbrk(str, find));
}
END_TEST

START_TEST(strpbrk_capital) {
  char str[] = "hello";
  char find[] = "HELLO";

  ck_assert_pstr_eq(s21_strpbrk(str, find), strpbrk(str, find));
}
END_TEST

START_TEST(strpbrk_long) {
  char str[] = "Many different letters here try to find some";
  char find[] = "troll";

  ck_assert_pstr_eq(s21_strpbrk(str, find), strpbrk(str, find));
}

/*-----STRRCHR-----*/

START_TEST(strrchr_simple) {
  char c = 'e';
  char line[] = "find e here, can you?";

  ck_assert_ptr_eq(s21_strrchr(line, c), strrchr(line, c));
}
END_TEST

START_TEST(strrchr_zero_term) {
  char c = '\0';
  char line[] = "find 1 here";

  ck_assert_ptr_eq(s21_strrchr(line, c), strrchr(line, c));
}
END_TEST

START_TEST(strrchr_empty_zero) {
  char c = '\0';
  char line[] = "";

  ck_assert_ptr_eq(s21_strrchr(line, c), strrchr(line, c));
}
END_TEST

START_TEST(strrchr_fail_find) {
  char c = 'L';
  char line[] = "I'm not hereXD";

  ck_assert_ptr_eq(s21_strrchr(line, c), strrchr(line, c));
}
END_TEST

START_TEST(strrchr_multiple_occur) {
  char c = 'L';
  char line[] = "alllllllcoooholllLLLL XDLXD";

  ck_assert_ptr_eq(s21_strrchr(line, c), strrchr(line, c));
}
END_TEST

START_TEST(strrchr_first_occur) {
  char c = '!';
  char line[] = "!alllllllcoooholllLLLL XDXD";

  ck_assert_ptr_eq(s21_strrchr(line, c), strrchr(line, c));
}
END_TEST
/*-----STRSPN-----*/

START_TEST(strspn_empty) {
  char src[] = "";
  char exclude[] = "";

  ck_assert_int_eq(s21_strspn(src, exclude), strspn(src, exclude));
}
END_TEST

START_TEST(strspn_src_empty) {
  char src[] = "";
  char exclude[] = "1234567890";

  ck_assert_int_eq(s21_strspn(src, exclude), strspn(src, exclude));
}
END_TEST

START_TEST(strspn_exclude_empty) {
  char src[] = "1234567890";
  char exclude[] = "";

  ck_assert_int_eq(s21_strspn(src, exclude), strspn(src, exclude));
}
END_TEST

START_TEST(strspn_simple) {
  char src[] = "Hello94";
  char exclude[] = "Hello";

  ck_assert_int_eq(s21_strspn(src, exclude), strspn(src, exclude));
}
END_TEST

START_TEST(strspn_capital) {
  char src[] = "HELLO BINGO";
  char exclude[] = "helo bingo";

  ck_assert_int_eq(s21_strspn(src, exclude), strspn(src, exclude));
}
END_TEST

START_TEST(strspn_first_found) {
  char src[] = "HELLO BINGO sfsdgweeg ewrwe23 234 3143425345320";
  char exclude[] = "HELLO BINGO";

  ck_assert_int_eq(s21_strspn(src, exclude), strspn(src, exclude));
}
END_TEST

START_TEST(strspn_specail_found) {
  char src[] =
      "\nHE\tLL\\O \n BINGO \t\t\t\t\tsfsdgweeg ewrwe23 234 3143425345320";
  char exclude[] = "HELO BING\\\t\n";

  ck_assert_int_eq(s21_strspn(src, exclude), strspn(src, exclude));
}
END_TEST

/*-----STRSTR-----*/
START_TEST(strstr_empty) {
  char haystack[] = "";
  char needle[] = "";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_empty_haystack) {
  char haystack[] = "";
  char needle[] = "find";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_empty_needle) {
  char haystack[] = "find";
  char needle[] = "";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_empty_same) {
  char haystack[] = "find";
  char needle[] = "find";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_find_simple) {
  char haystack[] = "Can you Find the right finD word? this find looks fine";
  char needle[] = "find";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_repeat) {
  char haystack[] = "1111111";
  char needle[] = "1";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_fain) {
  char haystack[] = "1111111";
  char needle[] = "2525";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_needle_bigger) {
  char haystack[] = "1111111";
  char needle[] = "1111111111";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_needle_partial) {
  char haystack[] = "11234523---";
  char needle[] = "33---";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
/*-----STRTOK-----*/
START_TEST(strtok_all_empty) {
  char str1[] = "";
  char str2[] = "";
  char delim[] = "";
  char *token1 = strtok(str1, delim);
  char *token2 = s21_strtok(str2, delim);
  ck_assert_pstr_eq(token1, token2);
}
END_TEST

START_TEST(strtok_no_space_delim) {
  char str1[] = "This string - was created: to test, how good is strtok?!!!";
  char str2[] = "This string - was created: to test, how good is strtok?!!!";
  char delim[] = "-:,?";
  char *token1 = strtok(str1, delim);
  char *token2 = s21_strtok(str2, delim);
  ck_assert_pstr_eq(token1, token2);
  while (token1 != S21_NULL && token2 != S21_NULL) {
    ck_assert_str_eq(token1, token2);
    token1 = strtok(S21_NULL, delim);
    token2 = s21_strtok(S21_NULL, delim);
    ck_assert_pstr_eq(token1, token2);
  }
}
END_TEST

START_TEST(strtok_fail_find_delim) {
  char str1[] = "This string - was created: to test, how good is strtok?!!!";
  char str2[] = "This string - was created: to test, how good is strtok?!!!";
  char delim[] = "(;)";
  char *token1 = strtok(str1, delim);
  char *token2 = s21_strtok(str2, delim);
  ck_assert_pstr_eq(token1, token2);
  while (token1 != S21_NULL && token2 != S21_NULL) {
    ck_assert_str_eq(token1, token2);
    token1 = strtok(S21_NULL, delim);
    token2 = s21_strtok(S21_NULL, delim);
    ck_assert_pstr_eq(token1, token2);
  }
}
END_TEST

START_TEST(strtok_full_delim_str) {
  char str1[] = "111111111,.1,.1,.1,.1,.1,.1";
  char str2[] = "111111111,.1,.1,.1,.1,.1,.1";
  char delim[] = ",.1";
  char *token1 = strtok(str1, delim);
  char *token2 = s21_strtok(str2, delim);
  ck_assert_pstr_eq(token1, token2);
}
END_TEST

START_TEST(strtok_same_str) {
  char str1[] = "find";
  char str2[] = "find";
  char delim[] = "find";
  char *token1 = strtok(str1, delim);
  char *token2 = s21_strtok(str2, delim);
  ck_assert_pstr_eq(token1, token2);
}
END_TEST

START_TEST(strtok_same_str_but_space) {
  char str1[] = "find find find find find";
  char str2[] = "find find find find find";
  char delim[] = "find";
  char *token1 = strtok(str1, delim);
  char *token2 = s21_strtok(str2, delim);
  ck_assert_pstr_eq(token1, token2);
  while (token1 != S21_NULL && token2 != S21_NULL) {
    ck_assert_str_eq(token1, token2);
    token1 = strtok(S21_NULL, delim);
    token2 = s21_strtok(S21_NULL, delim);
    ck_assert_pstr_eq(token1, token2);
  }
}
END_TEST

START_TEST(strtok_no_delim) {
  char str1[] = "This string - was created: to test, how good is strtok?!!!";
  char str2[] = "This string - was created: to test, how good is strtok?!!!";
  char delim[] = "";
  char *token1 = strtok(str1, delim);
  char *token2 = s21_strtok(str2, delim);
  ck_assert_pstr_eq(token1, token2);
  while (token1 != S21_NULL && token2 != S21_NULL) {
    ck_assert_str_eq(token1, token2);
    token1 = strtok(S21_NULL, delim);
    token2 = s21_strtok(S21_NULL, delim);
    ck_assert_pstr_eq(token1, token2);
  }
}
END_TEST

START_TEST(strtok_main_test) {
  char str1[] = "This string - was created: to test, how good is strtok?!!!";
  char str2[] = "This string - was created: to test, how good is strtok?!!!";
  char delim[] = " -:,?";
  char *token1 = strtok(str1, delim);
  char *token2 = s21_strtok(str2, delim);
  ck_assert_pstr_eq(token1, token2);
  while (token1 != S21_NULL && token2 != S21_NULL) {
    ck_assert_str_eq(token1, token2);
    token1 = strtok(S21_NULL, delim);
    token2 = s21_strtok(S21_NULL, delim);
    ck_assert_pstr_eq(token1, token2);
  }
}
END_TEST

Suite *string_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("string_test");

  /* Core test case */
  tc = tcase_create("string_tc");
  // memchr
  tcase_add_test(tc, memchr_empty_str);
  tcase_add_test(tc, memchr_find_zero_in_string);
  tcase_add_test(tc, memchr_find_space_in_str);
  tcase_add_test(tc, memchr_find_end_sym);
  tcase_add_test(tc, memchr_find_dig_str);
  tcase_add_test(tc, memchr_find_int_array);
  tcase_add_test(tc, memchr_find_fail);

  // memcmp
  tcase_add_test(tc, memcmp_empty_str);
  tcase_add_test(tc, memcmp_same_str);
  tcase_add_test(tc, memcmp_zero_size_same);
  tcase_add_test(tc, memcmp_full_size_same);
  tcase_add_test(tc, memcmp_full_size_diff_reg);
  tcase_add_test(tc, memcmp_zero_one_empty);
  tcase_add_test(tc, memcmp_long_same);
  tcase_add_test(tc, memcmp_long_diff);

  // memcpy
  tcase_add_test(tc, memcpy_simple_test);
  tcase_add_test(tc, memcpy_rewrite_copy);
  tcase_add_test(tc, memcpy_copy_empty);
  tcase_add_test(tc, memcpy_long_full_test);
  tcase_add_test(tc, memcpy_long_with_zero);

  // memmove
  tcase_add_test(tc, memmove_simple_test);
  tcase_add_test(tc, memmove_rewrite_copy);
  tcase_add_test(tc, memmove_copy_empty);
  tcase_add_test(tc, memmove_long_full_test);
  tcase_add_test(tc, memmove_overlap_test);
  tcase_add_test(tc, memmove_int);

  // memset
  tcase_add_test(tc, memset_null_simple_fill);
  tcase_add_test(tc, memset_char_simple_fill);
  tcase_add_test(tc, memset_char_diff_str_refill);
  tcase_add_test(tc, memset_char_partial_refill);
  tcase_add_test(tc, memset_zero_size);
  tcase_add_test(tc, memset_empty_str);

  // strcat
  tcase_add_test(tc, strcat_simple);
  tcase_add_test(tc, strcat_empty_dest);
  tcase_add_test(tc, strcat_empty_src);
  tcase_add_test(tc, strcat_any_symb);
  tcase_add_test(tc, strcat_empty_all);

  // strncat
  tcase_add_test(tc, strncat_empty_all);
  tcase_add_test(tc, strncat_simple);
  tcase_add_test(tc, strncat_empty_dest);
  tcase_add_test(tc, strncat_empty_src);
  tcase_add_test(tc, strncat_any_symb);
  tcase_add_test(tc, strncat_cat_some_symb);

  // strchr
  tcase_add_test(tc, strchr_simple);
  tcase_add_test(tc, strchr_zero_term);
  tcase_add_test(tc, strchr_empty_zero);
  tcase_add_test(tc, strchr_fail_find);
  tcase_add_test(tc, strchr_multiple_occur);
  tcase_add_test(tc, strchr_lase_occur);

  // strcmp
  tcase_add_test(tc, strcmp_simple);
  tcase_add_test(tc, strcmp_diff);
  tcase_add_test(tc, strcmp_capital);
  tcase_add_test(tc, strcmp_diff_size);
  tcase_add_test(tc, strcmp_empty);

  // strncmp
  tcase_add_test(tc, strncmp_simple);
  tcase_add_test(tc, strncmp_diff);
  tcase_add_test(tc, strncmp_skip);
  tcase_add_test(tc, strncmp_diff_size);
  tcase_add_test(tc, strncmp_empty_zero);
  tcase_add_test(tc, strncmp_loop_check);

  // strcpy
  tcase_add_test(tc, strcpy_simple_test);
  tcase_add_test(tc, strcpy_rewrite_copy);
  tcase_add_test(tc, strcpy_copy_empty);
  tcase_add_test(tc, strcpy_long_full_test);
  tcase_add_test(tc, strcpy_long_with_zero);

  // strncpy
  tcase_add_test(tc, strncpy_simple_test);
  tcase_add_test(tc, strncpy_rewrite_copy);
  tcase_add_test(tc, strncpy_copy_empty);
  tcase_add_test(tc, strncpy_all_empty);
  tcase_add_test(tc, strncpy_long_full_test);
  tcase_add_test(tc, strncpy_loop_check);

  // strcspn
  tcase_add_test(tc, strcspn_empty);
  tcase_add_test(tc, strcspn_src_empty);
  tcase_add_test(tc, strcspn_exclude_empty);
  tcase_add_test(tc, strcspn_simple);
  tcase_add_test(tc, strcspn_capital);
  tcase_add_test(tc, strcspn_last_found);

  // strerror
  tcase_add_test(tc, strerror_test);

  // strlen
  tcase_add_test(tc, strlen_empty);
  tcase_add_test(tc, strlen_simple);
  tcase_add_test(tc, strlen_specail_symb);
  tcase_add_test(tc, strlen_null_term);

  // strpbrk
  tcase_add_test(tc, strpbrk_empty);
  tcase_add_test(tc, strpbrk_str_empty);
  tcase_add_test(tc, strpbrk_find_empty);
  tcase_add_test(tc, strpbrk_find_digit);
  tcase_add_test(tc, strpbrk_same);
  tcase_add_test(tc, strpbrk_capital);
  tcase_add_test(tc, strpbrk_long);

  // strrchr
  tcase_add_test(tc, strrchr_simple);
  tcase_add_test(tc, strrchr_zero_term);
  tcase_add_test(tc, strrchr_empty_zero);
  tcase_add_test(tc, strrchr_fail_find);
  tcase_add_test(tc, strrchr_multiple_occur);
  tcase_add_test(tc, strrchr_first_occur);

  // strspn
  tcase_add_test(tc, strspn_empty);
  tcase_add_test(tc, strspn_src_empty);
  tcase_add_test(tc, strspn_exclude_empty);
  tcase_add_test(tc, strspn_simple);
  tcase_add_test(tc, strspn_capital);
  tcase_add_test(tc, strspn_first_found);
  tcase_add_test(tc, strspn_specail_found);

  // strstr
  tcase_add_test(tc, strstr_empty);
  tcase_add_test(tc, strstr_empty_haystack);
  tcase_add_test(tc, strstr_empty_needle);
  tcase_add_test(tc, strstr_empty_same);
  tcase_add_test(tc, strstr_find_simple);
  tcase_add_test(tc, strstr_repeat);
  tcase_add_test(tc, strstr_fain);
  tcase_add_test(tc, strstr_needle_bigger);
  tcase_add_test(tc, strstr_needle_partial);

  // strtok

  tcase_add_test(tc, strtok_all_empty);
  tcase_add_test(tc, strtok_no_space_delim);
  tcase_add_test(tc, strtok_fail_find_delim);
  tcase_add_test(tc, strtok_full_delim_str);
  tcase_add_test(tc, strtok_same_str);
  tcase_add_test(tc, strtok_same_str_but_space);
  tcase_add_test(tc, strtok_no_delim);
  tcase_add_test(tc, strtok_main_test);

  suite_add_tcase(s, tc);

  return s;
}
