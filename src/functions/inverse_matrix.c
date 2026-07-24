
#include "../s21_matrix.h"
/**
 * @file s21_inverse_matrix.c
 *
 * @author mitchely
 * @brief Инверсирование матрицы
 *
 * @param A  (s21_matrix*) указатель на текущую матрицу
 * @param result  (s21_matrix*) указатель на результирующию матрицу
 *
 * @return OK (0 - успешное выполнение) ERROR_INCORRECT_MATRIX (1 - матрица A
 * или result равна NULL) ERROR_CALCULATION (2 - матрица не является квадратной)
 *
 * @note функция инверсирует исходную матрицу A и сохраняет в матрицу result
 * @details Сначала ищем матрицу дополнений и сохраняем ее в temp1. После
 * транспонируем temp1 и сохраняем в temp2. Матрицу temp2 умножаем на
 * 1/(определитель матрицы). В случае если определитель матрицы равен нулю,
 * выдаем ошибку error_calculation
 *
 * @warning Определитель матрицы A не равен 0. Иначе error_calculation
 * @warning структура матрицы A не должна быть NULL
 * @warning матрица result не должна быть NULL
 *
 *
 */

int s21_inverse_matrix(s21_matrix* A, s21_matrix* result) {
  if (s21_check_null_matrix(A) || s21_check_null_matrix(result)) {
    return ERROR_INCORRECT_MATRIX;
  }

  if (A->rows != A->columns) {
    return ERROR_CALCULATION;
  }

  double deter = 0.0;

  int code = s21_determinant(A, &deter);

  if (code == OK && s21_eq_double(deter, 0.0)) {
    return ERROR_CALCULATION;
  }

  if (A->rows == 1) {
    code = s21_create_matrix(1, 1, result);
    if (code == OK) {
      result->matrix[0][0] = 1.0 / A->matrix[0][0];
    }
  } else {
    s21_matrix temp1, temp2;

    if (code == OK) {
      code = s21_calc_complements(A, &temp1);
    }

    if (code == OK) {
      code = s21_transpose(&temp1, &temp2);
    }

    if (code == OK) {
      code = s21_mult_number(&temp2, 1.0 / deter, result);
    }

    s21_remove_matrix(&temp1);
    s21_remove_matrix(&temp2);
  }

  return code;
}
