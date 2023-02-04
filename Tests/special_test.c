#include "test.h"

/*-----TO LOWER-----*/
START_TEST(to_lower_simple) {
  char str[] = "SIMPLE";
  char compare[] = "simple";
  char *got = s21_to_lower(str);
  ck_assert_pstr_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_mixed) {
  char str[] = "We aRe TrYiNG heRe TO GEt LOWER strIng";
  char compare[] = "we are trying here to get lower string";
  char *got = s21_to_lower(str);
  ck_assert_pstr_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_not_only_letters) {
  char str[] =
      "(LeTs Test, somE LinES***$ wiTh ADDITIONAL:: &12342 syMBOls 0 -+ )";
  char compare[] =
      "(lets test, some lines***$ with additional:: &12342 symbols 0 -+ )";
  char *got = s21_to_lower(str);
  ck_assert_pstr_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_empty) {
  char str[] = "";
  char compare[] = "";
  char *got = s21_to_lower(str);
  ck_assert_pstr_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_null) {
  char *str = S21_NULL;
  char *compare = S21_NULL;
  char *got = s21_to_lower(str);
  ck_assert_pstr_eq(got, compare);
  if (got) free(got);
}
END_TEST

/*-----TO UPPER-----*/
START_TEST(to_upper_simple) {
  char str[] = "simple";
  char compare[] = "SIMPLE";
  char *got = s21_to_upper(str);
  ck_assert_pstr_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_mixed) {
  char str[] = "We aRe TrYiNG heRe TO GEt upper strIng";
  char compare[] = "WE ARE TRYING HERE TO GET UPPER STRING";
  char *got = s21_to_upper(str);
  ck_assert_pstr_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_not_only_letters) {
  char str[] =
      "(LeTs Test, somE LinES***$ wiTh ADDITIONAL:: &12342 syMBOls 0 -+ )";
  char compare[] =
      "(LETS TEST, SOME LINES***$ WITH ADDITIONAL:: &12342 SYMBOLS 0 -+ )";
  char *got = s21_to_upper(str);
  ck_assert_pstr_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_empty) {
  char str[] = "";
  char compare[] = "";
  char *got = s21_to_upper(str);
  ck_assert_pstr_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_null) {
  char *str = S21_NULL;
  char *compare = S21_NULL;
  char *got = s21_to_upper(str);
  ck_assert_pstr_eq(got, compare);
  if (got) free(got);
}
END_TEST

