#include <stdio.h>
#define N 3

void swapRows(double mat[N][N+1], int i, int j) {
    for (int k = 0; k <= N; k++) {
        double temp = mat[i][k];
        mat[i][k] = mat[j][k];
        mat[j][k] = temp;
    }
}

void printMatrix(double mat[N][N+1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++)
            printf("%.2f ", mat[i][j]);
        printf("\n");
    }
}

void gaussElimination(double mat[N][N+1]) {
    for (int i = 0; i < N; i++) {
        // Partial Pivoting
        int maxIdx = i;
        for (int k = i + 1; k < N; k++) {
            if (mat[k][i] > mat[maxIdx][i])
                maxIdx = k;
        }
        if (maxIdx != i)
            swapRows(mat, i, maxIdx);

        // Gaussian Elimination
        for (int k = i + 1; k < N; k++) {
            double factor = mat[k][i] / mat[i][i];
            for (int j = i; j <= N; j++)
                mat[k][j] -= factor * mat[i][j];
        }
    }

    // Back substitution
    double sol[N];
    for (int i = N - 1; i >= 0; i--) {
        sol[i] = mat[i][N];
        for (int j = i + 1; j < N; j++)
            sol[i] -= mat[i][j] * sol[j];
        sol[i] /= mat[i][i];
    }

    // Print the solution
    printf("\nSolution:\n");
    for (int i = 0; i < N; i++)
        printf("x%d = %.2f\n", i + 1, sol[i]);
}

int main() {
    double mat[N][N+1] = {
        {2, 1, -1, 8},
        {-3, -1, 2, -11},
        {-2, 1, 2, -3}
    };

    printf("Original Augmented Matrix:\n");
    printMatrix(mat);

    gaussElimination(mat);

    return 0;
}
