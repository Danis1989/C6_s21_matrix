#include "s21_matrix.h"

// Определитель матрицы (determinant), вычисление определителя

int s21_determinant(matrix_t *A, double *result) {
  if (A == NULL) return NOCORRECT; /* некорректная матрица */

  if (A->rows != A->columns) {
    *result = 0.0;
    return ERROR;
  }

  if (A->rows == 0 || A->columns == 0) {
    *result = 0.0;
    return ERROR;
  }

  double det = 0.0;
  double minor_deter = 0.0; /* определитель минора */
  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else if (A->rows > 2) {
    matrix_t mini_matrix = {0};
    for (int i = 0; i < A->rows; i++) {
      int check_matrix =
          s21_create_matrix(A->rows - 1, A->columns - 1, &mini_matrix);
      if (check_matrix == OKAY) {
        s21_minor(A, &mini_matrix, i, 0);
        s21_determinant(&mini_matrix, &minor_deter);
        int sign;
        if (i % 2 == 0) {
          sign = 1;
        } else
          sign = -1;
        det += sign * A->matrix[i][0] * minor_deter;

        s21_remove_matrix(
            &mini_matrix); /* вызываем Морфеуса и чистим матрицу */
      }
    }
    *result = det;
  }

  return OKAY;
}