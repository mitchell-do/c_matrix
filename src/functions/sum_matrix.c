#include "../s21_matrix.h"

/**
 * @file s21_sum_matrix.c
 *
 * @author mitchely
 * @brief Сумма двух матриц
 *
 * @param A  (s21_matrix*) указатель на первую матрицу
 * @param B  (s21_matrix*) указатель на вторую матрицу
 * @param result  (s21_matrix*) указатель на результирующию матрицу
 *
 * @return OK (0 - успешное выполнение) ERROR_INCORRECT_MATRIX (1 - матрица A
 * или result равна NULL) ERROR_CALCULATION (2 - матрица не является квадратной)
 *
 * @note функция суммирует матрицу A и B, после записывает результат в result
 *
 * @details суммируем все элементы массива A И B и записываем в массив result
 *
 * @warning структура матрицы A не должна быть NULL
 * @warning структура матрицы B не должна быть NULL
 * @warning значение A->rows должа быть равна B->rows
 * @warning значение A->columns должа быть равна B->columns
 * @warning матрица result не должна быть NULL
 *
 *
 */
int s21_sum_matrix(s21_matrix *A, s21_matrix *B, s21_matrix *result) {
  int code;

  if (s21_check_null_matrix(A) || s21_check_null_matrix(B) ||
      s21_check_null_matrix(result)) {
    return ERROR_INCORRECT_MATRIX;
  }

  if (A->rows != B->rows && A->columns != B->columns) {
    return ERROR_CALCULATION;
  }

  code = s21_create_matrix(A->rows, A->columns, result);

  if (code == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }

  return code;
}
