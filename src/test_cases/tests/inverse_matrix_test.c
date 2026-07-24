#include "../test.h"

START_TEST(test_inverse_matrix_simple_2_2) {
  s21_matrix first_matrix;
  s21_matrix result_matrix;
  s21_matrix exception_matrix;

  ck_assert_int_eq(s21_create_matrix(2, 2, &first_matrix), OK);
  ck_assert_int_eq(s21_create_matrix(2, 2, &exception_matrix), OK);

  first_matrix.matrix[0][0] = 2.0;
  first_matrix.matrix[0][1] = -2.0;
  first_matrix.matrix[1][0] = 2.0;
  first_matrix.matrix[1][1] = 2.0;

  exception_matrix.matrix[0][0] = 0.25;
  exception_matrix.matrix[0][1] = 0.25;
  exception_matrix.matrix[1][0] = -0.25;
  exception_matrix.matrix[1][1] = 0.25;

  ck_assert_int_eq(s21_inverse_matrix(&first_matrix, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &exception_matrix), SUCCESS);

  s21_remove_matrix(&first_matrix);
  s21_remove_matrix(&exception_matrix);
  s21_remove_matrix(&result_matrix);
}
END_TEST

START_TEST(test_inverse_matrix_simple_1_1) {
  s21_matrix first_matrix;
  s21_matrix result_matrix;
  s21_matrix excpeted_matrix;
  ck_assert_int_eq(create_matrix_with_nums(1, 1, &first_matrix, 2.0), OK);
  ck_assert_int_eq(create_matrix_with_nums(1, 1, &excpeted_matrix, 0.5), OK);

  ck_assert_int_eq(s21_inverse_matrix(&first_matrix, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&excpeted_matrix, &result_matrix), SUCCESS);

  s21_remove_matrix(&first_matrix);
  s21_remove_matrix(&result_matrix);
  s21_remove_matrix(&excpeted_matrix);
}
END_TEST

START_TEST(test_inverse_matrix_simple_2_3) {
  s21_matrix first_matrix;
  s21_matrix result_matrix;

  ck_assert_int_eq(create_matrix_with_nums(2, 3, &first_matrix, 2.0), OK);

  ck_assert_int_eq(s21_inverse_matrix(&first_matrix, &result_matrix),
                   ERROR_CALCULATION);

  s21_remove_matrix(&first_matrix);
}
END_TEST

START_TEST(test_inverse_matrix_simple_3_3) {
  s21_matrix first_matrix;
  s21_matrix result_matrix;
  s21_matrix exception_matrix;

  ck_assert_int_eq(s21_create_matrix(3, 3, &first_matrix), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &exception_matrix), OK);

  first_matrix.matrix[0][0] = 2.0;
  first_matrix.matrix[0][1] = 5.0;
  first_matrix.matrix[0][2] = 7.0;

  first_matrix.matrix[1][0] = 6.0;
  first_matrix.matrix[1][1] = 3.0;
  first_matrix.matrix[1][2] = 4.0;

  first_matrix.matrix[2][0] = 5.0;
  first_matrix.matrix[2][1] = -2.0;
  first_matrix.matrix[2][2] = -3.0;

  exception_matrix.matrix[0][0] = 1.0;
  exception_matrix.matrix[0][1] = -1.0;
  exception_matrix.matrix[0][2] = 1.0;

  exception_matrix.matrix[1][0] = -38.0;
  exception_matrix.matrix[1][1] = 41.0;
  exception_matrix.matrix[1][2] = -34.0;

  exception_matrix.matrix[2][0] = 27.0;
  exception_matrix.matrix[2][1] = -29.0;
  exception_matrix.matrix[2][2] = 24.0;

  ck_assert_int_eq(s21_inverse_matrix(&first_matrix, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &exception_matrix), SUCCESS);

  s21_remove_matrix(&first_matrix);
  s21_remove_matrix(&exception_matrix);
  s21_remove_matrix(&result_matrix);
}
END_TEST

