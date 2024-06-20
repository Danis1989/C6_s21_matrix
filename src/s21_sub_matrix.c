#include "s21_matrix.h"

// Вычитание матриц

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = 0;
  if (s21_check_matrix(A) == 1 || s21_check_matrix(B) == 1) {
    status = 1;
  } else if ((A->rows != B->rows) || (A->columns != B->columns)) {
    status = 2;
  } else {
    int check = s21_create_matrix(A->rows, B->columns, result);
    if (check == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    } else
      status = 1;
  }

  return status;
}