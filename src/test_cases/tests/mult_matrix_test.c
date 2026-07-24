#include "../test.h"

START_TEST(test_mult_matrix_simple_negative) {
  s21_matrix f_matrix;
  s21_matrix s_matrix;

  s21_matrix result_matrix;
  s21_matrix expected_result;

  ck_assert_int_eq(s21_create_matrix(3, 2, &f_matrix), OK);
  ck_assert_int_eq(s21_create_matrix(2, 3, &s_matrix), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &expected_result), OK);

  f_matrix.matrix[0][0] = 1;
  f_matrix.matrix[0][1] = 4;

  f_matrix.matrix[1][0] = 2;
  f_matrix.matrix[1][1] = 5;

  f_matrix.matrix[2][0] = 3;
  f_matrix.matrix[2][1] = 6;

  s_matrix.matrix[0][0] = 1;
  s_matrix.matrix[0][1] = -1;
  s_matrix.matrix[0][2] = 1;

  s_matrix.matrix[1][0] = 2;
  s_matrix.matrix[1][1] = 3;
  s_matrix.matrix[1][2] = 4;

  expected_result.matrix[0][0] = 9;
  expected_result.matrix[0][1] = 11;
  expected_result.matrix[0][2] = 17;

  expected_result.matrix[1][0] = 12;
  expected_result.matrix[1][1] = 13;
  expected_result.matrix[1][2] = 22;

  expected_result.matrix[2][0] = 15;
  expected_result.matrix[2][1] = 15;
  expected_result.matrix[2][2] = 27;

  ck_assert_int_eq(s21_mult_matrix(&f_matrix, &s_matrix, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected_result), SUCCESS);

  s21_remove_matrix(&f_matrix);
  s21_remove_matrix(&s_matrix);
  s21_remove_matrix(&result_matrix);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_mult_matrix_simple) {
  s21_matrix f_matrix;
  s21_matrix s_matrix;

  s21_matrix result_matrix;
  s21_matrix expected_result;

  ck_assert_int_eq(s21_create_matrix(3, 2, &f_matrix), OK);
  ck_assert_int_eq(s21_create_matrix(2, 3, &s_matrix), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &expected_result), OK);

  f_matrix.matrix[0][0] = 1;
  f_matrix.matrix[0][1] = 4;

  f_matrix.matrix[1][0] = 2;
  f_matrix.matrix[1][1] = 5;

  f_matrix.matrix[2][0] = 3;
  f_matrix.matrix[2][1] = 6;

  s_matrix.matrix[0][0] = 1;
  s_matrix.matrix[0][1] = -1;
  s_matrix.matrix[0][2] = 1;

  s_matrix.matrix[1][0] = 2;
  s_matrix.matrix[1][1] = 3;
  s_matrix.matrix[1][2] = 4;

  expected_result.matrix[0][0] = 9;
  expected_result.matrix[0][1] = 11;
  expected_result.matrix[0][2] = 17;

  expected_result.matrix[1][0] = 12;
  expected_result.matrix[1][1] = 13;
  expected_result.matrix[1][2] = 22;

  expected_result.matrix[2][0] = 15;
  expected_result.matrix[2][1] = 15;
  expected_result.matrix[2][2] = 27;

  ck_assert_int_eq(s21_mult_matrix(&f_matrix, &s_matrix, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected_result), SUCCESS);
  s21_remove_matrix(&f_matrix);
  s21_remove_matrix(&s_matrix);
  s21_remove_matrix(&result_matrix);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_mult_matrix_simple_1_1) {
  s21_matrix f_matrix;
  s21_matrix s_matrix;

  s21_matrix result_matrix;
  s21_matrix expected_result;

  ck_assert_int_eq(s21_create_matrix(1, 1, &f_matrix), OK);
  ck_assert_int_eq(s21_create_matrix(1, 1, &s_matrix), OK);
  ck_assert_int_eq(s21_create_matrix(1, 1, &expected_result), OK);

  f_matrix.matrix[0][0] = 10.0;

  s_matrix.matrix[0][0] = 8.9;

  expected_result.matrix[0][0] = 89.0;

  ck_assert_int_eq(s21_mult_matrix(&f_matrix, &s_matrix, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected_result), SUCCESS);
  s21_remove_matrix(&f_matrix);
  s21_remove_matrix(&s_matrix);
  s21_remove_matrix(&result_matrix);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_mult_matrix_error_incorect_matrix) {
  s21_matrix f_matrix;
  s21_matrix s_matrix;

  s21_matrix result_matrix;

  ck_assert_int_eq(s21_create_matrix(3, 2, &f_matrix), OK);
  ck_assert_int_eq(s21_create_matrix(3, 2, &s_matrix), OK);

  ck_assert_int_eq(s21_mult_matrix(&f_matrix, &s_matrix, &result_matrix),
                   ERROR_CALCULATION);

  s21_remove_matrix(&f_matrix);
  s21_remove_matrix(&s_matrix);
}
END_TEST

START_TEST(test_mult_matrix_error_null_matrix) {
  s21_matrix f_matrix;

  s21_matrix result_matrix;

  ck_assert_int_eq(s21_create_matrix(3, 3, &f_matrix), OK);

  ck_assert_int_eq(
      s21_mult_matrix((s21_matrix *)NULL, (s21_matrix *)NULL, &result_matrix),
      ERROR_INCORRECT_MATRIX);
  ck_assert_int_eq(s21_mult_matrix((s21_matrix *)NULL, (s21_matrix *)NULL,
                                   (s21_matrix *)NULL),
                   ERROR_INCORRECT_MATRIX);
  ck_assert_int_eq(
      s21_mult_matrix(&f_matrix, (s21_matrix *)NULL, &result_matrix),
      ERROR_INCORRECT_MATRIX);
  ck_assert_int_eq(
      s21_mult_matrix((s21_matrix *)NULL, &f_matrix, &result_matrix),
      ERROR_INCORRECT_MATRIX);

  s21_remove_matrix(&f_matrix);
}
END_TEST

Suite *test_s21_mult_matrix_suite(void) {
  Suite *suite = suite_create("s21_mult_matrix");
  TCase *tc = tcase_create("mult_matrix");

  tcase_add_test(tc, test_mult_matrix_simple_negative);
  tcase_add_test(tc, test_mult_matrix_simple_1_1);
  tcase_add_test(tc, test_mult_matrix_simple);
  tcase_add_test(tc, test_mult_matrix_error_incorect_matrix);
  tcase_add_test(tc, test_mult_matrix_error_null_matrix);

  suite_add_tcase(suite, tc);
  return suite;
}