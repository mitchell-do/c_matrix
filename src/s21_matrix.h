#ifndef S21_MATRIX
#define S21_MATRIX

#define SUCCESS 1
#define FAILURE 0

#define OK 0
#define ERROR_INCORRECT_MATRIX 1
#define ERROR_CALCULATION 2

#include <math.h>
#include <stdlib.h>

#define eps 0.00000001

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} s21_matrix;

int s21_create_matrix(int rows, int columns, s21_matrix *result);
void s21_remove_matrix(s21_matrix *A);
int s21_eq_matrix(s21_matrix *A, s21_matrix *B);

int s21_sum_matrix(s21_matrix *A, s21_matrix *B, s21_matrix *result);
int s21_sub_matrix(s21_matrix *A, s21_matrix *B, s21_matrix *result);

int s21_mult_number(s21_matrix *A, double number, s21_matrix *result);
int s21_mult_matrix(s21_matrix *A, s21_matrix *B, s21_matrix *result);

int s21_transpose(s21_matrix *A, s21_matrix *result);
int s21_calc_complements(s21_matrix *A, s21_matrix *result);
int s21_determinant(s21_matrix *A, double *result);
int s21_inverse_matrix(s21_matrix *A, s21_matrix *result);

// дополнительные функции

int s21_check_null_matrix(s21_matrix *value);
int s21_eq_double(double a, double b);
int s21_double_check(double a);
int s21_get_minor(s21_matrix *A, int row, int column, double *result);
void s21_pointer_position(int matrix_columns, int *temp_row, int *temp_column);

#endif