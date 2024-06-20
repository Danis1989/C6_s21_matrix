#include "s21_matrix.h"

// Сравнение матриц

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  /* только при сравнении    успех 1
                           неуспех 0 */

  int success = 0;
  if (A->rows <= 0 || A->columns <= 0 || B->rows <= 0 || B->columns <= 0 ||
      (A->rows != B->rows) ||
      (A->columns != B->columns)) { /* проверка на корректность*/
    success = 0;                    /* fail */
  } else if (A->rows == B->rows && A->columns == B->columns) {
    success = 1;
    for (int i = 0; i < A->rows && success != 0; ++i) {
      for (int j = 0; j < A->columns && success != 0; ++j) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= EPS) {
          success = 0; /* неуспех */
        }
      }
    }
  }

  return success;
}
