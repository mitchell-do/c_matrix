#include "../s21_matrix.h"

/**
 * @file s21_transpose.c
 *
 * @author mitchely
 * @brief Транспонирование матрицы
 *
 * @param A  (s21_matrix*) указатель на первую матрицу
 * @param result  (s21_matrix*) указатель на результирующию матрицу
 *
 * @return OK (0 - успешное выполнение) ERROR_INCORRECT_MATRIX (1 - матрица A
 * или result равна NULL) ERROR_CALCULATION (2 - матрица не является квадратной)
 *
 * @note функция транспонирует матрицу A, после записывает результат в result
 *
 * @details элементы i j меняются на j i
 *
 *
 * @warning структура матрицы A не должна быть NULL
 * @warning матрица result не должна быть NULL
 *
 *
 */
int s21_transpose(s21_matrix *A, s21_matrix *result) {
  if (s21_check_null_matrix(A) || s21_check_null_matrix(result)) {
    return ERROR_INCORRECT_MATRIX;
  }

  int code = s21_create_matrix(A->columns, A->rows, result);

  if (code == OK) {
    for (int i = 0; i < A->columns; i++) {
      for (int j = 0; j < A->rows; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }

  return code;
}
