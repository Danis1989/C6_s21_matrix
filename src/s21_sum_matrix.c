#include "s21_matrix.h"

// Сложение (sum_matrix)

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OKAY;
  if (s21_check_matrix(A) == 1 || s21_check_matrix(B) == 1) {
    return NOCORRECT;
  } else if ((A->rows != B->rows) || (A->columns != B->columns)) {
    return ERROR;
  } else {
    int check = s21_create_matrix(A->rows, B->columns, result);
    if (check == OKAY) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = B->matrix[i][j] + A->matrix[i][j];
        }
      }
    } else
      status = 1;
  }

  return status;
}
