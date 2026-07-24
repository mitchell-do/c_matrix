#include "test.h"

int main(void) {
  int failed = 0;

  Suite *s21_matrix_test[] = {
      test_s21_equal_suite(),        test_s21_calc_complements_suite(),
      test_s21_init_suite(),         test_s21_sum_matrix_suite(),
      test_s21_sub_matrix_suite(),   test_s21_mult_number_suite(),
      test_s21_mult_matrix_suite(),  test_s21_transpose_suite(),
      test_s21_determinant_suite(),  test_s21_inverse_matrix(),
      test_s21_helpful_func_suite(), NULL};

  for (int i = 0; s21_matrix_test[i] != NULL; i++) {
    SRunner *runner = srunner_create(s21_matrix_test[i]);

    srunner_run_all(runner, CK_NORMAL);

    failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    printf("\n");
  }

  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
