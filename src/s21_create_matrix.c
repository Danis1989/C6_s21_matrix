#include "s21_matrix.h"

//Создание матриц

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int ret_status = OKAY;

  if (rows <= 0 || columns <= 0 || result == NULL) {
    return NOCORRECT;
  } else {
    result->matrix = calloc(rows, sizeof(double *)); /* память для строк */
    result->rows = rows;
    result->columns = columns;

    if (result->matrix != NULL) {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] =
            calloc(columns, sizeof(double)); /* память для столбцов */
      }
    }
  }
  return ret_status;
}

int s21_check_matrix(matrix_t *matrix_check) {
  /*
  0 - ok
  1 - not ok
  */
  int status = 0;

  if (matrix_check == NULL || matrix_check->matrix == NULL ||
      (matrix_check->rows) <= 0 || (matrix_check->columns) <= 0) {
    status = 1;

  } else {
    for (int i = 0; i < matrix_check->rows; i++) {
      for (int j = 0; j < matrix_check->columns; j++) {
        if (matrix_check->matrix[i][j] == NAN) {
          status = 1;
        }
      }
    }
  }
  return status;
}