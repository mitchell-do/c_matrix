#include "../test.h"

START_TEST(test_calc_comp_zero_m) {
  s21_matrix first_matrix;
  s21_matrix result_matrix;
  s21_matrix expected_result_matrix;

  ck_assert_int_eq(create_matrix_with_nums(3, 3, &first_matrix, 2), OK);
  ck_assert_int_eq(create_matrix_with_nums(3, 3, &expected_result_matrix, 0),
                   OK);

  ck_assert_int_eq(s21_calc_complements(&first_matrix, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected_result_matrix),
                   SUCCESS);

  s21_remove_matrix(&first_matrix);
  s21_remove_matrix(&result_matrix);
  s21_remove_matrix(&expected_result_matrix);
}
END_TEST

START_TEST(test_calc_comp_2_2) {
  s21_matrix first_matrix;
  s21_matrix result_matrix;
  s21_matrix expected_result_matrix;

  ck_assert_int_eq(create_matrix_with_nums(2, 2, &first_matrix, 2), OK);
  ck_assert_int_eq(s21_create_matrix(2, 2, &expected_result_matrix), OK);
  expected_result_matrix.matrix[0][0] = 2;
  expected_result_matrix.matrix[0][1] = -2;
  expected_result_matrix.matrix[1][0] = -2;
  expected_result_matrix.matrix[1][1] = 2;

  ck_assert_int_eq(s21_calc_complements(&first_matrix, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected_result_matrix),
                   SUCCESS);

  s21_remove_matrix(&first_matrix);
  s21_remove_matrix(&result_matrix);
  s21_remove_matrix(&expected_result_matrix);
}
END_TEST

START_TEST(test_calc_comp_1_1) {
  s21_matrix first_matrix;
  s21_matrix result_matrix;
  s21_matrix expected_matrix;

  ck_assert_int_eq(create_matrix_with_nums(1, 1, &first_matrix, 2), OK);
  ck_assert_int_eq(create_matrix_with_nums(1, 1, &expected_matrix, 2), OK);

  first_matrix.matrix[0][0] = -9.0;
  expected_matrix.matrix[0][0] = -9.0;

  ck_assert_int_eq(s21_calc_complements(&first_matrix, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&expected_matrix, &result_matrix), SUCCESS);

  s21_remove_matrix(&first_matrix);
  s21_remove_matrix(&expected_matrix);
  s21_remove_matrix(&result_matrix);
}
END_TEST

START_TEST(test_calc_comp_big_matrix) {
  s21_matrix first_matrix;
  s21_matrix result_matrix;
  s21_matrix expected_result_matrix;

  ck_assert_int_eq(create_matrix_with_nums(4, 4, &first_matrix, 21.0), OK);
  ck_assert_int_eq(create_matrix_with_nums(4, 4, &expected_result_matrix, 0),
                   OK);

  ck_assert_int_eq(s21_calc_complements(&first_matrix, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected_result_matrix),
                   SUCCESS);

  s21_remove_matrix(&first_matrix);
  s21_remove_matrix(&result_matrix);
  s21_remove_matrix(&expected_result_matrix);
}
END_TEST

START_TEST(test_calc_comp_2_2_full) {
  s21_matrix first_matrix;
  s21_matrix result_matrix;
  s21_matrix expected_result_matrix;

  ck_assert_int_eq(s21_create_matrix(2, 2, &first_matrix), OK);
  ck_assert_int_eq(s21_create_matrix(2, 2, &expected_result_matrix), OK);

  first_matrix.matrix[0][0] = -3.0;
  first_matrix.matrix[0][1] = 9.0;
  first_matrix.matrix[1][0] = -3.9;
  first_matrix.matrix[1][1] = 100.0;

  expected_result_matrix.matrix[0][0] = 100.0;
  expected_result_matrix.matrix[0][1] = 3.9;
  expected_result_matrix.matrix[1][0] = -9.0;
  expected_result_matrix.matrix[1][1] = -3.0;

  ck_assert_int_eq(s21_calc_complements(&first_matrix, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected_result_matrix),
                   SUCCESS);

  s21_remove_matrix(&first_matrix);
  s21_remove_matrix(&result_matrix);
  s21_remove_matrix(&expected_result_matrix);
}
END_TEST

