#include "s21_matrix.h"

// Умножение матрицы на число (mult_number)

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int success = -1;
  if (s21_check_matrix(A) == 1) return 1;
  if (s21_check_matrix(A) == 2) return 2;
  int check = s21_create_matrix(A->rows, A->columns, result);

  if (check == 0) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
    success = 0; /* успех 0*/
  } else
    success = 1; /* ошибка вычилений и прочее не успех 1 */

  return success;
}