#include <stdio.h>

int main() {
    
    int r1, c1, r2, c2;
    double a[100][100], b[100][100], c[100][100] = {0};

    // 1. Get matrix dimensions from the user
    printf("Enter rows and columns for Matrix A (max 100): ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns for Matrix B (max 100): ");
    scanf("%d %d", &r2, &c2);

    // 2. Validate dimensions
    if (c1 != r2) {
        printf("Error: Columns of Matrix A (%d) must equal rows of Matrix B (%d).\n", c1, r2);
        return 1;
    }
    if (r1 > 100 || c1 > 100 || r2 > 100 || c2 > 100 || r1 <= 0 || c1 <= 0 || r2 <= 0 || c2 <= 0) {
        printf("Error: Dimensions must be between 1 and 100.\n");
        return 1;
    }

    // 3. Read elements for Matrix A
    printf("\nEnter elements of Matrix A (%d x %d):\n", r1, c1);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("a[%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &a[i][j]);
        }
    }

    // 4. Read elements for Matrix B
    printf("\nEnter elements of Matrix B (%d x %d):\n", r2, c2);
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            printf("b[%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &b[i][j]);
        }
    }

    // 5. Perform Matrix Multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // 6. Print the Resultant Matrix
    printf("\nResultant product of the matrices (%d x %d):\n", r1, c2);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%.2f\t", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
