#include "../test.h"

START_TEST(test_transpose_square_matrix) {
  s21_matrix temp_matrix;
  s21_matrix result_matrix;
  s21_matrix expected_result;

  ck_assert_int_eq(create_matrix_with_nums(4, 4, &temp_matrix, 2.0), OK);
  ck_assert_int_eq(create_matrix_with_nums(4, 4, &expected_result, 2.0), OK);

  ck_assert_int_eq(s21_transpose(&temp_matrix, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected_result), SUCCESS);

  s21_remove_matrix(&temp_matrix);
  s21_remove_matrix(&result_matrix);
  s21_remove_matrix(&expected_result);
}

START_TEST(test_transpose_simple_1_1) {
  s21_matrix temp_matrix;
  s21_matrix result_matrix;
  s21_matrix expected_result;

  ck_assert_int_eq(s21_create_matrix(1, 1, &temp_matrix), OK);
  ck_assert_int_eq(s21_create_matrix(1, 1, &expected_result), OK);

  temp_matrix.matrix[0][0] = 13.0;
  expected_result.matrix[0][0] = 13.0;

  ck_assert_int_eq(s21_transpose(&temp_matrix, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected_result), SUCCESS);
  s21_remove_matrix(&temp_matrix);
  s21_remove_matrix(&result_matrix);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_transpose_simple) {
  s21_matrix temp_matrix;
  s21_matrix result_matrix;
  s21_matrix expected_result;

  ck_assert_int_eq(s21_create_matrix(3, 4, &temp_matrix), OK);
  ck_assert_int_eq(s21_create_matrix(4, 3, &expected_result), OK);

  temp_matrix.matrix[0][0] = 13.0;
  temp_matrix.matrix[0][1] = 12.0;
  temp_matrix.matrix[0][2] = 55.0;
  temp_matrix.matrix[0][3] = -5.5;

  temp_matrix.matrix[1][0] = 3.2;
  temp_matrix.matrix[1][1] = 56.0;
  temp_matrix.matrix[1][2] = 90.0;
  temp_matrix.matrix[1][3] = 3.0;

  temp_matrix.matrix[2][0] = 1.0;
  temp_matrix.matrix[2][1] = 2.0;
  temp_matrix.matrix[2][2] = 3.0;
  temp_matrix.matrix[2][3] = -5.0;

  expected_result.matrix[0][0] = 13.0;
  expected_result.matrix[0][1] = 3.2;
  expected_result.matrix[0][2] = 1.0;

  expected_result.matrix[1][0] = 12.0;
  expected_result.matrix[1][1] = 56.0;
  expected_result.matrix[1][2] = 2.0;

  expected_result.matrix[2][0] = 55.0;
  expected_result.matrix[2][1] = 90.0;
  expected_result.matrix[2][2] = 3.0;

  expected_result.matrix[3][0] = -5.5;
  expected_result.matrix[3][1] = 3.0;
  expected_result.matrix[3][2] = -5.0;

  ck_assert_int_eq(s21_transpose(&temp_matrix, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected_result), SUCCESS);
  s21_remove_matrix(&temp_matrix);
  s21_remove_matrix(&result_matrix);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_transpose_simple_two) {
  s21_matrix temp_matrix;
  s21_matrix result_matrix;
  s21_matrix expected_result;

  ck_assert_int_eq(create_matrix_with_nums(10, 2, &temp_matrix, 2.0), OK);
  ck_assert_int_eq(create_matrix_with_nums(2, 10, &expected_result, 2.0), OK);

  ck_assert_int_eq(s21_transpose(&temp_matrix, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected_result), SUCCESS);
  s21_remove_matrix(&temp_matrix);
  s21_remove_matrix(&result_matrix);
  s21_remove_matrix(&expected_result);
}

START_TEST(test_transpose_error_null_matrix) {
  s21_matrix temp;

  ck_assert_int_eq(s21_create_matrix(2, 2, &temp), OK);

  ck_assert_int_eq(s21_transpose((s21_matrix *)NULL, (s21_matrix *)NULL),
                   ERROR_INCORRECT_MATRIX);
  ck_assert_int_eq(s21_transpose((s21_matrix *)NULL, &temp),
                   ERROR_INCORRECT_MATRIX);
  ck_assert_int_eq(s21_transpose(&temp, (s21_matrix *)NULL),
                   ERROR_INCORRECT_MATRIX);

  s21_remove_matrix(&temp);
}
END_TEST

Suite *test_s21_transpose_suite(void) {
  Suite *suite = suite_create("s21_transpose");
  TCase *tc = tcase_create("transpose");

  tcase_add_test(tc, test_transpose_simple);
  tcase_add_test(tc, test_transpose_simple_1_1);
  tcase_add_test(tc, test_transpose_simple_two);
  tcase_add_test(tc, test_transpose_square_matrix);
  tcase_add_test(tc, test_transpose_error_null_matrix);

  suite_add_tcase(suite, tc);
  return suite;
}