/*-----INSERT-----*/
START_TEST(insert_null) {
  char *str = S21_NULL;
  char *insert = S21_NULL;
  s21_size_t start = 0;
  char *compare = S21_NULL;
  char *got = s21_insert(str, insert, start);
  ck_assert_pstr_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(insert_null_existing_str) {
  char str[] = "I'm alive!";
  char *insert = S21_NULL;
  s21_size_t start = 0;
  char *compare = "I'm alive!";
  char *got = s21_insert(str, insert, start);
  ck_assert_pstr_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(insert_empty_existing_str) {
  char str[] = "I'm alive!";
  char insert[] = "";
  s21_size_t start = 0;
  char *compare = "I'm alive!";
  char *got = s21_insert(str, insert, start);
  ck_assert_pstr_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(insert_simple_start) {
  char str[] = "World!";
  char insert[] = "Hello ";
  s21_size_t start = 0;
  char *compare = "Hello World!";
  char *got = s21_insert(str, insert, start);
  ck_assert_pstr_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(insert_simple_end) {
  char str[] = "Hello ";
  char insert[] = "World!";
  s21_size_t start = 6;
  char *compare = "Hello World!";
  char *got = s21_insert(str, insert, start);
  ck_assert_pstr_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(insert_middle) {
  char str[] = "Hello  World!";
  char insert[] = "Beautiful";
  s21_size_t start = 6;
  char *compare = "Hello Beautiful World!";
  char *got = s21_insert(str, insert, start);
  ck_assert_pstr_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(insert_start_empty) {
  char str[] = "";
  char insert[] = "Hello World!";
  s21_size_t start = 0;
  char *compare = "Hello World!";
  char *got = s21_insert(str, insert, start);
  ck_assert_pstr_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(insert_special_symb) {
  char str[] = "Hello\t  World!";
  char insert[] = "\nBeautiful\n";
  s21_size_t start = 7;
  char *compare = "Hello\t \nBeautiful\n World!";
  char *got = s21_insert(str, insert, start);
  ck_assert_pstr_eq(got, compare);
  if (got) free(got);
}
END_TEST

/*-----TRIM-----*/
START_TEST(trim_all_empty) {
  char str[] = "";
  char trim[] = "";
  char compare[] = "";
  char *got = s21_trim(str, trim);
  ck_assert_str_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(trim_simple_without_spec) {
  char str[] = "  trim until here  ";
  char trim[] = "";
  char compare[] = "trim until here";
  char *got = s21_trim(str, trim);
  ck_assert_str_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(trim_simple_spaces) {
  char str[] = "           trim until here          ";
  char trim[] = " ";
  char compare[] = "trim until here";
  char *got = s21_trim(str, trim);
  ck_assert_str_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(trim_spaces_and_not_special) {
  char str[] = "       \t\t    trim until here  \n        ";
  char trim[] = " ";
  char compare[] = "\t\t    trim until here  \n";
  char *got = s21_trim(str, trim);
  ck_assert_str_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(trim_without_spec_empty) {
  char str[] = "  \n\v     \t\t    trim until here  \n    \t\t\t\v    ";
  char trim[] = "";
  char compare[] = "trim until here";
  char *got = s21_trim(str, trim);
  ck_assert_str_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(trim_without_spec_null) {
  char str[] = "  \n\v     \t\t    trim until here  \n    \t\t\t\v    ";
  char *trim = S21_NULL;
  char compare[] = "trim until here";
  char *got = s21_trim(str, trim);
  ck_assert_str_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(trim_full_line) {
  char str[] = "lllllqqqqq";
  char *trim = "lq";
  char compare[] = "";
  char *got = s21_trim(str, trim);
  ck_assert_str_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(trim_chars) {
  char str[] = "trimimtrmtirmirtirm Only This Will Remain! tritrmtirmtirmtir";
  char *trim = "trim";
  char compare[] = " Only This Will Remain! ";
  char *got = s21_trim(str, trim);
  ck_assert_str_eq(got, compare);
  if (got) free(got);
}
END_TEST

START_TEST(trim_chars_and_ints) {
  char str[] =
      "123123trimimtrmtir3123mirtirm1Only This Will Remain!3"
      "tritrmt123irmtirmt33ir";
  char *trim = "trim123";
  char compare[] = "Only This Will Remain!";
  char *got = s21_trim(str, trim);
  ck_assert_str_eq(got, compare);
  if (got) free(got);
}
END_TEST

Suite *special_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("special_test");

  /* Core test case */
  tc = tcase_create("special_tc");

  // to lower
  tcase_add_test(tc, to_lower_simple);
  tcase_add_test(tc, to_lower_mixed);
  tcase_add_test(tc, to_lower_not_only_letters);
  tcase_add_test(tc, to_lower_empty);
  tcase_add_test(tc, to_lower_null);

  // to upper
  tcase_add_test(tc, to_upper_simple);
  tcase_add_test(tc, to_upper_mixed);
  tcase_add_test(tc, to_upper_not_only_letters);
  tcase_add_test(tc, to_upper_empty);
  tcase_add_test(tc, to_upper_null);

  // insert
  tcase_add_test(tc, insert_null);
  tcase_add_test(tc, insert_null_existing_str);
  tcase_add_test(tc, insert_empty_existing_str);
  tcase_add_test(tc, insert_simple_start);
  tcase_add_test(tc, insert_simple_end);
  tcase_add_test(tc, insert_middle);
  tcase_add_test(tc, insert_start_empty);
  tcase_add_test(tc, insert_special_symb);

  // trim
  tcase_add_test(tc, trim_all_empty);
  tcase_add_test(tc, trim_simple_without_spec);
  tcase_add_test(tc, trim_simple_spaces);
  tcase_add_test(tc, trim_spaces_and_not_special);
  tcase_add_test(tc, trim_without_spec_empty);
  tcase_add_test(tc, trim_without_spec_null);
  tcase_add_test(tc, trim_full_line);
  tcase_add_test(tc, trim_chars);
  tcase_add_test(tc, trim_chars_and_ints);

  suite_add_tcase(s, tc);

  return s;
}
