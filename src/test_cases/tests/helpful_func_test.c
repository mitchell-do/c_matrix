#include "../test.h"

START_TEST(test_check_null_matrix) {
  s21_matrix temp_matrix;

  ck_assert_int_eq(s21_check_null_matrix(&temp_matrix), OK);
  ck_assert_int_eq(s21_check_null_matrix((s21_matrix *)NULL),
                   ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_check_get_minor_null) {
  double temp;

  ck_assert_int_eq(s21_get_minor((s21_matrix *)NULL, 1, 2, &temp),
                   ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_eq_doble_check) {
  double a = 9.5;
  double b = 10.5;

  ck_assert_int_eq(s21_eq_double(a, b), FAILURE);
  ck_assert_int_eq(s21_eq_double(a, a), SUCCESS);
  ck_assert_int_eq(s21_eq_double(INFINITY, b), FAILURE);
  ck_assert_int_eq(s21_eq_double(NAN, b), FAILURE);
  ck_assert_int_eq(s21_eq_double(INFINITY, INFINITY), FAILURE);
  ck_assert_int_eq(s21_eq_double(NAN, NAN), FAILURE);
  ck_assert_int_eq(s21_eq_double(a, INFINITY), FAILURE);
  ck_assert_int_eq(s21_eq_double(a, NAN), FAILURE);
}
END_TEST

Suite *test_s21_helpful_func_suite(void) {
  Suite *suite = suite_create("s21_helpful_func");
  TCase *tc = tcase_create("helpful_func");

  tcase_add_test(tc, test_check_null_matrix);
  tcase_add_test(tc, test_check_get_minor_null);
  tcase_add_test(tc, test_eq_doble_check);

  suite_add_tcase(suite, tc);
  return suite;
}