START_TEST(test_calc_comp_error_wrong_matrix) {
  s21_matrix first_matrix;
  s21_matrix result_matrix;

  ck_assert_int_eq(create_matrix_with_nums(2, 3, &first_matrix, 9.0), OK);

  ck_assert_int_eq(s21_calc_complements(&first_matrix, &result_matrix),
                   ERROR_CALCULATION);

  s21_remove_matrix(&first_matrix);
}
END_TEST

START_TEST(test_calc_comp_error_null_matrix) {
  s21_matrix result_matrix;

  ck_assert_int_eq(s21_calc_complements((s21_matrix *)NULL, &result_matrix),
                   ERROR_INCORRECT_MATRIX);
  ck_assert_int_eq(s21_calc_complements((s21_matrix *)NULL, (s21_matrix *)NULL),
                   ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_calc_comp_simple) {
  s21_matrix first_matrix;
  s21_matrix result_matrix;
  s21_matrix expected_result_matrix;

  ck_assert_int_eq(s21_create_matrix(3, 3, &first_matrix), OK);

  first_matrix.matrix[0][0] = 1.0;
  first_matrix.matrix[0][1] = 2.0;
  first_matrix.matrix[0][2] = 3.0;

  first_matrix.matrix[1][0] = 0.0;
  first_matrix.matrix[1][1] = 4.0;
  first_matrix.matrix[1][2] = 2.0;

  first_matrix.matrix[2][0] = 5.0;
  first_matrix.matrix[2][1] = 2.0;
  first_matrix.matrix[2][2] = 1.0;

  ck_assert_int_eq(s21_create_matrix(3, 3, &expected_result_matrix), OK);

  expected_result_matrix.matrix[0][0] = 0.0;
  expected_result_matrix.matrix[0][1] = 10.0;
  expected_result_matrix.matrix[0][2] = -20.0;

  expected_result_matrix.matrix[1][0] = 4.0;
  expected_result_matrix.matrix[1][1] = -14.0;
  expected_result_matrix.matrix[1][2] = 8.0;

  expected_result_matrix.matrix[2][0] = -8.0;
  expected_result_matrix.matrix[2][1] = -2.0;
  expected_result_matrix.matrix[2][2] = 4.0;

  ck_assert_int_eq(s21_calc_complements(&first_matrix, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected_result_matrix),
                   SUCCESS);

  s21_remove_matrix(&first_matrix);
  s21_remove_matrix(&result_matrix);
  s21_remove_matrix(&expected_result_matrix);
}
END_TEST

START_TEST(test_calc_complements_memory_leak) {
  s21_matrix A;
  s21_matrix result;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 0.0;
  A.matrix[0][2] = 0.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 1.0;
  A.matrix[1][2] = 0.0;
  A.matrix[2][0] = 0.0;
  A.matrix[2][1] = 0.0;
  A.matrix[2][2] = 1.0;

  for (int i = 0; i < 100; i++) {
    int code = s21_calc_complements(&A, &result);
    ck_assert_int_eq(code, OK);
    s21_remove_matrix(&result);
  }

  s21_remove_matrix(&A);
}
END_TEST

Suite *test_s21_calc_complements_suite(void) {
  Suite *suite = suite_create("s21_calc_complements");
  TCase *tc = tcase_create("calc_complements");

  tcase_add_test(tc, test_calc_comp_zero_m);
  tcase_add_test(tc, test_calc_comp_simple);
  tcase_add_test(tc, test_calc_comp_2_2);
  tcase_add_test(tc, test_calc_comp_2_2_full);
  tcase_add_test(tc, test_calc_comp_error_wrong_matrix);
  tcase_add_test(tc, test_calc_comp_big_matrix);
  tcase_add_test(tc, test_calc_comp_error_null_matrix);
  tcase_add_test(tc, test_calc_complements_memory_leak);
  tcase_add_test(tc, test_calc_comp_1_1);

  suite_add_tcase(suite, tc);
  return suite;
}