START_TEST(test_inverse_matrix_simple_4_4) {
  s21_matrix first_matrix;
  s21_matrix result_matrix;
  s21_matrix exception_matrix;

  ck_assert_int_eq(s21_create_matrix(4, 4, &first_matrix), OK);
  ck_assert_int_eq(s21_create_matrix(4, 4, &exception_matrix), OK);

  first_matrix.matrix[0][0] = 1.0;
  first_matrix.matrix[0][1] = 1.0;
  first_matrix.matrix[0][2] = -1.0;
  first_matrix.matrix[0][3] = 1.0;

  first_matrix.matrix[1][0] = 1.0;
  first_matrix.matrix[1][1] = -1.0;
  first_matrix.matrix[1][2] = 2.0;
  first_matrix.matrix[1][3] = -1.0;

  first_matrix.matrix[2][0] = 2.0;
  first_matrix.matrix[2][1] = 1.0;
  first_matrix.matrix[2][2] = -1.0;
  first_matrix.matrix[2][3] = 1.0;

  first_matrix.matrix[3][0] = 2.0;
  first_matrix.matrix[3][1] = 2.0;
  first_matrix.matrix[3][2] = 0.0;
  first_matrix.matrix[3][3] = 1.0;

  exception_matrix.matrix[0][0] = -1.0;
  exception_matrix.matrix[0][1] = 0.0;
  exception_matrix.matrix[0][2] = 1.0;
  exception_matrix.matrix[0][3] = 0.0;

  exception_matrix.matrix[1][0] = -3.0;
  exception_matrix.matrix[1][1] = -1.0;
  exception_matrix.matrix[1][2] = 1.0;
  exception_matrix.matrix[1][3] = 1.0;

  exception_matrix.matrix[2][0] = 3.0;
  exception_matrix.matrix[2][1] = 1.0;
  exception_matrix.matrix[2][2] = -2.0;
  exception_matrix.matrix[2][3] = 0.0;

  exception_matrix.matrix[3][0] = 8.0;
  exception_matrix.matrix[3][1] = 2.0;
  exception_matrix.matrix[3][2] = -4.0;
  exception_matrix.matrix[3][3] = -1.0;

  ck_assert_int_eq(s21_inverse_matrix(&first_matrix, &result_matrix), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &exception_matrix), SUCCESS);

  s21_remove_matrix(&first_matrix);
  s21_remove_matrix(&exception_matrix);
  s21_remove_matrix(&result_matrix);
}
END_TEST

START_TEST(test_inverse_matrix_much) {
  s21_matrix first_matrix;
  s21_matrix result_matrix;
  s21_matrix exception_matrix;

  ck_assert_int_eq(s21_create_matrix(4, 4, &first_matrix), OK);
  ck_assert_int_eq(s21_create_matrix(4, 4, &exception_matrix), OK);

  first_matrix.matrix[0][0] = 1.0;
  first_matrix.matrix[0][1] = 1.0;
  first_matrix.matrix[0][2] = -1.0;
  first_matrix.matrix[0][3] = 1.0;

  first_matrix.matrix[1][0] = 1.0;
  first_matrix.matrix[1][1] = -1.0;
  first_matrix.matrix[1][2] = 2.0;
  first_matrix.matrix[1][3] = -1.0;

  first_matrix.matrix[2][0] = 2.0;
  first_matrix.matrix[2][1] = 1.0;
  first_matrix.matrix[2][2] = -1.0;
  first_matrix.matrix[2][3] = 1.0;

  first_matrix.matrix[3][0] = 2.0;
  first_matrix.matrix[3][1] = 2.0;
  first_matrix.matrix[3][2] = 0.0;
  first_matrix.matrix[3][3] = 1.0;

  exception_matrix.matrix[0][0] = -1.0;
  exception_matrix.matrix[0][1] = 0.0;
  exception_matrix.matrix[0][2] = 1.0;
  exception_matrix.matrix[0][3] = 0.0;

  exception_matrix.matrix[1][0] = -3.0;
  exception_matrix.matrix[1][1] = -1.0;
  exception_matrix.matrix[1][2] = 1.0;
  exception_matrix.matrix[1][3] = 1.0;

  exception_matrix.matrix[2][0] = 3.0;
  exception_matrix.matrix[2][1] = 1.0;
  exception_matrix.matrix[2][2] = -2.0;
  exception_matrix.matrix[2][3] = 0.0;

  exception_matrix.matrix[3][0] = 8.0;
  exception_matrix.matrix[3][1] = 2.0;
  exception_matrix.matrix[3][2] = -4.0;
  exception_matrix.matrix[3][3] = -1.0;

  for (int i = 0; i < 1000; i++) {
    ck_assert_int_eq(s21_inverse_matrix(&first_matrix, &result_matrix), OK);
    ck_assert_int_eq(s21_eq_matrix(&result_matrix, &exception_matrix), SUCCESS);
    s21_remove_matrix(&result_matrix);
  }

  s21_remove_matrix(&first_matrix);
  s21_remove_matrix(&exception_matrix);
}
END_TEST

