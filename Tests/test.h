#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"
#define SIZE 256

Suite *sscanf_suite(void);
Suite *string_suite(void);
Suite *special_suite(void);
Suite *sprintf_suite(void);

#endif  //  SRC_TESTS_TEST_H_
