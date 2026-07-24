#include "../test.h"

START_TEST(test_mult_number_simple) {
  s21_matrix temp_matrix;
  s21_matrix result_matrix;
  s21_matrix expected_result;

  ck_assert_int_eq(create_matrix_with_nums(2, 2, &temp_matrix, 3.0), OK);
  ck_assert_int_eq(create_matrix_with_nums(2, 2, &expected_result, 6.0), OK);

  ck_assert_int_eq(s21_mult_number(&temp_matrix, 2.0, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected_result), SUCCESS);

  s21_remove_matrix(&temp_matrix);
  s21_remove_matrix(&result_matrix);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_mult_number_simple_1_1) {
  s21_matrix temp_matrix;
  s21_matrix result_matrix;
  s21_matrix expected_result;

  ck_assert_int_eq(create_matrix_with_nums(1, 1, &temp_matrix, 3.0), OK);
  ck_assert_int_eq(create_matrix_with_nums(1, 1, &expected_result, 6.0), OK);

  ck_assert_int_eq(s21_mult_number(&temp_matrix, 2.0, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected_result), SUCCESS);

  s21_remove_matrix(&temp_matrix);
  s21_remove_matrix(&result_matrix);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_mult_number_simple_negative) {
  s21_matrix temp_matrix;
  s21_matrix result_matrix;
  s21_matrix expected_result;

  ck_assert_int_eq(create_matrix_with_nums(3, 2, &temp_matrix, 3.0), OK);
  ck_assert_int_eq(create_matrix_with_nums(3, 2, &expected_result, -6.0), OK);

  ck_assert_int_eq(s21_mult_number(&temp_matrix, -2.0, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected_result), SUCCESS);

  s21_remove_matrix(&temp_matrix);
  s21_remove_matrix(&result_matrix);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_mult_number_zero_matrix) {
  s21_matrix temp_matrix;
  s21_matrix result_matrix;
  s21_matrix expected_result;

  ck_assert_int_eq(create_matrix_with_nums(3, 2, &temp_matrix, 3.0), OK);
  ck_assert_int_eq(create_matrix_with_nums(3, 2, &expected_result, -6.0), OK);

  ck_assert_int_eq(s21_mult_number(&temp_matrix, -2.0, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected_result), SUCCESS);

  s21_remove_matrix(&temp_matrix);
  s21_remove_matrix(&result_matrix);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_mult_number_error_null_matrix) {
  s21_matrix result_matrix;
  s21_matrix temp;
  ck_assert_int_eq(s21_create_matrix(2, 3, &temp), OK);

  ck_assert_int_eq(s21_mult_number((s21_matrix *)NULL, -2.0, &result_matrix),
                   ERROR_INCORRECT_MATRIX);
  ck_assert_int_eq(s21_mult_number(&temp, -2.0, (s21_matrix *)NULL),
                   ERROR_INCORRECT_MATRIX);
  ck_assert_int_eq(
      s21_mult_number((s21_matrix *)NULL, -2.0, (s21_matrix *)NULL),
      ERROR_INCORRECT_MATRIX);
  s21_remove_matrix(&temp);
}
END_TEST

Suite *test_s21_mult_number_suite(void) {
  Suite *suite = suite_create("s21_mult_number");
  TCase *tc = tcase_create("mult_number");

  tcase_add_test(tc, test_mult_number_simple);
  tcase_add_test(tc, test_mult_number_simple_1_1);
  tcase_add_test(tc, test_mult_number_simple_negative);
  tcase_add_test(tc, test_mult_number_zero_matrix);
  tcase_add_test(tc, test_mult_number_error_null_matrix);

  suite_add_tcase(suite, tc);
  return suite;
}