START_TEST(test_inverse_matrix_null) {
  s21_matrix result_matrix;

  ck_assert_int_eq(s21_inverse_matrix((s21_matrix*)NULL, &result_matrix),
                   ERROR_INCORRECT_MATRIX);
  ck_assert_int_eq(s21_inverse_matrix(&result_matrix, (s21_matrix*)NULL),
                   ERROR_INCORRECT_MATRIX);
  ck_assert_int_eq(s21_inverse_matrix((s21_matrix*)NULL, (s21_matrix*)NULL),
                   ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_inverse_matrix_zero_determinator) {
  s21_matrix first_matrix;
  s21_matrix result_matrix;
  ck_assert_int_eq(create_matrix_with_nums(2, 2, &first_matrix, 2.0), OK);

  ck_assert_int_eq(s21_inverse_matrix(&first_matrix, &result_matrix),
                   ERROR_CALCULATION);
  s21_remove_matrix(&first_matrix);
}
END_TEST

START_TEST(test_s21_inverse_matrix_small_values) {
  s21_matrix A, result;
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), OK);

  A.matrix[0][0] = 1e-3;
  A.matrix[0][1] = 2e-3;
  A.matrix[1][0] = 3e-3;
  A.matrix[1][1] = 4e-3;

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_double_eq_tol(result.matrix[0][0], -2e3, 1e-7);
  ck_assert_double_eq_tol(result.matrix[0][1], 1e3, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][0], 1.5e3, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][1], -0.5e3, 1e-7);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_inverse_matrix_identity) {
  s21_matrix A, result, I;

  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &I), OK);

  // Создаем единичную матрицу
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = (i == j) ? 1.0 : 0.0;
      I.matrix[i][j] = (i == j) ? 1.0 : 0.0;
    }
  }

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &I), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&I);
}
END_TEST

START_TEST(test_s21_inverse_matrix_4x4) {
  s21_matrix A, result, expected;
  ck_assert_int_eq(s21_create_matrix(4, 4, &A), OK);
  ck_assert_int_eq(s21_create_matrix(4, 4, &expected), OK);

  double src[4][4] = {{2, 1, 0, 0}, {3, 2, 0, 0}, {1, 1, 3, 4}, {2, -1, 2, 3}};
  double inv[4][4] = {
      {2, -1, 0, 0}, {-3, 2, 0, 0}, {31, -19, 3, -4}, {-23, 14, -2, 3}};

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      A.matrix[i][j] = src[i][j];
      expected.matrix[i][j] = inv[i][j];
    }
  }
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

Suite* test_s21_inverse_matrix(void) {
  Suite* suite = suite_create("s21_inverse_matrix");
  TCase* tc = tcase_create("inverse_matrix");

  tcase_add_test(tc, test_inverse_matrix_simple_1_1);
  tcase_add_test(tc, test_inverse_matrix_simple_2_2);
  tcase_add_test(tc, test_inverse_matrix_simple_2_3);
  tcase_add_test(tc, test_inverse_matrix_simple_3_3);
  tcase_add_test(tc, test_inverse_matrix_simple_4_4);
  tcase_add_test(tc, test_inverse_matrix_much);
  tcase_add_test(tc, test_s21_inverse_matrix_small_values);
  tcase_add_test(tc, test_s21_inverse_matrix_identity);
  tcase_add_test(tc, test_s21_inverse_matrix_4x4);

  tcase_add_test(tc, test_inverse_matrix_null);
  tcase_add_test(tc, test_inverse_matrix_zero_determinator);

  suite_add_tcase(suite, tc);
  return suite;
}