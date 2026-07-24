#include "./test.h"

int create_matrix_with_nums(int rows, int columns, s21_matrix *A, double n) {
  int code = s21_create_matrix(rows, columns, A);

  if (code == OK) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        A->matrix[i][j] = n;
      }
    }
  }

  return code;
}

void eq_double(double a, double b) {
  int code = OK;

  if (fabs(a - b) > eps) {
    code = 1;
  }

  ck_assert_int_eq(code, OK);
}