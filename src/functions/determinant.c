#include <stdio.h>

#include "../s21_matrix.h"

/**
 * @file s21_determinant.c
 * @author mitchely
 *
 * @brief Вычисление определителя матрицы
 *
 * @details
 *Определитель матрицы равен сумме произведений элементов строки (столбца) на
соответствующие алгебраические дополнения
 *
 * @param A (s21_matrix*) Указатель на исходную квадратную матрицу
 * @param result (double*) Указатель на определитель, куда будет записан
результат

* @return Код ошибки:
 *         OK (0) - успешное выполнение
 *         ERROR_INCORRECT_MATRIX (1) - матрица A или result равна NULL
 *         ERROR_CALCULATION (2) - матрица не является квадратной

 * @note Результат для матрицы 1x1 всегда равен исходному элементу
 * @details алгоритм для матрицы nxn (n > 1)
 * 1. копируем исходную матрицу в temp
 * 2. переворачиваем матрицу temp (s21_permutation_matrix)
 * 3. считаем положительную часть определителя матрицы A
 * 4. считаем положительную часть определителя матрицы temp
 * 5. вычитаем результат 4 из результата 3
 * 6. удаляем матрицу temp из памяти
 *
 * @warning Входная матрица A должна быть корректно инициализирована
 */
int s21_determinant(s21_matrix* A, double* result) {
  int code = OK;

  if (s21_check_null_matrix(A)) {
    return ERROR_INCORRECT_MATRIX;
  }

  if (A->rows != A->columns) {
    return ERROR_CALCULATION;
  }

  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result +=
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    double temp = 0.0;
    for (int j = 0; j < A->columns; j++) {
      if (code == OK) {
        double minor = 0.0;
        code = s21_get_minor(A, 0, j, &minor);

        temp += (1 - 2 * (j % 2)) * minor * A->matrix[0][j];
      }
    }
    if (code == OK) {
      *result = temp;
    }
  }
  return code;
}
