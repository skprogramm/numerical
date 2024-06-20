#include <stdio.h>

#define N 3

void displayMatrix(double matrix[N][N]);
void gaussElimination(double matrix[N][N], double inverse[N][N]);

int main() {
    double matrix[N][N], inverse[N][N];

    printf("Enter the elements of the matrix row-wise:\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    printf("Original matrix:\n");
    displayMatrix(matrix);

    gaussElimination(matrix, inverse);

    printf("\nInverse matrix:\n");
    displayMatrix(inverse);

    return 0;
}

//display matrix
void displayMatrix(double matrix[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%lf\t", matrix[i][j]);
        }
        printf("\n");
    }
}

//Gauss elimination to find the inverse
void gaussElimination(double matrix[N][N], double inverse[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            inverse[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    for (int i = 0; i < N; ++i) {
        // Find pivot element
        double pivot = matrix[i][i];

        // Divide the current row of both matrix by pivot
        for (int j = 0; j < N; ++j) {
            matrix[i][j] /= pivot;
            inverse[i][j] /= pivot;
        }

        for (int k = 0; k < N; ++k) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j < N; ++j) {
                    matrix[k][j] -= factor * matrix[i][j];
                    inverse[k][j] -= factor * inverse[i][j];
                }
            }
        }
    }
}
