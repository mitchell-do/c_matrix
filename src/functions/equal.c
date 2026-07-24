#include "../s21_matrix.h"

/**
 * @file s21_equal.c
 * @author mitchely
 *
 * @brief Сравнение двух матриц
 *
 * @details
 *Определитель матрицы равен сумме произведений элементов строки (столбца) на
соответствующие алгебраические дополнения
 *
 * @param A (s21_matrix*) Указатель на первую матрицу
 * @param B (s21_matrix*) Указатель на вторую матрицу
результат

* @return Коды сравнения:
 *         SUCCESS (1) - матрицы равны
 *         FAILURE (0) - матрицы не равны
 *
 * @details алгоритм для матрицы nxn (n > 0)
 * 1. сравнение размерности двух матриц
 * 2. сравниваем каждый элемент из первой матрицы с каждым элементом из второй
матрицы (тк значение double, то для сравнения требуется EPS)
 *

 * @warning Входная матрица A должна быть корректно инициализирована
 * @warning Входная матрица B должна быть корректно инициализирована

 */
int s21_eq_matrix(s21_matrix* A, s21_matrix* B) {
  int code = SUCCESS;

  if (!A || !B) {
    return FAILURE;
  }

  if (A->rows != B->rows || A->columns != B->columns) {
    return FAILURE;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (!s21_eq_double(A->matrix[i][j], B->matrix[i][j])) {
        code = FAILURE;
      }
    }
  }

  return code;
}