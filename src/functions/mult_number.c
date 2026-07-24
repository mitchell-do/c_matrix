#include "../s21_matrix.h"

/**
 * @file s21_mult_numbers.c
 *
 * @author mitchely
 * @brief Умножение матрицы на число
 *
 * @param A  (s21_matrix*) указатель на первую матрицу
 * @param number  (double) число умножаемое на матрицу
 * @param result  (s21_matrix*) указатель на результирующию матрицу
 *
 * @return OK (0 - успешное выполнение) ERROR_INCORRECT_MATRIX (1 - матрица A
 * или result равна NULL) ERROR_CALCULATION (2 - матрица не является квадратной)
 *
 * @note функция перемножает матрицу на число и записывает результат в result
 * @details Создаем матрицу result. Перебираем все элементы матрицы A и
 * перемножаем на число number , после чего сохраняем элемент в матрицу result
 *
 * @warning структура матрицы A не должна быть NULL
 * @warning матрица result не должна быть NULL
 *
 *
 */
int s21_mult_number(s21_matrix *A, double number, s21_matrix *result) {
  int code;

  // проверка на NULL указатели
  if (s21_check_null_matrix(A) || s21_check_null_matrix(result) ||
      !s21_double_check(number)) {
    return ERROR_INCORRECT_MATRIX;
  }

  code = s21_create_matrix(A->rows, A->columns, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }

  return code;
}
