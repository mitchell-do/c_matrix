#include "../test.h"

START_TEST(test_determinant_simple) {
  s21_matrix temp_matrix;
  double result = 0.0;
  double excepted_result = 0.0;

  ck_assert_int_eq(create_matrix_with_nums(4, 4, &temp_matrix, 4), OK);
  ck_assert_int_eq(s21_determinant(&temp_matrix, &result), OK);

  eq_double(result, excepted_result);

  s21_remove_matrix(&temp_matrix);
}

START_TEST(test_determinant_simple_2_2) {
  s21_matrix temp_matrix;
  double result = 0.0;
  double excepted_result = -2.0;

  ck_assert_int_eq(s21_create_matrix(2, 2, &temp_matrix), OK);

  temp_matrix.matrix[0][0] = 1.0;
  temp_matrix.matrix[0][1] = 2.0;
  temp_matrix.matrix[1][0] = 3.0;
  temp_matrix.matrix[1][1] = 4.0;

  ck_assert_int_eq(s21_determinant(&temp_matrix, &result), OK);

  eq_double(result, excepted_result);
  s21_remove_matrix(&temp_matrix);
}

START_TEST(test_determinant_simple_1_1) {
  s21_matrix temp_matrix;
  double result = 0.0;
  double excepted_result = -2.0;

  ck_assert_int_eq(s21_create_matrix(1, 1, &temp_matrix), OK);

  temp_matrix.matrix[0][0] = -2.0;

  ck_assert_int_eq(s21_determinant(&temp_matrix, &result), OK);
  eq_double(result, excepted_result);

  s21_remove_matrix(&temp_matrix);
}

START_TEST(test_determinant_error_wrong_matrix) {
  s21_matrix temp_matrix;
  double result = 0.0;

  ck_assert_int_eq(create_matrix_with_nums(4, 3, &temp_matrix, 4), OK);
  ck_assert_int_eq(s21_determinant(&temp_matrix, &result), ERROR_CALCULATION);
  s21_remove_matrix(&temp_matrix);
}

START_TEST(test_determinant_error_null_matrix) {
  double result = 0.0;

  ck_assert_int_eq(s21_determinant((s21_matrix *)NULL, &result),
                   ERROR_INCORRECT_MATRIX);
}

START_TEST(test_determinant_simple_3_3) {
  s21_matrix temp_matrix;
  double result = 0.0;
  double excepted_result = 0.0;

  ck_assert_int_eq(create_matrix_with_nums(3, 3, &temp_matrix, 5.0), OK);

  ck_assert_int_eq(s21_determinant(&temp_matrix, &result), OK);

  eq_double(result, excepted_result);
  s21_remove_matrix(&temp_matrix);
}

START_TEST(test_determinant_simple_4_4) {
  s21_matrix temp_matrix;
  double result = 0.0;
  double excepted_result = 0.0;

  ck_assert_int_eq(create_matrix_with_nums(4, 4, &temp_matrix, 5.0), OK);

  ck_assert_int_eq(s21_determinant(&temp_matrix, &result), OK);

  eq_double(result, excepted_result);
  s21_remove_matrix(&temp_matrix);
}

START_TEST(test_determinant_matrix_4_4) {
  s21_matrix temp_matrix;
  double result = 0.0;
  double excepted_result = -7020926.0;

  ck_assert_int_eq(s21_create_matrix(4, 4, &temp_matrix), OK);

  temp_matrix.matrix[0][0] = 0.0;
  temp_matrix.matrix[0][1] = 20.0;
  temp_matrix.matrix[0][2] = 12.0;
  temp_matrix.matrix[0][3] = 11.0;

  temp_matrix.matrix[1][0] = 4.0;
  temp_matrix.matrix[1][1] = 0.0;
  temp_matrix.matrix[1][2] = 34.0;
  temp_matrix.matrix[1][3] = 85.0;

  temp_matrix.matrix[2][0] = 21.0;
  temp_matrix.matrix[2][1] = 122.0;
  temp_matrix.matrix[2][2] = 0.0;
  temp_matrix.matrix[2][3] = 21.0;

  temp_matrix.matrix[3][0] = 45.0;
  temp_matrix.matrix[3][1] = 25.0;
  temp_matrix.matrix[3][2] = 86.0;
  temp_matrix.matrix[3][3] = 12.0;

  ck_assert_int_eq(s21_determinant(&temp_matrix, &result), OK);

  eq_double(result, excepted_result);
  s21_remove_matrix(&temp_matrix);
}

START_TEST(test_determinant_matrix_3_3_from_md) {
  s21_matrix temp_matrix;
  double result = 0.0;
  double excepted_result = 0.0;

  ck_assert_int_eq(s21_create_matrix(3, 3, &temp_matrix), OK);

  temp_matrix.matrix[0][0] = 1.0;
  temp_matrix.matrix[0][1] = 2.0;
  temp_matrix.matrix[0][2] = 3.0;

  temp_matrix.matrix[1][0] = 5.0;
  temp_matrix.matrix[1][1] = 6.0;
  temp_matrix.matrix[1][2] = 7.0;

  temp_matrix.matrix[2][0] = 8.0;
  temp_matrix.matrix[2][1] = 9.0;
  temp_matrix.matrix[2][2] = 10.0;

  ck_assert_int_eq(s21_determinant(&temp_matrix, &result), OK);

  eq_double(result, excepted_result);
  s21_remove_matrix(&temp_matrix);
}

START_TEST(test_s21_determinant_3x3) {
  s21_matrix A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 1.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = 6.0;
  A.matrix[2][2] = 0.0;

  double determinant = 0.0;
  int status = s21_determinant(&A, &determinant);

  ck_assert_int_eq(status, OK);
  eq_double(determinant, 1.0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_simple_5_5) {
  s21_matrix temp_matrix;
  double result = 0.0;
  double excepted_result = 0.0;

  ck_assert_int_eq(create_matrix_with_nums(5, 5, &temp_matrix, 5.0), OK);

  ck_assert_int_eq(s21_determinant(&temp_matrix, &result), OK);

  eq_double(result, excepted_result);
  s21_remove_matrix(&temp_matrix);
}

Suite *test_s21_determinant_suite(void) {
  Suite *suite = suite_create("s21_determinant");
  TCase *tc = tcase_create("determinant");

  tcase_add_test(tc, test_determinant_simple);
  tcase_add_test(tc, test_determinant_error_wrong_matrix);
  tcase_add_test(tc, test_determinant_simple_5_5);
  tcase_add_test(tc, test_determinant_simple_4_4);
  tcase_add_test(tc, test_determinant_simple_3_3);
  tcase_add_test(tc, test_determinant_matrix_3_3_from_md);
  tcase_add_test(tc, test_s21_determinant_3x3);
  tcase_add_test(tc, test_determinant_simple_2_2);
  tcase_add_test(tc, test_determinant_simple_1_1);
  tcase_add_test(tc, test_determinant_error_null_matrix);

  tcase_add_test(tc, test_determinant_matrix_4_4);

  suite_add_tcase(suite, tc);
  return suite;
}
