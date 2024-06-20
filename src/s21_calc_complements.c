#include "s21_matrix.h"

// Минор матрицы и матрица алгебраических дополнений (calc_complements)
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int success = -1;
  if (s21_check_matrix(A) != 0) {
    return s21_check_matrix(A);
  } else if (A->rows != A->columns) { /* если матрица не квадратная */
    return 2;
  } else if (A->rows == 1 && A->columns == 1) {
    return 2; /* не успех */
  } else {
    success = 0;
    int check_create; /* 0 - успех, 1 - не успех */
    check_create = s21_create_matrix(A->rows, A->columns, result);
    if (check_create == 0) {
      for (int i = 0; i < A->columns; ++i) {
        for (int j = 0; j < A->rows; ++j) {
          double minor = 0.0;
          matrix_t temporary_matrix = {
              0};  // временная матрица, очевидно из названия
          int check_temp = -1;
          check_temp =
              s21_create_matrix(A->rows - 1, A->columns - 1, &temporary_matrix);
          if (check_temp == 0) { /* 0 - успех, 1 - не успех */
            s21_minor(A, &temporary_matrix, i, j);
            s21_determinant(&temporary_matrix, &minor);
            result->matrix[i][j] = minor * pow(-1, i + j);
            s21_remove_matrix(&temporary_matrix);
          } else
            success = 1;
        }
      }
    }
  }
  return success;
}

void s21_minor(matrix_t *A, matrix_t *mini_matrix, int n_row, int n_col) {
  // Создаем временную матрицу для подматрицы
  int i = 0, j = 0;
  for (int row = 0; row < A->rows; row++) {
    for (int col = 0; col < A->columns; col++) {
      if (row != n_row && col != n_col) {
        mini_matrix->matrix[i][j] = A->matrix[row][col];
        j++;
        if (j == A->columns - 1) {
          j = 0;
          i++;
        }
      }
    }
  }
}