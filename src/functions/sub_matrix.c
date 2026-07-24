#include "../s21_matrix.h"

/**
 * @file s21_sub_matrix.c
 *
 * @author mitchely
 * @brief Вычитание матрицы из матрицы
 *
 * @param A  (s21_matrix*) указатель на первую матрицу
 * @param B  (s21_matrix*) указатель на вторую матрицу
 * @param result  (s21_matrix*) указатель на результирующию матрицу
 *
 * @return OK (0 - успешное выполнение) ERROR_INCORRECT_MATRIX (1 - матрица A
 * или result равна NULL) ERROR_CALCULATION (2 - матрица не является квадратной)
 *
 * @note функция вычитает из матрицы A матрицу B и записывает результат в result
 *
 * @details умножаем матрицу B на -1 и сохраняем ее в матрицу temp. Вызываем
 * функцию суммирования двух матриц для A и temp.
 *
 * @warning структура матрицы A не должна быть NULL
 * @warning структура матрицы B не должна быть NULL
 * @warning значение A->columns должа быть равна B->rows
 * @warning матрица result не должна быть NULL
 *
 *
 */
int s21_sub_matrix(s21_matrix *A, s21_matrix *B, s21_matrix *result) {
  int code;
  s21_matrix temp;

  if (s21_check_null_matrix(A) || s21_check_null_matrix(B) ||
      s21_check_null_matrix(result)) {
    return ERROR_INCORRECT_MATRIX;
  }

  code = s21_mult_number(B, -1.0, &temp);

  if (code == OK) {
    code = s21_sum_matrix(A, &temp, result);

    if (code == OK) {
      s21_remove_matrix(&temp);
    }
  }

  return code;
}
