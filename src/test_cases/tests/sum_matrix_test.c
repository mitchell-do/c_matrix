#include "../test.h"

START_TEST(test_sum_simple) {
  s21_matrix first_matrix;
  s21_matrix second_matrix;
  s21_matrix result_matrix;
  s21_matrix expected_result;

  ck_assert_int_eq(create_matrix_with_nums(2, 2, &first_matrix, 3.0), OK);
  ck_assert_int_eq(create_matrix_with_nums(2, 2, &second_matrix, 3.0), OK);
  ck_assert_int_eq(create_matrix_with_nums(2, 2, &expected_result, 6.0), OK);

  ck_assert_int_eq(
      s21_sum_matrix(&first_matrix, &second_matrix, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected_result), SUCCESS);

  s21_remove_matrix(&first_matrix);
  s21_remove_matrix(&second_matrix);
  s21_remove_matrix(&result_matrix);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_sum_simple_minus_sec_matrix) {
  s21_matrix first_matrix;
  s21_matrix second_matrix;
  s21_matrix result_matrix;
  s21_matrix expected_result;

  ck_assert_int_eq(create_matrix_with_nums(2, 2, &first_matrix, 3.0), OK);
  ck_assert_int_eq(create_matrix_with_nums(2, 2, &second_matrix, -3.0), OK);
  ck_assert_int_eq(create_matrix_with_nums(2, 2, &expected_result, 0.0), OK);

  ck_assert_int_eq(
      s21_sum_matrix(&first_matrix, &second_matrix, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected_result), SUCCESS);

  s21_remove_matrix(&first_matrix);
  s21_remove_matrix(&second_matrix);
  s21_remove_matrix(&result_matrix);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_sum_simple_minus_fir_matrix) {
  s21_matrix first_matrix;
  s21_matrix second_matrix;
  s21_matrix result_matrix;
  s21_matrix expected_result;

  ck_assert_int_eq(create_matrix_with_nums(2, 2, &first_matrix, -3.0), OK);
  ck_assert_int_eq(create_matrix_with_nums(2, 2, &second_matrix, 3.0), OK);
  ck_assert_int_eq(create_matrix_with_nums(2, 2, &expected_result, 0.0), OK);

  ck_assert_int_eq(
      s21_sum_matrix(&first_matrix, &second_matrix, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected_result), SUCCESS);

  s21_remove_matrix(&first_matrix);
  s21_remove_matrix(&second_matrix);
  s21_remove_matrix(&result_matrix);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_sum_error_incorrect_matrix) {
  s21_matrix first_matrix;
  s21_matrix second_matrix;
  s21_matrix result_matrix;

  ck_assert_int_eq(create_matrix_with_nums(3, 3, &first_matrix, -3.0), OK);
  ck_assert_int_eq(create_matrix_with_nums(2, 2, &second_matrix, 3.0), OK);

  ck_assert_int_eq(
      s21_sum_matrix(&first_matrix, &second_matrix, &result_matrix),
      ERROR_CALCULATION);

  s21_remove_matrix(&first_matrix);
  s21_remove_matrix(&second_matrix);
}
END_TEST

START_TEST(test_sum_error_null_matrix) {
  s21_matrix result_matrix;
  s21_matrix temp;
  ck_assert_int_eq(s21_create_matrix(2, 2, &temp), OK);

  ck_assert_int_eq(
      s21_sum_matrix((s21_matrix *)NULL, (s21_matrix *)NULL, &result_matrix),
      ERROR_INCORRECT_MATRIX);
  ck_assert_int_eq(s21_sum_matrix((s21_matrix *)NULL, &temp, &result_matrix),
                   ERROR_INCORRECT_MATRIX);
  ck_assert_int_eq(s21_sum_matrix(&temp, (s21_matrix *)NULL, &result_matrix),
                   ERROR_INCORRECT_MATRIX);
  ck_assert_int_eq(s21_sum_matrix(&temp, &temp, (s21_matrix *)NULL),
                   ERROR_INCORRECT_MATRIX);
  s21_remove_matrix(&temp);
}
END_TEST

Suite *test_s21_sum_matrix_suite(void) {
  Suite *suite = suite_create("s21_sum_matrix");
  TCase *tc = tcase_create("sum_matrix");

  tcase_add_test(tc, test_sum_simple);
  tcase_add_test(tc, test_sum_simple_minus_fir_matrix);
  tcase_add_test(tc, test_sum_simple_minus_sec_matrix);
  tcase_add_test(tc, test_sum_error_incorrect_matrix);
  tcase_add_test(tc, test_sum_error_null_matrix);

  suite_add_tcase(suite, tc);
  return suite;
}