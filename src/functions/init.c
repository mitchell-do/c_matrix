#include "../s21_matrix.h"

/**
 * @file s21_init.c
 *
 * @author mitchely
 * @brief создание матрицы размером ROWSxCOLUMNS
 *
 * @param rows - (int) кол-во строк в матрице
 * @param columns - (int) кол-во столбцов в матрице
 * @param result - (s21_matrix*) указатель на будущую матрицу
 *
 * @note функция выделяет память для матрицы result с помощью calloc
 *
 * @warning rows и columns должы быть > 0
 * @warning result не должен быть NULL
 *
 */

int s21_create_matrix(int rows, int columns, s21_matrix* result) {
  int code = OK;

  if (s21_check_null_matrix(result) || rows < 1 || columns < 1) {
    return ERROR_INCORRECT_MATRIX;
  }

  result->columns = columns;
  result->rows = rows;

  result->matrix = calloc(sizeof(double*), rows);
  for (int i = 0; i < rows; i++) {
    *(result->matrix + i) = calloc(sizeof(double), columns);
  }

  return code;
}

/**
 * @file s21_init.c
 *
 * @author mitchely
 * @brief Удаление матрицы A
 *
 * @param A - (s21_matrix*) указатель на текущую матрицу
 *
 * @note функция освобождает выделенную под матрицу в памяти пробегаяс по каждой
 * строчке матрицы
 *
 * @warning структура матрицы A не должна быть NULL
 * @warning матрица A->matrix не должна быть NULL
 *
 *
 */
void s21_remove_matrix(s21_matrix* A) {
  if (s21_check_null_matrix(A) == OK) {
    if (A->matrix != NULL) {
      for (int i = 0; i < A->rows; i++) {
        free(A->matrix[i]);
      }
      free(A->matrix);
    }
  }

  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
}
