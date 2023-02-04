#include "test.h"

START_TEST(simple_int) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%c Test %c Test %c Test %c Test %c";
  int a = 65;
  int b = 66;
  int c = 67;
  int d = 68;
  int e = 69;
  int res1 = s21_sprintf(str1, format, a, b, c, d, e);
  int res2 = sprintf(str2, format, a, b, c, d, e);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_c_check) {
  char str1[5100];
  char str[5100];

  sprintf(str, "%11c %c", 'A', 'b');
  s21_sprintf(str1, "%11c %c", 'A', 'b');
  ck_assert_str_eq(str, str1);
  sprintf(str, "%c %97c", 'n', 'j');
  s21_sprintf(str1, "%c %97c", 'n', 'j');
  ck_assert_str_eq(str, str1);
  sprintf(str, "%-c %-3c", 'j', 'z');
  s21_sprintf(str1, "%-c %-3c", 'j', 'z');
  ck_assert_str_eq(str, str1);
  sprintf(str, "%-c %-3c %c %c %c %c", 'j', 'z', 'z', 'z', 'z', 'z');
  s21_sprintf(str1, "%-c %-3c %c %c %c %c", 'j', 'z', 'z', 'z', 'z', 'z');
  ck_assert_str_eq(str, str1);
  sprintf(str, "%c", 'A');
  s21_sprintf(str1, "%c", 'A');
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_1_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = 9;
  int b = 10;
  int c = 17;
  int d = 66;
  int e = 124;
  int res1 = s21_sprintf(str1, str3, a, b, c, d, e);
  int res2 = sprintf(str2, str3, a, b, c, d, e);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_2_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = -6;
  int b = -10;
  int c = -17;
  int d = -66;
  int e = -124;
  int res1 = s21_sprintf(str1, str3, a, b, c, d, e);
  int res2 = sprintf(str2, str3, a, b, c, d, e);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_4_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = 60;
  int b = 50;
  int c = 1744;
  int d = 386;
  int e = 257;

  int res1 = s21_sprintf(str1, str3, a, b, c, d, e);
  int res2 = sprintf(str2, str3, a, b, c, d, e);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_5_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  char a = 0;

  int res1 = s21_sprintf(str1, str3, a, a, a, a, a);
  int res2 = sprintf(str2, str3, a, a, a, a, a);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_11_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%#c Test %#c Test %#c Test %#c Test %#c";

  int res1 = s21_sprintf(str1, str3, ' ', 'n', '5', '%', '\\');
  int res2 = sprintf(str2, str3, ' ', 'n', '5', '%', '\\');
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_12_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int res1 = s21_sprintf(str1, str3, '\n', '\0', '\0', '\0', 'c');
  int res2 = sprintf(str2, str3, '\n', '\0', '\0', '\0', 'c');
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_13_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";

  int res1 = s21_sprintf(str1, str3, 'b', '4', '#', '@', '\0');
  int res2 = sprintf(str2, str3, 'b', '4', '#', '@', '\0');
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_14_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int res1 = s21_sprintf(str1, str3, 'Y', 'G', 123, '\0', 'J');
  int res2 = sprintf(str2, str3, 'Y', 'G', 123, '\0', 'J');
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_15_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%.7c Test %-7c Test %-50c Test % 54c Test %0188c";
  int a = 112;
  int res1 = s21_sprintf(str1, str3, a, a, a, a, a);
  int res2 = sprintf(str2, str3, a, a, a, a, a);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_16_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%.7c Test % -.7c Test %- 050c Test %- 54c Test %-0188c";
  int a = 45;
  int res1 = s21_sprintf(str1, str3, a, a, a, a, a);
  int res2 = sprintf(str2, str3, a, a, a, a, a);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_17_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%70c Test %-90c Test %080c Test %-065c Test %- 60c";
  int a = 255;
  int res1 = s21_sprintf(str1, str3, a, a, a, a, a);
  int res2 = sprintf(str2, str3, a, a, a, a, a);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_1_string) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %s Test";
  char *val = "Why am I here?!";
  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Three string parameters
