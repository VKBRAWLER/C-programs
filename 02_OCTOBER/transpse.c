// Find transpose and inverse of a matrix
#include <stdio.h>

#define N 3

void print_matrix(double mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%f ", mat[i][j]);
        }
        printf("\n");
    }
}

void gauss_jordan(double mat[N][N], double inv[N][N]) {
    // Initialize the inverse matrix as the identity matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                inv[i][j] = 1.0;
            } else {
                inv[i][j] = 0.0;
            }
        }
    }

    // Perform row operations to get the upper triangular matrix
    for (int i = 0; i < N; i++) {
        double pivot = mat[i][i];
        for (int j = 0; j < N; j++) {
            mat[i][j] /= pivot;
            inv[i][j] /= pivot;
        }
        for (int j = i + 1; j < N; j++) {
            double factor = mat[j][i];
            for (int k = 0; k < N; k++) {
                mat[j][k] -= factor * mat[i][k];
                inv[j][k] -= factor * inv[i][k];
            }
        }
    }

    // Perform row operations to get the identity matrix
    for (int i = N - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            double factor = mat[j][i];
            for (int k = 0; k < N; k++) {
                mat[j][k] -= factor * mat[i][k];
                inv[j][k] -= factor * inv[i][k];
            }
        }
    }
}

int main() {
    double mat[N][N] = {{1, 2, 3}, {0, 1, 4}, {5, 6, 0}};
    double inv[N][N];

    gauss_jordan(mat, inv);

    printf("Original matrix:\n");
    print_matrix(mat);

    printf("Inverse matrix:\n");
    print_matrix(inv);

    return 0;
}