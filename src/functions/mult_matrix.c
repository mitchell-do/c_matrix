#include "../s21_matrix.h"

/**
 * @file s21_mult_matrix.c
 *
 * @author mitchely
 * @brief Умножение матрицы на матрицу
 *
 * @param A  (s21_matrix*) указатель на первую матрицу
 * @param B  (s21_matrix*) указатель на вторую матрицу
 * @param result  (s21_matrix*) указатель на результирующию матрицу
 *
 * @return OK (0 - успешное выполнение) ERROR_INCORRECT_MATRIX (1 - матрица A
 * или result равна NULL) ERROR_CALCULATION (2 - матрица не является квадратной)
 *
 * @note функция перемножает две матрицы A и B и записывает результат в result
 * @details Создаем матрицу result. Перебираем все элементы result. для каждого
 * элемента мы суммируем все произведения i-ой строки матрицы A на j-столбец
 * матрицы B
 *
 * @warning структура матрицы A не должна быть NULL
 * @warning структура матрицы B не должна быть NULL
 * @warning значение A->columns должа быть равна B->rows
 * @warning матрица result не должна быть NULL
 *
 *
 */
int s21_mult_matrix(s21_matrix *A, s21_matrix *B, s21_matrix *result) {
  int code;

  // проверка на null матриц
  if (s21_check_null_matrix(A) || s21_check_null_matrix(B) ||
      s21_check_null_matrix(result)) {
    return ERROR_INCORRECT_MATRIX;
  }

  if (A->columns != B->rows) {
    return ERROR_CALCULATION;
  }

  code = s21_create_matrix(A->rows, B->columns, result);

  if (code == OK) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        for (int x = 0; x < A->columns; x++) {
          result->matrix[i][j] += A->matrix[i][x] * B->matrix[x][j];
        }
      }
    }
  }

  return code;
}