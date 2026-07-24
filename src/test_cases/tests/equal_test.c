#include "../test.h"

START_TEST(test_eq_succes) {
  s21_matrix first_matrix;
  s21_matrix second_matrix;

  ck_assert_int_eq(create_matrix_with_nums(2, 2, &first_matrix, 2.999999), OK);
  ck_assert_int_eq(create_matrix_with_nums(2, 2, &second_matrix, 2.999999), OK);
  ck_assert_int_eq(s21_eq_matrix(&first_matrix, &second_matrix), SUCCESS);

  s21_remove_matrix(&first_matrix);
  s21_remove_matrix(&second_matrix);
}
END_TEST

START_TEST(test_eq_succes_1_1) {
  s21_matrix first_matrix;
  s21_matrix second_matrix;

  ck_assert_int_eq(create_matrix_with_nums(1, 1, &first_matrix, 2.999999), OK);
  ck_assert_int_eq(create_matrix_with_nums(1, 1, &second_matrix, 2.999999), OK);
  ck_assert_int_eq(s21_eq_matrix(&first_matrix, &second_matrix), SUCCESS);

  s21_remove_matrix(&first_matrix);
  s21_remove_matrix(&second_matrix);
}
END_TEST

START_TEST(test_eq_failure) {
  s21_matrix first_matrix;
  s21_matrix second_matrix;

  int expected_result = FAILURE;

  ck_assert_int_eq(create_matrix_with_nums(2, 2, &first_matrix, 2.99999), OK);
  ck_assert_int_eq(create_matrix_with_nums(2, 2, &second_matrix, 3.0), OK);
  ck_assert_int_eq(s21_eq_matrix(&first_matrix, &second_matrix),
                   expected_result);

  s21_remove_matrix(&first_matrix);
  s21_remove_matrix(&second_matrix);
}
END_TEST

START_TEST(test_eq_failure_wrong_size) {
  s21_matrix first_matrix;
  s21_matrix second_matrix;

  int expected_result = FAILURE;

  ck_assert_int_eq(create_matrix_with_nums(2, 3, &first_matrix, 2.0), OK);
  ck_assert_int_eq(create_matrix_with_nums(2, 2, &second_matrix, 2.0), OK);
  ck_assert_int_eq(s21_eq_matrix(&first_matrix, &second_matrix),
                   expected_result);

  s21_remove_matrix(&first_matrix);
  s21_remove_matrix(&second_matrix);
}
END_TEST

START_TEST(test_eq_failure_null_matrix) {
  s21_matrix first_matrix;
  s21_matrix second_matrix;

  ck_assert_int_eq(create_matrix_with_nums(2, 2, &first_matrix, 2.0), OK);
  ck_assert_int_eq(create_matrix_with_nums(2, 2, &second_matrix, 2.0), OK);

  ck_assert_int_eq(s21_eq_matrix((s21_matrix *)NULL, &second_matrix), FAILURE);
  ck_assert_int_eq(s21_eq_matrix(&first_matrix, (s21_matrix *)NULL), FAILURE);
  ck_assert_int_eq(s21_eq_matrix((s21_matrix *)NULL, (s21_matrix *)NULL),
                   FAILURE);

  s21_remove_matrix(&first_matrix);
  s21_remove_matrix(&second_matrix);
}
END_TEST

Suite *test_s21_equal_suite(void) {
  Suite *suite = suite_create("s21_equal");
  TCase *tc = tcase_create("equal");

  tcase_add_test(tc, test_eq_succes);
  tcase_add_test(tc, test_eq_succes_1_1);

  tcase_add_test(tc, test_eq_failure);
  tcase_add_test(tc, test_eq_failure_wrong_size);
  tcase_add_test(tc, test_eq_failure_null_matrix);

  suite_add_tcase(suite, tc);
  return suite;
}
