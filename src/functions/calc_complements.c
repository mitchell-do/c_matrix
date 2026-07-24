#include "../s21_matrix.h"

int s21_calc_complements_logic(s21_matrix* A, s21_matrix* result);
void s21_calc_complements_logic_double_matrix(s21_matrix* A,
                                              s21_matrix* result);
void s21_pointer_position(int matrix_columns, int* temp_row, int* temp_column);

/**
 * @file s21_calc_complements.c
 * @author mitchely
 *
 * @brief Вычисление матрицы алгебраических дополнений
 *
 * @details
 *Алгебраическое дополнение A_ij = (-1)^(i+j) * M_ij, где M_ij - определитель
 минора, полученного вычеркиванием i-й строки и j-го столбца.
 *
 * @param A (s21_matrix*) Указатель на исходную квадратную матрицу
 * @param result (s21_matrix*) Указатель на матрицу, куда будет записан
результат (создается внутри)

* @return Код ошибки:
 *         1. OK (0) - успешное выполнение
 *         2. ERROR_INCORRECT_MATRIX (1) - матрица A или result равна NULL
 *         3. ERROR_CALCULATION (2) - матрица не является квадратной

 * @note Результат для матрицы 1x1 всегда равен исходному элементу
 * @note Для матрицы 2x2 используется оптимизированный алгоритм, тк основной не
работает определителя
 * @note Для матриц размером NxN (s21_calc_complements_logic) создаем временный
 * массив temp. после чего для каждого элемента ищем минор (s21_get_minor) и
 сохраняем в temp,
 * после мы считаем определитель минора и сохраняем ответ в result. после мы
 считаем знак для элемента
миноры

 * @warning Входная матрица A должна быть корректно инициализирована
 * @warning Результат необходимо освободить через s21_remove_matrix()
 */

int s21_calc_complements(s21_matrix* A, s21_matrix* result) {
  int code;

  if (s21_check_null_matrix(A) || s21_check_null_matrix(result)) {
    return ERROR_INCORRECT_MATRIX;
  }

  if (A->rows != A->columns) {
    return ERROR_CALCULATION;
  }

  code = s21_create_matrix(A->rows, A->columns, result);

  if (code == OK) {
    if (A->rows == 1) {
      result->matrix[0][0] = A->matrix[0][0];
    } else if (A->rows == 2) {
      s21_calc_complements_logic_double_matrix(A, result);
    } else {
      code = s21_calc_complements_logic(A, result);
    }
  }

  return code;
}

/**
 * @author mitchely
 * @brief Оптимизированное вычисление алгебраических дополнений для матрицы 2x2
 *
 * Для матрицы [[a, b], [c, d]]:
 * - A00 = +d
 * - A01 = -c
 * - A10 = -b
 * - A11 = +a
 *
 * @param A (s21_matrix*) Исходная матрица 2x2
 * @param result (s21_matrix*) Матрица для результата (создана в
 * s21_calc_complements)
 */
void s21_calc_complements_logic_double_matrix(s21_matrix* A,
                                              s21_matrix* result) {
  for (int i = 0; i < 2; i++) {
    result->matrix[i][0] = A->matrix[!i][1];
    result->matrix[i][1] = A->matrix[!i][0];
  }

  result->matrix[0][1] *= -1;
  result->matrix[1][0] *= -1;
}

/**
 * @author mitchely
 *
 * @brief Основная логика вычисления алгебраических дополнений для матриц n x n
 * (n>2)
 *
 * @details Алгоритм:
 * 1. Создается временная матрица размером [n-1]x[n-1] для хранения миноров
 * 2. Для каждого элемента (i,j) исходной матрицы:
 *    a) Получаем минор (высчитываем матрицу, удаляя i - строку и j - столбец)
 *    b) Вычисляем определитель минора
 *    c) Применяем знак (-1)^(i+j) (если i+j четное то умножаем на +1, в
 * остальных случаях на -1)
 * 3. Освобождаем временную матрицу
 *
 * @param A (s21_matrix*) Исходная матрица (размер >2)
 * @param result (s21_matrix*) Матрица для результата (должна быть создана
 * заранее)
 * @return Код ошибки при вычислении определителя или OK (0)
 *
 */
int s21_calc_complements_logic(s21_matrix* A, s21_matrix* result) {
  int code = OK;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (code == OK) {
        code = s21_get_minor(A, i, j, &result->matrix[i][j]);

        result->matrix[i][j] *= (i + j) % 2 == 0 ? 1.0 : -1.0;
      }
    }
  }

  return code;
}
