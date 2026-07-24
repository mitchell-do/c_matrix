#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

Suite *test_s21_calc_complements_suite(void);
Suite *test_s21_equal_suite(void);
Suite *test_s21_init_suite(void);
Suite *test_s21_sum_matrix_suite(void);
Suite *test_s21_sub_matrix_suite(void);
Suite *test_s21_mult_number_suite(void);
Suite *test_s21_mult_matrix_suite(void);
Suite *test_s21_transpose_suite(void);
Suite *test_s21_determinant_suite(void);
Suite *test_s21_inverse_matrix(void);
Suite *test_s21_helpful_func_suite(void);
int create_matrix_with_nums(int rows, int columns, s21_matrix *A, double n);
void eq_double(double a, double b);

#endif