START_TEST(sprintf_2_string) {
  char str1[100];
  char str2[100];
  char *str3 = "%s Test %s Test %s";
  char *val = "I'm so tired";
  char *val2 = "Who invented this?";
  char *val3 = "This project gave me hemmoroids";
  int res1 = s21_sprintf(str1, str3, val, val2, val3);
  int res2 = sprintf(str2, str3, val, val2, val3);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_string) {
  char str1[100];
  char str2[100];
  char *str3 = "%s Test %s Test %s";
  char *val = "Don't need this test";
  char *val2 = "Just for the kicks";
  char *val3 = "Lol";
  int res1 = s21_sprintf(str1, str3, val, val2, val3);
  int res2 = sprintf(str2, str3, val, val2, val3);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Different width
START_TEST(sprintf_5_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%3s Test %5s Test %10s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore";
  char *val3 = "PPAP";

  int res1 = s21_sprintf(str1, str3, val, val2, val3);
  int res2 = sprintf(str2, str3, val, val2, val3);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_6_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5s Test %.23s Test %3.s TEST %.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";

  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5s Test %-.8s Test %-7s TEST %-.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";

  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Zeroes
START_TEST(sprintf_8_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%0s Test %0.s Test %0.0s TEST %0s GOD %.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";

  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Pluses
START_TEST(sprintf_9_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%+s Test %+3.s Test %5.7s TEST %10s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "abcd";
  char *val4 = "I don't feel so good";

  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// // Zero vals
// START_TEST(sprintf_10_string) {
//   char str1[200];
//   char str2[200];
//   char *str3 = "%s Test %3.s Test %5.7s TEST %10s %#s %-s %+s %.s % .s";
//   char *val = NULL;

//   int res1 =
//       s21_sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
//   int res2 = sprintf(str2, str3, val, val, val, val, val, val, val, val,
//   val);

//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// Spaces
START_TEST(sprintf_11_string) {
  char str1[200];
  char str2[200];
  char *str3 = "% s Test % 3.s Test % 5.7s TEST % 10s GOD %.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Plus
START_TEST(sprintf_12_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%+s Test %+3.s Test %+5.7s TEST %+10s GOD %+.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";

  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Hash
START_TEST(sprintf_13_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%#s Test %#3s Test %#5.7s TEST %#.7s Oof %#.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";

  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_14_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%0s Test %06s Test %05.7s TEST %0.7s Oof %0.s";
  char *val = "WHAT IS THIS";
  char *val2 = "idx";
  char *val3 = "PPAP";
  char *val4 = "I don't";
  char *val5 = "What is lovin'?!";
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Asterisk
START_TEST(sprintf_15_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%*s Test %-*s Test %*.*s TEST %.*s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;

  int res1 = s21_sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3,
                         ast5, val4);
  int res2 =
      sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_16_string) {
  char str1[100];
  char str2[100];
  char *str3 = "%s %s %s %07% %d";
  char *val = "This";
  char *val2 = "\0";
  int val3 = 65;
  char *val4 = "string";
  int res1 = s21_sprintf(str1, str3, val, val2, val4, val3);
  int res2 = sprintf(str2, str3, val, val2, val4, val3);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// START_TEST(sprintf_17_string) {
//   char str1[1024];
//   char str2[1024];
//   char *str3 =
//       "%0.0s %1.0s %2.0s %3.0s %5.0s %6.0s %7.0s %0.3s %0.7s %3.2s %3.7s
//       %7.3s";
//   char *val = NULL;

//   int res1 = s21_sprintf(str1, str3, val, val, val, val, val, val, val, val,
//                          val, val, val, val);
//   int res2 = sprintf(str2, str3, val, val, val, val, val, val, val, val, val,
//                      val, val, val);

//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// One parameter signed
START_TEST(sprintf_1_signed) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %d Test";
  int val = -12;
  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Three signed parameters
START_TEST(sprintf_2_signed) {
  char str1[100];
  char str2[100];
  char *str3 = "%d Test %d Test %d";
  int val = 012;
  int val2 = -017;
  int val3 = 07464;
  int res1 = s21_sprintf(str1, str3, val, val2, val3);
  int res2 = sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_signed) {
  char str1[100];
  char str2[100];
  char *str3 = "%d Test %d Test %d";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int res1 = s21_sprintf(str1, str3, val, val2, val3);
  int res2 = sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_signed) {
  char str1[100];
  char str2[100];
  char *str3 = "%ld Test %ld Test %hd GOD %hd";
  long int val = 3088675747373646;
  long val2 = 33030030303;
  short int val3 = 22600;
  short val4 = -120;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Different width
START_TEST(sprintf_5_signed) {
  char str1[100];
  char str2[100];
  char *str3 = "%3d Test %5d Test %10d";
  int val = -3015;
  int val2 = -11234;
  int val3 = -99;
  int res1 = s21_sprintf(str1, str3, val, val2, val3);
  int res2 = sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_6_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5d Test %.23d Test %3.d TEST %.d %.6d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -38;
  int val5 = -100;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5d Test %-.8d Test %-7d TEST %-.d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Zeroes
START_TEST(sprintf_8_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%0d Test %0.d Test %0.0d TEST %0d GOD %.d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  int val5 = -0123;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Pluses
START_TEST(sprintf_9_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%+d Test %+3.d Test %+5.7d TEST %+10d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Zero vals
START_TEST(sprintf_10_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%d Test %3.d Test %5.7d TEST %10d %#d %-d %+d %.d % .d";
  int val = 0;
  int res1 =
      s21_sprintf(str1, str3, val, val, val, val, val, val, val, val, val, val);
  int res2 = sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Spaces
START_TEST(sprintf_11_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "% d Test % 3.d Test % 5.7d TEST % 10d GOD %.d";
  int val = -32;
  int val2 = -8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -23;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Plus
START_TEST(sprintf_12_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%+d Test %+3.d Test %+5.7d TEST %+10d GOD %+.d";
  int val = -32;
  int val2 = -8899;
  int val3 = 91918;
  int val4 = -32311;
  int val5 = 3261;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Hash
START_TEST(sprintf_13_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%#d Test %#3d Test %#5.7d TEST %#.7d Oof %#.d";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = 32311;
  int val5 = -8894;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_14_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%0d Test %06d Test %05.7d TEST %0.7d Oof %0.d";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -8894;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Asterisk
START_TEST(sprintf_15_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%*d Test %-*d Test %*.*d TEST %.*d";
  int val = 32;
  int val2 = 8899;
  int val3 = -919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  int res1 = s21_sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3,
                         ast5, val4);
  int res2 =
      sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Simple extra test
START_TEST(sprintf_16_signed) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%d";
  int val = 12;
  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST
START_TEST(sprintf_17_signed) {
  char str1[1024] = "";
  char str2[1024] = "";
  int val = -75;
  sprintf(str2, "Hello %d %023d", val, val);  // нет нулей перед числом(бонус)
  s21_sprintf(str1, "Hello %d %023d", val, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_signed) {
  char str1[300];
  char str2[300];
  char *str3 = "%ld Test %ld Test %hd GOD %hd tt %d tt %d";
  long int val = LONG_MAX;
  long val2 = LONG_MIN;
  short int val3 = SHRT_MAX;
  short val4 = SHRT_MIN;
  int val5 = INT_MAX;
  int val6 = INT_MIN;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5, val6);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5, val6);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_19_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%- d Test %- 15d sdasda %- 15d sdsad %- d";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Different precision and width zeroes
START_TEST(sprintf_20_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5d Test %.23d Test %3.d TEST %.d %.6d";
  int val = -0;
  int val2 = -0;
  int val3 = 0;
  int val4 = 0;
  int val5 = 0;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// F OPT

START_TEST(sprintf_1_f) {
  char str1[200];
  char str2[200];
  char *str3 = "%f TEST %.f TEST %4f TEST %4.f TEST %5.10f!";
  double num = 76.756589367;
  int res1 = s21_sprintf(str1, str3, num, num, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_2_f) {
  char str1[200];
  char str2[200];
  char *str3 = "%f TEST %.f TEST %3f TEST %4.f TEST %5.10f!";
  double num = -76.756589367;
  int res1 = s21_sprintf(str1, str3, num, num, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_3_f) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lf\n%.Lf!";
  long double num_long = -76.756589;
  int res1 = s21_sprintf(str1, str3, num_long, num_long);
  int res2 = sprintf(str2, str3, num_long, num_long);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_4_f) {
  char str1[400];
  char str2[400];
  char *str3 = "%20.10f\n%20.15f\n%-20.5f!";
  double num = -76.756589;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_5_f) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lf\n%.Lf\n%+-#Lf\n%+#.Lf\n%-#.Lf!";
  long double num = 76.756589;
  int res1 = s21_sprintf(str1, str3, num, num, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_6_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %5f\ntest: %6.1f\ntest: %8.2f!";
  double num = 76.756589;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_7_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %10.5f\ntest: %12.4f!";
  double num = 76.756589;
  int res1 = s21_sprintf(str1, str3, num, num);
  int res2 = sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_8_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.1f\ntest: %16.2f\ntest: %18.3f!";
  double num = -7648938790.756589;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_9_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %10.4f\ntest: %25.5f!";
  double num = -7648938790.756589;
  int res1 = s21_sprintf(str1, str3, num, num);
  int res2 = sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_10_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+15.f\ntest: %+#16.f\ntest: %+#18.0f!";
  double num = 7648938790.756589;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_11_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 18.0f\ntest: %+10.f\ntest: %+25.f!";
  double num = 7648938790.756589;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_12_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-26.1f\ntest: %-18.0f\ntest: %#-10.f!";
  double num = 7648938790.756589;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_13_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-#15.f\ntest: %-+25.f!";
  double num = 7648938790.756589;
  int res1 = s21_sprintf(str1, str3, num, num);
  int res2 = sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_14_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-15.4f!\ntest: %-26.1f!\ntest: %-18.0f!";
  double num = -365289.3462865487;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_15_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %#-10.9f!\ntest: %-+25.15f!";
  double num = -365289.3462865487;
  int res1 = s21_sprintf(str1, str3, num, num);
  int res2 = sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_16_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13f!\ntest: %26.15f!";
  double num = -365289.34628654873789362746834;
  int res1 = s21_sprintf(str1, str3, num, num);
  int res2 = sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_17_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7f!\ntest: %10.15f!\ntest: %25.15f!";
  double num = -365289.34628654873789362746834;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_18_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13f!\ntest: %26.15f!";
  double num = 365289.34628654873789362746834;
  int res1 = s21_sprintf(str1, str3, num, num);
  int res2 = sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_19_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7f!\ntest: %10.15f!";
  double num = 365289.34628654873789362746834;
  int res1 = s21_sprintf(str1, str3, num, num);
  int res2 = sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_20_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %- 23.14f!\ntest: %+ 25.15f!";
  double num = 365289.34628654873789362746834;
  int res1 = s21_sprintf(str1, str3, num, num);
  int res2 = sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_21_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15f!\ntest: % -26f!\ntest: %- 18f!";
  double num = -365789.34;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_22_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 14f!\ntest: %+ 10f!\ntest: % +25f!";
  double num = -365789.34;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_23_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 14f!\ntest: % -27f!\ntest: %- 19f!";
  double num = 365789.34;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_24_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 16f!\ntest: %+ 44f!\ntest: % +35f!";
  double num = 365789.34;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_25_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %26Lf!\ntest: %18Lf!\ntest: %60Lf!";
  long double num = -3752765839673496.34;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_26_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15Lf!test: %100Lf!";
  long double num = -3752765839673496.34;
  int res1 = s21_sprintf(str1, str3, num, num);
  int res2 = sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_27_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %- 26Lf!\ntest: %+- 18Lf!\ntest: %60Lf!";
  long double num = 3752765839673496.34;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_28_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % +15Lf!test: %100Lf!";
  long double num = 3752765839673496.34;
  int res1 = s21_sprintf(str1, str3, num, num);
  int res2 = sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_30_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %020f!\ntest: %-020f!\ntest: %+025f!";
  double num = 837564.4753366;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_31_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-+ 025.5f!\ntest: %- 020.4f\ntest: %+ 016.6f!";
  double num = 837564.4753366;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_32_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %015f!\ntest: %-026f!\ntest: %+018f!";
  double num = -947.6785643;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_33_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 010.2f!\ntest: %- 025.7f\ntest: %+- 18.4f!";
  double num = -947.6785643;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_34_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15.1Lf!\ntest: % -26.15Lf!\ntest: %- 30.15Lf!";
  long double num = 278.723786;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_35_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 50.15Lf!\ntest: % +40.15Lf!";
  long double num = 278.723786;
  int res1 = s21_sprintf(str1, str3, num, num);
  int res2 = sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_36_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15.1Lf!\ntest: % -26.13Lf!\ntest: %- 30.8Lf!";
  long double num = -2358.367776967;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_37_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 50.14Lf!\ntest: % +40.14Lf!";
  long double num = -2358.367776967;
  int res1 = s21_sprintf(str1, str3, num, num);
  int res2 = sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_38_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = -9999.99999;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_39_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.10Lf!\ntest: %.6Lf!\ntest: %.Lf!";
  long double num = -9999.99999;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_40_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = 000000000000000.00000000000;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_41_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.6Lf!\ntest: %.Lf\ntest: %+ 0Lf!!";
  long double num = 000000000000000.00000000000;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_42_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = -635293201236310753.6495633;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_43_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 0Lf!\ntest: %.6Lf!\ntest: %.15Lf!";
  long double num = -635293201236310753.6495633;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_44_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = -236310753.6495633;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_45_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 0Lf!\ntest: %.6Lf!\ntest: %.15Lf!";
  long double num = -236310753.6495633;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_46_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = -9325781235683689988.;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_47_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 0Lf!\ntest: %.6Lf!\ntest: %.15Lf!";
  long double num = -9325781235683689988.;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_50_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %25.5Lf!\ntest: %Lf!\ntest: %-50Lf!";
  long double num = -9325781235683689988.;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_51_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 0Lf!\ntest: %060Lf!\ntest: %.15Lf!";
  long double num = -9325781235683689988.;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_52_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-+.1Lf!\ntest: %- .2Lf!\ntest: %-0.3Lf!";
  long double num = -0.999999;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_54_f) {
  char str1[400];
  char str2[400];
  char *str3 = "fshgkaljck% 10.12f hgsakul";
  double num = 0.235300;
  int res1 = s21_sprintf(str1, str3, num);
  int res2 = sprintf(str2, str3, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_55_f) {
  char str1[400];
  char str2[400];
  char *str3 = "%f";
  double num = 0.00000001;
  int res1 = s21_sprintf(str1, str3, num);
  int res2 = sprintf(str2, str3, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_56_f) {
  char str1[400];
  char str2[400];
  char *str3 = "%.5f %.5f %.5f %.5f";
  double num1 = -999.666;
  double num2 = 0.0001;
  double num3 = 666.999;
  double num4 = -100.001;
  int res1 = s21_sprintf(str1, str3, num1, num2, num3, num4);
  int res2 = sprintf(str2, str3, num1, num2, num3, num4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// One parameter unsigned
START_TEST(sprintf_1_unsigned) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %u Test";
  unsigned int val = 012;
  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Three unsigned parameters
START_TEST(sprintf_2_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "%u Test %u Test %u";
  unsigned int val = 012;
  unsigned int val2 = 017;
  unsigned int val3 = 07464;
  int res1 = s21_sprintf(str1, str3, val, val2, val3);
  int res2 = sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "%u Test %u Test %u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  int res1 = s21_sprintf(str1, str3, val, val2, val3);
  int res2 = sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "%lu Test %lu Test %hu GOD %hu";
  long unsigned int val = 3088675747373646;
  long unsigned val2 = 33030030303;
  unsigned short val3 = 22600;
  unsigned short val4 = 120;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Different width
START_TEST(sprintf_5_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "%3u Test %5u Test %10u";
  unsigned int val = 3015;
  unsigned int val2 = 01234;
  unsigned int val3 = 99;
  int res1 = s21_sprintf(str1, str3, val, val2, val3);
  int res2 = sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_6_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5u Test %.23u Test %3.u TEST %.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 38;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5u Test %-.8u Test %-7u TEST %-.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Zerues
START_TEST(sprintf_8_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%0u Test %0.u Test %0.0u TEST %0u GOD %.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  unsigned int val5 = 0123;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Pluses
START_TEST(sprintf_9_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%+u Test %+3.u Test %+5.7u TEST %+10u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Zeru vals
START_TEST(sprintf_10_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%u Test %3.u Test %5.7u TEST %10u %#u %-u %+u %.u % .u";
  unsigned int val = 0;
  int res1 =
      s21_sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  int res2 = sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Spaces
START_TEST(sprintf_11_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "% u Test % 3.u Test % 5.7u TEST % 10u GOD %.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 23;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Plus
START_TEST(sprintf_12_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%+u Test %+3.u Test %+5.7u TEST %+10u GOD %+.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 3261;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Hash
START_TEST(sprintf_13_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%#u Test %#3u Test %#5.7u TEST %#.7u Ouf %#.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 8894;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_14_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%0u Test %06u Test %05.7u TEST %0.7u Ouf %0.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 8894;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Asterisk
START_TEST(sprintf_15_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%*u Test %-*u Test %*.*u TEST %.*u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 919;
  unsigned int val4 = 32311;
  unsigned int ast = 2;
  unsigned int ast2 = 5;
  unsigned int ast3 = 4;
  unsigned int ast4 = 10;
  unsigned int ast5 = 7;
  int res1 = s21_sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3,
                         ast5, val4);
  int res2 =
      sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_16_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lu";
  unsigned long int val = ULONG_MAX;
  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_17_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%- u Test %- 15u sdasda %- 15u sdsad %- u";
  unsigned int val = -3231;
  unsigned int val2 = -3231;
  unsigned int val3 = 3231;
  unsigned int val4 = 3231;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// One parameter signed_i
START_TEST(sprintf_1_signed_i) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %d Test";
  int val = -12;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three signed_i parameters
START_TEST(sprintf_2_signed_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%d Test %d Test %d";
  int val = 012;
  int val2 = -017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_signed_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%i Test %i Test %i";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_signed_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%li Test %li Test %hi GOD %hi";
  long int val = 3088675747373646;
  signed long val2 = -125;
  short int val3 = -22600;
  short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_5_signed_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%3i Test %5i Test %10i";
  int val = -3015;
  int val2 = -11234;
  int val3 = -99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_6_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5i Test %.23i Test %3.i TEST %.i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5i Test %-.8i Test %-7i TEST %-.i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zeroes
START_TEST(sprintf_8_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%0i Test %0.i Test %0.0i TEST %0i GOD %.i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  int val5 = -0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_9_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%+i Test %+3.i Test %+5.7i TEST %+10i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zero vals
START_TEST(sprintf_10_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%i Test %3.i Test %5.7i TEST %10i %#i %-i %+i %.i % .i";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val,
                  val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_11_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "% i Test % 3.i Test % 5.7i TEST % 10i GOD %.i";
  int val = -32;
  int val2 = -8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Plus
START_TEST(sprintf_12_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%+i Test %+3.i Test %+5.7i TEST %+10i GOD %+.i";
  int val = -32;
  int val2 = -8899;
  int val3 = 91918;
  int val4 = -32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Hash
START_TEST(sprintf_13_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%#i Test %#3i Test %#5.7i TEST %#.7i Oof %#.i";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = 32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_14_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%0d Test %06i Test %05.7i TEST %0.7i Oof %0.i";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Asterisk
START_TEST(sprintf_15_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%*i Test %-*i Test %*.*i TEST %.*i";
  int val = 32;
  int val2 = 8899;
  int val3 = -919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Simple extra test
START_TEST(sprintf_16_signed_i) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%i";
  int val = 12;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%- i Test %- 15i sdasda %- 15i sdsad %- i";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// One parameter pointer
START_TEST(sprintf_1_pointer) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %p Test";
  char *val = "0p32";
  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Three pointer parameters
START_TEST(sprintf_2_pointer) {
  char str1[100];
  char str2[100];
  char *str3 = "%p Test %p Test %p";
  char *val = "0p7a4";
  char *val2 = "0p91ba123f";
  char *val3 = "0p3123";
  int res1 = s21_sprintf(str1, str3, val, val2, val3);
  int res2 = sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_pointer) {
  char str1[100];
  char str2[100];
  char *str3 = "%p Test %p Test %p";
  char *val = "0p3015";
  char *val2 = "0p712";
  char *val3 = "0p99";
  int res1 = s21_sprintf(str1, str3, val, val2, val3);
  int res2 = sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_pointer) {
  char str1[100];
  char str2[100];
  char *str3 = "%p Test %p Test %p GOD %p";
  long int *val = (void *)3088675747373646;
  long long int *val2 = (void *)33030030303;
  unsigned short int *val3 = (void *)22600;
  unsigned char *val4 = (void *)120;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Different width
START_TEST(sprintf_5_pointer) {
  char str1[100];
  char str2[100];
  char *str3 = "%3p Test %5p Test %12p";
  char *val = "3015";
  char *val2 = "01234";
  char *val3 = "99";
  int res1 = s21_sprintf(str1, str3, val, val2, val3);
  int res2 = sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_6_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5p Test %.23p Test %3.p TEST %.p";
  char *val = "3015";
  char *val2 = "712";
  char *val3 = "99";
  char *val4 = "38";
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5p Test %-.4p Test %-16p TEST %-.5p";
  char *val = "3015";
  char *val2 = "712";
  char *val3 = "99";
  char *val4 = "2939";
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Zeroes
START_TEST(sprintf_8_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%0p Test %0.p Test %0.0p TEST %0p GOD %.p";
  char *val = "3015";
  char *val2 = "712";
  char *val3 = "99";
  char *val4 = "2939";
  char *val5 = "0123";
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Pluses
START_TEST(sprintf_9_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%+p Test %+3.p Test %+5.7p TEST %+10p";
  char *val = "3015";
  char *val2 = "712";
  char *val3 = "99";
  char *val4 = "2939";
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Zero vals
START_TEST(sprintf_10_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%p Test %3.p Test %5.7p TEST %10p %#p %-p %+p %.p % .p";
  char *val = 0;
  int res1 =
      s21_sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  int res2 = sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Spaces
START_TEST(sprintf_11_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "% p Test % 3.p Test % 5.7p TEST % 10p GOD %.p";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "23";
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Plus
START_TEST(sprintf_12_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%+p Test %+3.p Test %+5.7p TEST %+10p GOD %+.p";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "3261";
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Hash
START_TEST(sprintf_13_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%#p Test %#3p Test %#5.7p TEST %#.7p Oof %#.p";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "8894";
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_14_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%0p Test %06p Test %05.7p TEST %0.7p Oof %0.p";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "8894";
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Asterisk
START_TEST(sprintf_15_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%*p Test %-*p Test %*.*p TEST %.*p Lololol %.*p";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "9193112312312";
  char *val4 = "32311";
  char *val5 = "WTF cmon";
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  int ast6 = 18;
  int res1 = s21_sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3,
                         ast5, val4, ast6, val5);
  int res2 = sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                     val4, ast6, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// One parameter hex
START_TEST(sprintf_1_hex) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %x Test";
  int val = 0x32;
  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Three hex parameters
START_TEST(sprintf_2_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%x Test %x Test %x";
  int val = 0x7a4;
  int val2 = 0x91ba123f;
  int val3 = 0x3123;
  int res1 = s21_sprintf(str1, str3, val, val2, val3);
  int res2 = sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%x Test %x Test %x";
  int val = 0x3015;
  int val2 = 0x712;
  int val3 = 0x99;
  int res1 = s21_sprintf(str1, str3, val, val2, val3);
  int res2 = sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%lx Test %lx Test %hx GOD %hx";
  long int val = 3088675747373646;
  long val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Different width
START_TEST(sprintf_5_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%3x Test %5x Test %10x";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  int res1 = s21_sprintf(str1, str3, val, val2, val3);
  int res2 = sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_6_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5x Test %.23x Test %3.x TEST %.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5x Test %-.8x Test %-7x TEST %-.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Zeroes
START_TEST(sprintf_8_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%0x Test %0.x Test %0.0x TEST %0x GOD %.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Pluses
START_TEST(sprintf_9_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%+x Test %+3.x Test %+5.7x TEST %+10x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Zero vals
START_TEST(sprintf_10_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%x Test %3.x Test %5.7x TEST %10x %#x %-x %+x %.x % .x";
  int val = 0;
  int res1 =
      s21_sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  int res2 = sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Spaces
START_TEST(sprintf_11_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "% x Test % 3.x Test % 5.7x TEST % 10x GOD %.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Plus
START_TEST(sprintf_12_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%+x Test %+3.x Test %+5.7x TEST %+10x GOD %+.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Hash
START_TEST(sprintf_13_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%#x Test %#3x Test %#5.7x TEST %#.7x Oof %#.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_14_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%0x Test %06x Test %05.7x TEST %0.7x Oof %0.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Asterisk
START_TEST(sprintf_15_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%*x Test %-*x Test %*.*x TEST %.*x";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  int res1 = s21_sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3,
                         ast5, val4);
  int res2 =
      sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_16_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%- x Test %- 15x sdasda %- 15x sdsad %- x";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_17_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lx";
  long int val = ULONG_MAX;
  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// ZERO flag neg
START_TEST(sprintf_18_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%0x Test %06x Test %05.7x TEST %0.7x Oof %0.x";
  int val = -32;
  int val2 = -8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -8894;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_19_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5x Test %#20x Test %-7x TEST %#- .x";
  int val = 301516816;
  int val2 = 7121656;
  int val3 = 99469351;
  int val4 = 2939146;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4);
  int res2 = sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// One parameter HEX
START_TEST(sprintf_1_HEX) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %X Test";
  int val = 0X32;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three HEX parameters
START_TEST(sprintf_2_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%X Test %X Test %X";
  int val = 0X7a4;
  int val2 = 0X9112312f;
  int val3 = 0X3123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%X Test %X Test %X";
  int val = 0X3015;
  int val2 = 0X712;
  int val3 = 0X99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%lX Test %lX Test %hX GOD %hX";
  unsigned long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_5_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%3X Test %5X Test %10X";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_6_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5X Test %.23X Test %3.X TEST %.X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5X Test %-.8X Test %-7X TEST %-.X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zeroes
START_TEST(sprintf_8_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%0X Test %0.X Test %0.0X TEST %0X GOD %.X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_9_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%+X Test %+3.X Test %+5.7X TEST %+10X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zero vals
START_TEST(sprintf_10_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%X Test %3.X Test %5.7X TEST %10X %#X %-X %+X %.X % .X";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_11_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "% X Test % 3.X Test % 5.7X TEST % 10X GOD %.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Plus
START_TEST(sprintf_12_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%+X Test %+3.X Test %+5.7X TEST %+10X GOD %+.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Hash
START_TEST(sprintf_13_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%#X Test %#3X Test %#5.7X TEST %#.7X Oof %#.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_14_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%0X Test %06X Test %05.7X TEST %0.7X Oof %0.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Asterisk
START_TEST(sprintf_15_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%*X Test %-*X Test %*.*X TEST %.*X";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%- X Test %- 15X sdasda %- 15X sdsad %- X";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Hash neg
START_TEST(sprintf_17_HEX) {
  char str1[200];
  char str2[200];
  char *str3 =
      "%-#21.20X Test %-#21.20X Test %-#15.17X TEST %-#14.10X Oof %-#21.20X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// One parameter octal
START_TEST(sprintf_1_octal) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %o Test";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three octal parameters
START_TEST(sprintf_2_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  int val = 012;
  int val2 = 017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%lo Test %lo Test %ho GOD %ho";
  long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_5_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%3o Test %5o Test %10o";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_6_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5o Test %.23o Test %3.o TEST %.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5o Test %-.8o Test %-7o TEST %-.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zeroes
START_TEST(sprintf_8_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Test %0.o Test %0.0o TEST %0o GOD %.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_9_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o Test %+3.o Test %+5.7o TEST %+10o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zero vals
START_TEST(sprintf_10_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%o Test %3.o Test %5.7o TEST %10o %#o %-o %+o %.o % .o";
  int val = 0;
  int res1 =
      s21_sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  int res2 = sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Spaces
START_TEST(sprintf_11_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "% o Test % 3.o Test % 5.7o TEST % 10o GOD %.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Plus
START_TEST(sprintf_12_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o Test %+3.o Test %+5.7o TEST %+10o GOD %+.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Hash
START_TEST(sprintf_13_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%#o Test %#3o Test %#5.7o TEST %#.7o Oof %#.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_14_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Test %06o Test %05.7o TEST %0.7o Oof %0.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Asterisk
START_TEST(sprintf_15_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%*o Test %-*o Test %*.*o TEST %.*o";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Simple extra test
START_TEST(sprintf_16_octal) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%o";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%- o Test %- 15o sdasda %- 15o sdsad %- o";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lo";
  long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Hash 2
START_TEST(sprintf_19_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%#o Test %#3.3o Test %#5.7o TEST %#30.15o Oof %#.40o";
  int val = 3453152;
  int val2 = -88199;
  int val3 = -919118;
  int val4 = 32311;
  int val5 = 881694;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Hash neg
START_TEST(sprintf_20_octal) {
  char str1[200];
  char str2[200];
  char *str3 =
      "%-#15o Test %-#49.3o Test %#-8.7o TEST %#-30.15o Oof %-#20.18o!";
  int val = 3453152;
  int val2 = -88199;
  int val3 = -919118;
  int val4 = 32311;
  int val5 = 881694;
  int res1 = s21_sprintf(str1, str3, val, val2, val3, val4, val5);
  int res2 = sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_1_e) {
  char str1[100];
  char str2[100];
  char *str3 = "%e Test %5e Test %5.e";
  double num = -764231539.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_e) {
  char str1[100];
  char str2[100];
  char *str3 = "%e\n%.e\n%4e\n%4.e\n%5.10e!";
  double num = -764231539.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_e) {
  char str1[100];
  char str2[100];
  char *str3 = "%#e\n%#.e\n%#5.e\n%#.0e\n%#0.0e!";
  double num = -665695342471359.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_e) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: %020e\nSecond test: %020.e!";
  double num = -5921563224775967.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: %010e\nForth test: %010.e!";
  double num = -5921563224775967.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Fifth test: %0.0e!";
  double num = -5921563224775967.;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_e) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: %020e\nSecond test: %020.e!";
  double num =
      -592156322477597777777777777777777777777777777777777777777777777777777777777777777777776.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: %010e\nForth test: %010.e\nFifth test: %0.0e!";
  double num =
      -592156322477597777777777777777777777777777777777777777777777777777777777777777777777776.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_e) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: %020e\nSecond test: %020.5e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: %020.4e\nForth test: %020.3e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Fifth test: %020.2e\nSixth test: %020.1e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Seventh test: %020.e\n Eighth test: %020.0e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_e) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: % 20e\nSecond test: % 20.5e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: % 20.4e\nForth test: % 20.3e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Fifth test: % 20.2e\nSixth test: % 20.1e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Seventh test: % 20.e\n Eighth test: % 20.0e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_e) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: % 31e\nSecond test: % 30.5e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: % 33.4e\nForth test: % 35.3e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Fifth test: % 36.2e\nSixth test: % 45.1e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Seventh test: % 64.e\n Eighth test: % 80.0e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_21_e) {
  char str1[300];
  char str2[300];
  double num1 = -89435776876.;
  double num2 = -894357768.76;
  char *str3 = "New test: %e\nSecond test: %e!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2),
                   s21_sprintf(str2, str3, num1, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_22_e) {
  char str1[300];
  char str2[300];
  double num3 = -89435.776876;
  double num4 = -0.89435776876;
  char *str3 = "Third test: %e\nForth test: %e\n!";
  ck_assert_int_eq(sprintf(str1, str3, num3, num4),
                   s21_sprintf(str2, str3, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_23_e) {
  char str1[300];
  char str2[300];
  double num1 = -.89435776876;
  double num2 = -.00089435776876;
  char *str3 = "New test: %e\nSecond test: %e!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2),
                   s21_sprintf(str2, str3, num1, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_24_e) {
  char str1[300];
  char str2[300];
  double num3 = -0.000000089435776876;
  double num4 = -0000000000000.89435776876;
  char *str3 = "Third test: %e\nForth test: %e\n!";
  ck_assert_int_eq(sprintf(str1, str3, num3, num4),
                   s21_sprintf(str2, str3, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_25_e) {
  char str1[300];
  char str2[300];
  double num1 = -.89435776876;
  double num2 = -.00089435776876;
  double num3 = -0.000000089435776876;
  double num4 = -0000000000000.89435776876;
  char *str3 = "test: %.E!\ntest: %#E!\ntest: %#.E!\ntest: %0.E!\n";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num3, num4),
                   s21_sprintf(str2, str3, num1, num2, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_26_e) {
  char str1[300];
  char str2[300];
  double num1 = -.3529373967;
  double num2 = -.0003529373967;
  double num3 = -0.00000003529373967;
  char *str3 = "test: % 013.E\ntest: %#4.9E\ntest: %016.2E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num3),
                   s21_sprintf(str2, str3, num1, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_27_e) {
  char str1[300];
  char str2[300];
  double num1 = -.3529373967;
  double num4 = -0000000000000.3529373967;
  char *str3 = "test: %20.E\ntest: %-20.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num4, num1),
                   s21_sprintf(str2, str3, num4, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_28_e) {
  char str1[300];
  char str2[300];
  double num1 = .3529373967;
  double num2 = .0003529373967;
  double num3 = 0.00000003529373967;
  char *str3 = "test: % 30.1E\ntest: % 30.E\ntest: %030.0E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num3),
                   s21_sprintf(str2, str3, num1, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_29_e) {
  char str1[300];
  char str2[300];
  double num1 = .3529373967;
  double num4 = 0000000000000.3529373967;
  char *str3 = "test: %066.E\ntest: %-20.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num4, num1),
                   s21_sprintf(str2, str3, num4, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_30_e) {
  char str1[300];
  char str2[300];
  double num1 = 53296575676899283734747273752737878257.;
  char *str3 = "test: %- 17.1E\ntest: % -17.1E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num1),
                   s21_sprintf(str2, str3, num1, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_31_e) {
  char str1[300];
  char str2[300];
  double num2 = -53296575676899283734747273752737878257.;
  char *str3 = "test: %# 10.2E\ntest: % #10.0E\ntest: %010.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num2, num2, num2),
                   s21_sprintf(str2, str3, num2, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_32_e) {
  char str1[600];
  char str2[600];
  double num1 = 1234567890000.0938217586;
  char *str3 = "test: %- 67.1E\ntest: % -67.1E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num1),
                   s21_sprintf(str2, str3, num1, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_33_e) {
  char str1[600];
  char str2[600];
  double num2 = -.12345678900000938217586;
  char *str3 = "test: %# 100.0E\ntest: % #100.0E\ntest: %0100.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num2, num2, num2),
                   s21_sprintf(str2, str3, num2, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_34_e) {
  char str1[1000];
  char str2[1000];
  double num1 = 1234567890000.0938217586;
  double num2 = -.12345678900000938217586;
  char *str3 = "test: % 070.10E\ntest: % -67.10E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2),
                   s21_sprintf(str2, str3, num1, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_35_e) {
  char str1[1000];
  char str2[1000];
  double num1 = -12345678900000938217586.;
  double num2 = .12345678900000938217586;
  char *str3 = "test: % 070.10E\ntest: % -67.10E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2),
                   s21_sprintf(str2, str3, num1, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_36_e) {
  char str1[600];
  char str2[600];
  double num1 = 53296575676899283734747273752737878257.;
  char *str3 = "test: % 10.1E\ntest: %- 10.1E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num1),
                   s21_sprintf(str2, str3, num1, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_37_e) {
  char str1[600];
  char str2[600];
  double num2 = 53296575676899283.734747273752737878257;
  char *str3 = "test: % -10.0E\ntest: %- 10.0E\ntest: % -10.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num2, num2, num2),
                   s21_sprintf(str2, str3, num2, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_38_e) {
  char str1[600];
  char str2[600];
  double num1 = .000000005329657567689928373474727375273787825732159676631957;
  double num2 = 53296575676899283.73474727375273787825732159676631957;
  char *str3 = "test: % 20E\ntest: %-20E\ntest: %+ 020.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num1),
                   s21_sprintf(str2, str3, num1, num2, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_39_e) {
  char str1[600];
  char str2[600];
  double num3 = 5329657567689928373474727375.273787825732159676631957;
  double num4 = 53296575676899283734747273752737878257.32159676631957;
  char *str3 = "test: %#20.E\ntest: %- 20E!";
  ck_assert_int_eq(sprintf(str1, str3, num3, num4),
                   s21_sprintf(str2, str3, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_40_e) {
  char str1[100];
  char str2[100];
  char *str3 = "%.e\n%.2e\n%.5E\n%.9E\n%.13E!";
  double num = -2599999999.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_41_e) {
  char str1[200];
  char str2[200];
  char *str3 = "%.Le\n%.2Le\n%.5Le\n%.9Le\n%.13LE!";
  long double num = -2599999999.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_42_e) {
  char str1[200];
  char str2[200];
  char *str3 = "%e\n%.e\n%.5e\n%.9e\n%.15E!";
  double num = 0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_43_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %20Le!\ntest: %Le!\ntest: %-10Le!";
  long double num =
      -93257812350000000000000000000683689988320616583292392563908359623906832590653989623.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_44_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %060Le!\ntest: %.14Le!";
  long double num =
      -93257812350000000000000000000683689988320616583292392563908359623906832590653989623.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_1_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = 76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%25.18g TEST\n%.6g TEST\n";
  double num = 838.65400000;
  double num1 = 640.783289182;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%.2g TEST\n%.3g TEST\n";
  double num = 838.65400000;
  double num1 = 640.783289182;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %#5.10g!";
  double num = 0.0000756589367;
  int res1 = s21_sprintf(str1, str3, num, num, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_6_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %#5.10g!";
  double num = -0.0000756589367;
  int res1 = s21_sprintf(str1, str3, num, num, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_7_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = 573429.56589367;
  int res1 = s21_sprintf(str1, str3, num, num, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_8_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.0g TEST %4.2g TEST %4.g TEST %5.10g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_g) {
  char str1[200];
  char str2[200];
  char *str3 = "test: %15.1g\ntest: %16.2g\ntest: %18.3g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_g) {
  char str1[200];
  char str2[200];
  char *str3 = "test: %10.4g\ntest: %25.5g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-#15.g\ntest: %-26.1g\ntest: %-18.0g!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %#-10.g\ntest: %-+25.g!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%6g TEST %.2g TEST %4.5g TEST %4.3g TEST %5.10g!";
  double num = -0.0000756589367;
  int res1 = s21_sprintf(str1, str3, num, num, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_14_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = 573429.56589367;
  int res1 = s21_sprintf(str1, str3, num, num, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_15_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lg\n%.Lg!";
  long double num_long = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num_long, num_long),
                   s21_sprintf(str2, str3, num_long, num_long));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%20.10g\n%20.15g\n%-20.5g!";
  double num = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lg\n%.Lg\n%+-#Lg\n%+#.Lg\n%-#.Lg!";
  long double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13g!\ntest: %26.15g!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7g!\ntest: %10.15g!\ntest: %25.15g!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13g!\ntest: %26.15g!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_21_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7g!\ntest: %10.15g!\ntest: %25.15g!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_22_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %020g!\ntest: %-020g!\ntest: %+025g!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_23_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-+ 025.5g!\ntest: %- 020.4g!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_24_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %020g!\ntest: %-020g!\ntest: %+025g!";
  double num = -837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_25_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-+ 025.5g!\ntest: %- 020.4g!";
  double num = -837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_26_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %015g!\ntest: %-026g!\ntest: %+018g!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_27_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 010.2g!\ntest: %- 025.7g!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_28_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15.1Lg!\ntest: % -26.15Lg!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_29_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %- 30.15Lg!\ntest: %+ 50.15Lg!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_30_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % +40.15Lg\ntest: % +-25.15Lg!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_31_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15.1Lg!\ntest: % -26.15Lg!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_32_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %- 30.13Lg!\ntest: %+ 50.15Lg!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_33_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % +40.15Lg!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_34_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lg!\ntest: %.2Lg!\ntest: %.3Lg!";
  long double num = 9999.999999;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_35_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.6Lg!\ntest: %.Lg!";
  long double num = 9999.999999;
  int res1 = s21_sprintf(str1, str3, num, num);
  int res2 = sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_36_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.g!\ntest: %.2g!\ntest: %.3g!";
  double num = 0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_37_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.10g!\ntest: %.6g!\ntest: %.g!";
  double num = 0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_38_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-20.13g!\ntest: %-25.7g!";
  double num = -4353.235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_39_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-.15g!\ntest: %-16g!\ntest: %- 13.5g!";
  double num = -4353.235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_40_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+20.13g!\ntest: %+25.7g!";
  double num = 0.00000235300;
  int res1 = s21_sprintf(str1, str3, num, num);
  int res2 = sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_41_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+.15g!\ntest: %+16g!\ntest: %+ 13.5g!";
  double num = 0.00000235300;
  int res1 = s21_sprintf(str1, str3, num, num, num);
  int res2 = sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_42_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.Lg!\ntest: %.2Lg!\ntest: %.3Lg!";
  long double num = 8236310759735201795485858585858447757573.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_43_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.12Lg!\ntest: %.6Lg!\ntest: %.9Lg!";
  long double num = 8236310759735201795485858585858447757573.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_44_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %Lg!\n";
  long double num = INFINITY;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_45_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %Lg!\ntest: %Lg!\n";
  long double num = NAN;
  long double num1 = 1.;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_46_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.0Lg!";
  long double num = 0.001203;
  int res1 = s21_sprintf(str1, str3, num);
  int res2 = sprintf(str2, str3, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_1_n) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %n Test";
  int valn1 = 0, valn2 = 0;
  ck_assert_int_eq(sprintf(str1, str3, &valn1),
                   s21_sprintf(str2, str3, &valn2));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(valn1, valn2);
}
END_TEST

START_TEST(sprintf_2_n) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %o T%nest %o%n";
  int val = 012;
  int val2 = 017;
  int valn1 = 0, valn2 = 0, valn3 = 0, valn4 = 0;
  ck_assert_int_eq(sprintf(str1, str3, val, &valn1, val2, &valn3),
                   s21_sprintf(str2, str3, val, &valn2, val2, &valn4));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(valn1, valn2);
  ck_assert_int_eq(valn3, valn4);
}
END_TEST

START_TEST(sprintf_3_n) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Te%-+#nst %o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int valn1 = 0, valn2 = 0;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, &valn1, val3),
                   s21_sprintf(str2, str3, val, val2, &valn2, val3));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(valn1, valn2);
}
END_TEST

START_TEST(sprintf_4_n) {
  char str1[100];
  char str2[100];
  char *str3 = "%lo Test %lo Test %ho%34.23n";
  long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  int valn1 = 0, valn2 = 0;

  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, (unsigned short)val3, &valn1),
      s21_sprintf(str2, str3, val, val2, (unsigned short)val3, &valn2));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(valn1, valn2);
}
END_TEST

START_TEST(sprintf_1_percent) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%%Test %o Test";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_percent) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %o Tes%%%%t %o";
  int val = 012;
  int val2 = 017;
  ck_assert_int_eq(sprintf(str1, str3, val, val2),
                   s21_sprintf(str2, str3, val, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_percent) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Te%%st %o Test %o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(e_precision_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = 0.000000000000000948;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_1_1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%1.1f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_huge_w) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%210s";

  ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                   sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_many_g) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG %g %G %Lg %.5g";
  long double hex = 0.000005;
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;
  int res1 = s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5);
  int res2 = sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_large_g) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG";
  long double hex = 0.000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_zero_prec_g) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.0g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf_hard_1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";
  int res1 = s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                         "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11);
  int res2 = sprintf(str2, format, 'f', 21, 42, 666.666,
                     "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_no_prec_g) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.123000;
  int res1 = s21_sprintf(str1, format, hex);
  int res2 = sprintf(str2, format, hex);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_many_hex_lower) {
  char str1[200];
  char str2[200];
  int res1 =
      s21_sprintf(str1, "%x %x %x %x %x", 12340987, 135, 0, -1230, -123213123);
  int res2 =
      sprintf(str2, "%x %x %x %x %x", 12340987, 135, 0, -1230, -123213123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_many_hex_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(
      s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_ast_grid_neg) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                           199, -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1, 199,
                           -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_hard_1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int a = s21_sprintf(
      str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
      4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
  int b = sprintf(str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x",
                  3, 126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9,
                  41, -41, 33);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_hard_1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X",
                  3, -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9,
                  41, -41, 33),
      sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
              -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
              -41, 33));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_lower_with_length) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  unsigned short val1 = -11;
  ck_assert_int_eq(s21_sprintf(str1, "%hx", val1), sprintf(str2, "%hx", val1));
  ck_assert_str_eq(str1, str2);
  unsigned short val2 = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%hx", val2), sprintf(str2, "%hx", val2));
  ck_assert_str_eq(str1, str2);
  unsigned short val3 = 11;
  ck_assert_int_eq(s21_sprintf(str1, "%hx", val3), sprintf(str2, "%hx", val3));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_length) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int res1 = s21_sprintf(str1, "%hx", -11);
  int res2 = sprintf(str2, "%hx", (unsigned short)-11);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);

  res1 = s21_sprintf(str1, "%hx", 0);
  res2 = sprintf(str2, "%hx", (unsigned short)0);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);

  res1 = s21_sprintf(str1, "%hx", 11);
  res2 = sprintf(str2, "%hx", (unsigned short)11);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);

  long unsigned int val = INT32_MAX;
  res1 = s21_sprintf(str1, "%lx", val);
  res2 = sprintf(str2, "%lx", val);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);

  long unsigned int v = 0;
  res1 = s21_sprintf(str1, "%lx", v);
  res2 = sprintf(str2, "%lx", v);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *sprintf_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("sprintf_test");

  /* Core test case */
  tc = tcase_create("sprintf_tc");

  // -c
  tcase_add_test(tc, simple_int);
  tcase_add_test(tc, sprintf_c_check);
  tcase_add_test(tc, sprintf_1_c);
  tcase_add_test(tc, sprintf_2_c);
  tcase_add_test(tc, sprintf_4_c);
  tcase_add_test(tc, sprintf_5_c);
  tcase_add_test(tc, sprintf_11_c);
  tcase_add_test(tc, sprintf_12_c);
  tcase_add_test(tc, sprintf_13_c);
  tcase_add_test(tc, sprintf_14_c);
  tcase_add_test(tc, sprintf_15_c);
  tcase_add_test(tc, sprintf_16_c);
  tcase_add_test(tc, sprintf_17_c);
  // -s
  tcase_add_test(tc, sprintf_1_string);
  tcase_add_test(tc, sprintf_2_string);
  tcase_add_test(tc, sprintf_3_string);
  tcase_add_test(tc, sprintf_5_string);
  tcase_add_test(tc, sprintf_6_string);
  tcase_add_test(tc, sprintf_7_string);
  tcase_add_test(tc, sprintf_8_string);
  tcase_add_test(tc, sprintf_9_string);
  // tcase_add_test(tc, sprintf_10_string);
  tcase_add_test(tc, sprintf_11_string);
  tcase_add_test(tc, sprintf_12_string);
  tcase_add_test(tc, sprintf_13_string);
  tcase_add_test(tc, sprintf_14_string);
  tcase_add_test(tc, sprintf_15_string);
  tcase_add_test(tc, sprintf_16_string);
  // tcase_add_test(tc, sprintf_17_string);

  // -d
  tcase_add_test(tc, sprintf_1_signed);
  tcase_add_test(tc, sprintf_2_signed);
  tcase_add_test(tc, sprintf_3_signed);
  tcase_add_test(tc, sprintf_4_signed);
  tcase_add_test(tc, sprintf_5_signed);
  tcase_add_test(tc, sprintf_6_signed);
  tcase_add_test(tc, sprintf_7_signed);
  tcase_add_test(tc, sprintf_8_signed);
  tcase_add_test(tc, sprintf_9_signed);
  tcase_add_test(tc, sprintf_10_signed);
  tcase_add_test(tc, sprintf_11_signed);
  tcase_add_test(tc, sprintf_12_signed);
  tcase_add_test(tc, sprintf_13_signed);
  tcase_add_test(tc, sprintf_14_signed);
  tcase_add_test(tc, sprintf_15_signed);
  tcase_add_test(tc, sprintf_16_signed);
  tcase_add_test(tc, sprintf_17_signed);
  tcase_add_test(tc, sprintf_18_signed);
  tcase_add_test(tc, sprintf_19_signed);
  tcase_add_test(tc, sprintf_20_signed);

  // -f
  tcase_add_test(tc, sprintf_1_f);
  tcase_add_test(tc, sprintf_2_f);
  tcase_add_test(tc, sprintf_3_f);
  tcase_add_test(tc, sprintf_4_f);
  tcase_add_test(tc, sprintf_5_f);
  tcase_add_test(tc, sprintf_6_f);
  tcase_add_test(tc, sprintf_7_f);
  tcase_add_test(tc, sprintf_8_f);
  tcase_add_test(tc, sprintf_9_f);
  tcase_add_test(tc, sprintf_10_f);
  tcase_add_test(tc, sprintf_11_f);
  tcase_add_test(tc, sprintf_12_f);
  tcase_add_test(tc, sprintf_13_f);
  tcase_add_test(tc, sprintf_14_f);
  tcase_add_test(tc, sprintf_15_f);
  tcase_add_test(tc, sprintf_16_f);
  tcase_add_test(tc, sprintf_17_f);
  tcase_add_test(tc, sprintf_18_f);
  tcase_add_test(tc, sprintf_19_f);
  tcase_add_test(tc, sprintf_20_f);
  tcase_add_test(tc, sprintf_21_f);
  tcase_add_test(tc, sprintf_22_f);
  tcase_add_test(tc, sprintf_23_f);
  tcase_add_test(tc, sprintf_24_f);
  tcase_add_test(tc, sprintf_25_f);
  tcase_add_test(tc, sprintf_26_f);
  tcase_add_test(tc, sprintf_27_f);
  tcase_add_test(tc, sprintf_28_f);
  tcase_add_test(tc, sprintf_30_f);
  tcase_add_test(tc, sprintf_31_f);
  tcase_add_test(tc, sprintf_32_f);
  tcase_add_test(tc, sprintf_33_f);
  tcase_add_test(tc, sprintf_34_f);
  tcase_add_test(tc, sprintf_35_f);
  tcase_add_test(tc, sprintf_36_f);
  tcase_add_test(tc, sprintf_37_f);
  tcase_add_test(tc, sprintf_38_f);
  tcase_add_test(tc, sprintf_39_f);
  tcase_add_test(tc, sprintf_40_f);
  tcase_add_test(tc, sprintf_41_f);
  tcase_add_test(tc, sprintf_42_f);
  tcase_add_test(tc, sprintf_43_f);
  tcase_add_test(tc, sprintf_44_f);
  tcase_add_test(tc, sprintf_45_f);
  tcase_add_test(tc, sprintf_46_f);
  tcase_add_test(tc, sprintf_47_f);
  tcase_add_test(tc, sprintf_50_f);
  tcase_add_test(tc, sprintf_51_f);
  tcase_add_test(tc, sprintf_52_f);
  tcase_add_test(tc, sprintf_54_f);
  tcase_add_test(tc, sprintf_55_f);
  tcase_add_test(tc, sprintf_56_f);

  // -u
  tcase_add_test(tc, sprintf_1_unsigned);
  tcase_add_test(tc, sprintf_2_unsigned);
  tcase_add_test(tc, sprintf_3_unsigned);
  tcase_add_test(tc, sprintf_4_unsigned);
  tcase_add_test(tc, sprintf_5_unsigned);
  tcase_add_test(tc, sprintf_6_unsigned);
  tcase_add_test(tc, sprintf_7_unsigned);
  tcase_add_test(tc, sprintf_8_unsigned);
  tcase_add_test(tc, sprintf_9_unsigned);
  tcase_add_test(tc, sprintf_10_unsigned);
  tcase_add_test(tc, sprintf_11_unsigned);
  tcase_add_test(tc, sprintf_12_unsigned);
  tcase_add_test(tc, sprintf_13_unsigned);
  tcase_add_test(tc, sprintf_14_unsigned);
  tcase_add_test(tc, sprintf_15_unsigned);
  tcase_add_test(tc, sprintf_16_unsigned);
  tcase_add_test(tc, sprintf_17_unsigned);

  // -i
  tcase_add_test(tc, sprintf_1_signed_i);
  tcase_add_test(tc, sprintf_2_signed_i);
  tcase_add_test(tc, sprintf_3_signed_i);
  tcase_add_test(tc, sprintf_4_signed_i);
  tcase_add_test(tc, sprintf_5_signed_i);
  tcase_add_test(tc, sprintf_6_signed_i);
  tcase_add_test(tc, sprintf_7_signed_i);
  tcase_add_test(tc, sprintf_8_signed_i);
  tcase_add_test(tc, sprintf_9_signed_i);
  tcase_add_test(tc, sprintf_10_signed_i);
  tcase_add_test(tc, sprintf_11_signed_i);
  tcase_add_test(tc, sprintf_12_signed_i);
  tcase_add_test(tc, sprintf_13_signed_i);
  tcase_add_test(tc, sprintf_14_signed_i);
  tcase_add_test(tc, sprintf_15_signed_i);
  tcase_add_test(tc, sprintf_16_signed_i);
  tcase_add_test(tc, sprintf_17_signed_i);

  tcase_add_test(tc, sprintf_1_pointer);
  tcase_add_test(tc, sprintf_2_pointer);
  tcase_add_test(tc, sprintf_3_pointer);
  tcase_add_test(tc, sprintf_4_pointer);
  tcase_add_test(tc, sprintf_5_pointer);
  tcase_add_test(tc, sprintf_6_pointer);
  tcase_add_test(tc, sprintf_7_pointer);
  tcase_add_test(tc, sprintf_8_pointer);
  tcase_add_test(tc, sprintf_9_pointer);
  tcase_add_test(tc, sprintf_10_pointer);
  tcase_add_test(tc, sprintf_11_pointer);
  tcase_add_test(tc, sprintf_12_pointer);
  tcase_add_test(tc, sprintf_13_pointer);
  tcase_add_test(tc, sprintf_14_pointer);
  tcase_add_test(tc, sprintf_15_pointer);

  tcase_add_test(tc, sprintf_1_hex);
  tcase_add_test(tc, sprintf_2_hex);
  tcase_add_test(tc, sprintf_3_hex);
  tcase_add_test(tc, sprintf_4_hex);
  tcase_add_test(tc, sprintf_5_hex);
  tcase_add_test(tc, sprintf_6_hex);
  tcase_add_test(tc, sprintf_7_hex);
  tcase_add_test(tc, sprintf_8_hex);
  tcase_add_test(tc, sprintf_9_hex);
  tcase_add_test(tc, sprintf_10_hex);
  tcase_add_test(tc, sprintf_11_hex);
  tcase_add_test(tc, sprintf_12_hex);
  tcase_add_test(tc, sprintf_13_hex);
  tcase_add_test(tc, sprintf_14_hex);
  tcase_add_test(tc, sprintf_15_hex);
  tcase_add_test(tc, sprintf_16_hex);
  tcase_add_test(tc, sprintf_17_hex);
  tcase_add_test(tc, sprintf_18_hex);
  tcase_add_test(tc, sprintf_19_hex);

  tcase_add_test(tc, sprintf_1_HEX);
  tcase_add_test(tc, sprintf_2_HEX);
  tcase_add_test(tc, sprintf_3_HEX);
  tcase_add_test(tc, sprintf_4_HEX);
  tcase_add_test(tc, sprintf_5_HEX);
  tcase_add_test(tc, sprintf_6_HEX);
  tcase_add_test(tc, sprintf_7_HEX);
  tcase_add_test(tc, sprintf_8_HEX);
  tcase_add_test(tc, sprintf_9_HEX);
  tcase_add_test(tc, sprintf_10_HEX);
  tcase_add_test(tc, sprintf_11_HEX);
  tcase_add_test(tc, sprintf_12_HEX);
  tcase_add_test(tc, sprintf_13_HEX);
  tcase_add_test(tc, sprintf_14_HEX);
  tcase_add_test(tc, sprintf_15_HEX);
  tcase_add_test(tc, sprintf_16_HEX);
  tcase_add_test(tc, sprintf_17_HEX);

  tcase_add_test(tc, sprintf_1_octal);
  tcase_add_test(tc, sprintf_2_octal);
  tcase_add_test(tc, sprintf_3_octal);
  tcase_add_test(tc, sprintf_4_octal);
  tcase_add_test(tc, sprintf_5_octal);
  tcase_add_test(tc, sprintf_6_octal);
  tcase_add_test(tc, sprintf_7_octal);
  tcase_add_test(tc, sprintf_8_octal);
  tcase_add_test(tc, sprintf_9_octal);
  tcase_add_test(tc, sprintf_10_octal);
  tcase_add_test(tc, sprintf_11_octal);
  tcase_add_test(tc, sprintf_12_octal);
  tcase_add_test(tc, sprintf_13_octal);
  tcase_add_test(tc, sprintf_14_octal);
  tcase_add_test(tc, sprintf_15_octal);
  tcase_add_test(tc, sprintf_16_octal);
  tcase_add_test(tc, sprintf_17_octal);
  tcase_add_test(tc, sprintf_18_octal);
  tcase_add_test(tc, sprintf_19_octal);
  tcase_add_test(tc, sprintf_20_octal);

  tcase_add_test(tc, sprintf_1_e);
  tcase_add_test(tc, sprintf_2_e);
  tcase_add_test(tc, sprintf_3_e);
  tcase_add_test(tc, sprintf_4_e);
  tcase_add_test(tc, sprintf_5_e);
  tcase_add_test(tc, sprintf_6_e);
  tcase_add_test(tc, sprintf_7_e);
  tcase_add_test(tc, sprintf_8_e);
  tcase_add_test(tc, sprintf_9_e);
  tcase_add_test(tc, sprintf_10_e);
  tcase_add_test(tc, sprintf_11_e);
  tcase_add_test(tc, sprintf_12_e);
  tcase_add_test(tc, sprintf_13_e);
  tcase_add_test(tc, sprintf_14_e);
  tcase_add_test(tc, sprintf_15_e);
  tcase_add_test(tc, sprintf_16_e);
  tcase_add_test(tc, sprintf_17_e);
  tcase_add_test(tc, sprintf_18_e);
  tcase_add_test(tc, sprintf_19_e);
  tcase_add_test(tc, sprintf_20_e);
  tcase_add_test(tc, sprintf_21_e);
  tcase_add_test(tc, sprintf_22_e);
  tcase_add_test(tc, sprintf_23_e);
  tcase_add_test(tc, sprintf_24_e);
  tcase_add_test(tc, sprintf_25_e);
  tcase_add_test(tc, sprintf_26_e);
  tcase_add_test(tc, sprintf_27_e);
  tcase_add_test(tc, sprintf_28_e);
  tcase_add_test(tc, sprintf_29_e);
  tcase_add_test(tc, sprintf_30_e);
  tcase_add_test(tc, sprintf_31_e);
  tcase_add_test(tc, sprintf_32_e);
  tcase_add_test(tc, sprintf_33_e);
  tcase_add_test(tc, sprintf_34_e);
  tcase_add_test(tc, sprintf_35_e);
  tcase_add_test(tc, sprintf_36_e);
  tcase_add_test(tc, sprintf_37_e);
  tcase_add_test(tc, sprintf_38_e);
  tcase_add_test(tc, sprintf_39_e);
  tcase_add_test(tc, sprintf_40_e);
  tcase_add_test(tc, sprintf_41_e);
  tcase_add_test(tc, sprintf_42_e);
  tcase_add_test(tc, sprintf_43_e);
  tcase_add_test(tc, sprintf_44_e);

  tcase_add_test(tc, sprintf_1_g);
  tcase_add_test(tc, sprintf_2_g);
  tcase_add_test(tc, sprintf_3_g);
  tcase_add_test(tc, sprintf_4_g);
  tcase_add_test(tc, sprintf_5_g);
  tcase_add_test(tc, sprintf_6_g);
  tcase_add_test(tc, sprintf_7_g);
  tcase_add_test(tc, sprintf_8_g);
  tcase_add_test(tc, sprintf_9_g);
  tcase_add_test(tc, sprintf_10_g);
  tcase_add_test(tc, sprintf_11_g);
  tcase_add_test(tc, sprintf_12_g);
  tcase_add_test(tc, sprintf_13_g);
  tcase_add_test(tc, sprintf_14_g);
  tcase_add_test(tc, sprintf_15_g);
  tcase_add_test(tc, sprintf_16_g);
  tcase_add_test(tc, sprintf_17_g);
  tcase_add_test(tc, sprintf_18_g);
  tcase_add_test(tc, sprintf_19_g);
  tcase_add_test(tc, sprintf_20_g);
  tcase_add_test(tc, sprintf_21_g);
  tcase_add_test(tc, sprintf_22_g);
  tcase_add_test(tc, sprintf_23_g);
  tcase_add_test(tc, sprintf_24_g);
  tcase_add_test(tc, sprintf_25_g);
  tcase_add_test(tc, sprintf_26_g);
  tcase_add_test(tc, sprintf_27_g);
  tcase_add_test(tc, sprintf_28_g);
  tcase_add_test(tc, sprintf_29_g);
  tcase_add_test(tc, sprintf_30_g);
  tcase_add_test(tc, sprintf_31_g);
  tcase_add_test(tc, sprintf_32_g);
  tcase_add_test(tc, sprintf_33_g);
  tcase_add_test(tc, sprintf_34_g);
  tcase_add_test(tc, sprintf_35_g);
  tcase_add_test(tc, sprintf_36_g);
  tcase_add_test(tc, sprintf_37_g);
  tcase_add_test(tc, sprintf_38_g);
  tcase_add_test(tc, sprintf_39_g);
  tcase_add_test(tc, sprintf_40_g);
  tcase_add_test(tc, sprintf_41_g);
  tcase_add_test(tc, sprintf_42_g);
  tcase_add_test(tc, sprintf_43_g);
  tcase_add_test(tc, sprintf_44_g);
  tcase_add_test(tc, sprintf_45_g);
  tcase_add_test(tc, sprintf_46_g);

  tcase_add_test(tc, sprintf_1_n);
  tcase_add_test(tc, sprintf_2_n);
  tcase_add_test(tc, sprintf_3_n);
  tcase_add_test(tc, sprintf_4_n);

  tcase_add_test(tc, sprintf_1_percent);
  tcase_add_test(tc, sprintf_2_percent);
  tcase_add_test(tc, sprintf_3_percent);

  tcase_add_test(tc, e_precision_huge);
  tcase_add_test(tc, test_sprintf_huge_w);
  tcase_add_test(tc, test_sprintf_1_1);
  tcase_add_test(tc, sprintf_many_g);
  tcase_add_test(tc, sprintf_large_g);
  tcase_add_test(tc, sprintf_zero_prec_g);
  tcase_add_test(tc, test_sprintf_hard_1);
  tcase_add_test(tc, sprintf_no_prec_g);
  tcase_add_test(tc, test_many_hex_lower);
  tcase_add_test(tc, test_many_hex_upper);
  tcase_add_test(tc, test_many_hex_lower_with_zero);
  tcase_add_test(tc, test_many_hex_upper_with_zero);
  tcase_add_test(tc, test_many_hex_lower_ast_grid_neg);
  tcase_add_test(tc, test_many_hex_upper_with_width_star);
  tcase_add_test(tc, test_many_hex_lower_hard_1);
  tcase_add_test(tc, test_many_hex_upper_hard_1);
  tcase_add_test(tc, test_one_hex_lower_with_length);
  tcase_add_test(tc, test_one_hex_upper_with_length);

  suite_add_tcase(s, tc);
  // Ready -c -d -i -f -s -u -p -x -X -o -e -E -g % *
  return s;
}
