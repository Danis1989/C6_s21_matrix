#include "s21_matrix.h"

// Обратная матрица (inverse_matrix)

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int ret_status = 0;
  if ((s21_check_matrix(A) == 0) && (result != NULL)) { /* существуют*/
    if (A->rows == A->columns) { /* квадратная матрица */
      if (s21_create_matrix(A->rows, A->columns, result) == 0) {
        double deter = 0;
        s21_determinant(A, &deter);
        if (deter != 0) {
          // printf("\ndeter = %lf\n", deter);
          matrix_t first_temp_matrix = {0};
          matrix_t second_temp_matrix = {0};
          s21_calc_complements(A, &first_temp_matrix);
          s21_transpose(&first_temp_matrix, &second_temp_matrix);
          for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
              result->matrix[i][j] = second_temp_matrix.matrix[i][j] / deter;
            }
          }
          s21_remove_matrix(&first_temp_matrix);
          s21_remove_matrix(&second_temp_matrix);
        } else {
          ret_status = 2;
        }
      }
    } else {
      ret_status = 2; /* квадратная матрица */
    }
  } else { /* существуют */
    ret_status = 1;
  }
  return ret_status;
}