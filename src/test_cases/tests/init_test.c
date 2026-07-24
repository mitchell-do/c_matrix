#include "../test.h"

START_TEST(test_create_matrix_simple) {
  s21_matrix temp_matrix;

  ck_assert_int_eq(s21_create_matrix(3, 3, &temp_matrix), OK);

  s21_remove_matrix(&temp_matrix);
}
END_TEST

START_TEST(test_create_matrix_1_1) {
  s21_matrix temp_matrix;

  ck_assert_int_eq(s21_create_matrix(1, 1, &temp_matrix), OK);

  s21_remove_matrix(&temp_matrix);
}
END_TEST

START_TEST(test_create_matrix_null_matrix) {
  ck_assert_int_eq(s21_create_matrix(1, 1, (s21_matrix *)NULL),
                   ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_create_matrix_failure) {
  s21_matrix temp_matrix;

  ck_assert_int_eq(s21_create_matrix(-3, 3, &temp_matrix),
                   ERROR_INCORRECT_MATRIX);
  ck_assert_int_eq(s21_create_matrix(3, -3, &temp_matrix),
                   ERROR_INCORRECT_MATRIX);
  ck_assert_int_eq(s21_create_matrix(-3, -3, &temp_matrix),
                   ERROR_INCORRECT_MATRIX);
}
END_TEST

Suite *test_s21_init_suite(void) {
  Suite *suite = suite_create("s21_init");
  TCase *tc = tcase_create("init");

  tcase_add_test(tc, test_create_matrix_simple);
  tcase_add_test(tc, test_create_matrix_1_1);
  tcase_add_test(tc, test_create_matrix_null_matrix);
  tcase_add_test(tc, test_create_matrix_failure);

  suite_add_tcase(suite, tc);
  return suite;
}