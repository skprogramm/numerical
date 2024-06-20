#include <stdio.h>

#define N 10

void displayMatrix(double matrix[N][N], int n);
void gaussElimination(double matrix[N][N], double inverse[N][N], int n);

int main() {
    int n;

    printf("Enter the size of the matrix (max 10): ");
    scanf("%d", &n);

    if (n <= 0 || n > N) {
        printf("Invalid matrix size. Please enter a size between 1 and %d.\n", N);
        return 1;
    }

    double matrix[N][N], inverse[N][N];

    printf("Enter the elements of the matrix row-wise:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    printf("Original matrix:\n");
    displayMatrix(matrix, n);

    // Compute inverse using Gauss elimination method
    gaussElimination(matrix, inverse, n);

    printf("\nInverse matrix:\n");
    displayMatrix(inverse, n);

    return 0;
}

// Function to display a matrix
void displayMatrix(double matrix[N][N], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%.6lf\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform Gauss elimination to find the inverse
void gaussElimination(double matrix[N][N], double inverse[N][N], int n) {
    // Initialize the inverse matrix as an identity matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inverse[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    // Perform Gauss elimination on the original matrix and the identity matrix simultaneously
    for (int i = 0; i < n; ++i) {
        // Find pivot element
        double pivot = matrix[i][i];

        // Divide the current row of both matrix by pivot
        for (int j = 0; j < n; ++j) {
            matrix[i][j] /= pivot;
            inverse[i][j] /= pivot;
        }

        // Eliminate all other elements in the current column
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j < n; ++j) {
                    matrix[k][j] -= factor * matrix[i][j];
                    inverse[k][j] -= factor * inverse[i][j];
                }
            }
        }
    }
}
