#include "s21_matrix.h"

// Транспонирование матрицы (transpose)
// замена строк этой матрицы ее столбцами с сохранением их номеров

int s21_transpose(matrix_t *A, matrix_t *result) {
  int res = 0;
  if (A->matrix == NULL) {
    // если нет матриц
    res = 1;
  } else if (s21_check_matrix(A) == 1) {
    return 1;
  } else if (s21_check_matrix(A) == 2) {
    return 2;

  } else {
    // Создание матрицы result с размерами, обратными размерам матрицы A
    res = s21_create_matrix(A->columns, A->rows, result);
    // если не произошла ошибка при создании
    if (res == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] += A->matrix[i][j];
        }
      }
    }
  }
  return res;
}
