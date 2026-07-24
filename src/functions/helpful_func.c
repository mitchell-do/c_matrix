#include "../s21_matrix.h"

/**
 * @author mitchely
 *
 * @brief Вспомогательная функция для перемещения указателя при построчном
 * заполнении матрицы
 *
 * @param A Матрица, по которой перемещается указатель
 * @param temp_row Указатель на текущую строку (инкрементируется при достижении
 * конца строки)
 * @param temp_column Указатель на текущий столбец (инкрементируется после
 * каждого элемента)
 *
 * @details
 * Алгоритм:
 * 1. Увеличивает temp_column на 1
 * 2. Если temp_column достиг конца строки (>= columns): обнуляет temp_column и
 * увеличивает temp_row на 1
 *
 */
void s21_pointer_position(int matrix_columns, int* temp_row, int* temp_column) {
  *temp_column += 1;
  if (*temp_column >= matrix_columns) {
    *temp_column = 0;
    *temp_row += 1;
  }
}

/**
 * @author mitchely
 *
 * @brief Формирует минор матрицы путем удаления указанной строки и столбца
 *
 * @param A Исходная матрица
 * @param row индекс удаляемой строки
 * @param column индекс удаляемого столбца
 * @param result Указатель на матрицу, куда будет записан минор (размером
 * (rows-1)x(cols-1))
 *
 * @details Функция получения минора пробегается по всем элемента передаваемого
 * массива, и не записывает в result_matrix удаленные строки и столбцы
 *
 * @note result должен быть предварительно создан с правильными размерами
 * @note Порядок обхода исходной матрицы - построчный слева направо
 *
 */
int s21_get_minor(s21_matrix* A, int row, int column, double* result) {
  if (s21_check_null_matrix(A)) {
    return ERROR_INCORRECT_MATRIX;
  }

  s21_matrix temp = {0};
  int code = s21_create_matrix(A->rows - 1, A->columns - 1, &temp);
  int temp_row = 0, temp_column = 0;

  if (code == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (row != i && column != j) {
          temp.matrix[temp_row][temp_column] = A->matrix[i][j];
          s21_pointer_position(temp.columns, &temp_row, &temp_column);
        }
      }
    }
    code = s21_determinant(&temp, result);
  }

  s21_remove_matrix(&temp);

  return code;
}

/**
 * @file s21_helpful_func.c
 *
 * @author mitchely
 * @brief Проверка матрицы на NULL
 *
 * @param A  (s21_matrix*) указатель на текущую матрицу
 * @param code (int*) указатель на код ошибки функции
 *

 *
 * @note функция проверяет матрицу на NULL и изменяет код OK (0 - успешное
 выполнение) ERROR_INCORRECT_MATRIX (1 - матрица A
 * или result равна NULL)
 *
 * @warning code должен быть изначально иницианизирована
 *
 *
 */
int s21_check_null_matrix(s21_matrix* value) {
  // OK - МАТРИЦА НЕ NULL
  // ERROR_INCORRECT_MATRIC - МАТРИЦА NULL
  return value == NULL ? ERROR_INCORRECT_MATRIX : OK;
}

/**
 * @brief проверка double на nan и inf
 *
 * @return 1 - все ок, 0 - либо nan, либо inf
 */
int s21_double_check(double a) { return !(isnan(a) + isinf(a)); }

/**
 * @brief сравнение двух double
 *
 * @return 1 - числа равны, 0 - числа не равны
 */
int s21_eq_double(double a, double b) {
  int code = FAILURE;

  if (s21_double_check(a) && s21_double_check(b)) {
    if (fabs(a - b) <= eps) {
      code = SUCCESS;
    }
  }

  return code;
}
