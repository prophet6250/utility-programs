#include <stdio.h>
#include <stdlib.h>

struct matrix
{
	int rows, columns;
	int **coefficients;
	int **mat;
};

typedef struct matrix matrix;

int CheckDet(matrix m)
{
	for (int i = 0; i < m.rows; i++)
		if (m.mat[i][i] == 0) return i;
	return -1;
}

void SwapOp(matrix *M, int whichDia)
{
	// finding the first nonzero valued row to be replaced with the target
	for (int i = whichDia; i < M->rows; i++) {
		if (M->mat[i][whichDia] != 0) {	// found the non-zero row
			// swap this entire row with target row
			for (int j = 0; j < M->columns; j++) {
				M->mat[whichDia][j] += M->mat[i][j];
				M->mat[i][j] = M->mat[whichDia][j] -
				M->mat[i][j];
				M->mat[whichDia][j] += M->mat[i][j];
			}
			break;
		}
	}
	return;
}

int Determinant(matrix M)
{
	long int answer = 1;
	int factor;
	int col = 0;
	while (col < M.columns) {
		// in this loop, the column denoted by col will be in order
		for (int i = col + 1; i < M.rows; i++) {
			// 1. check for M(0, 0) == 0
			int check = CheckDet(M);
			if (check != -1) {
				SwapOp(&M, check);
				i -= 1;
				if (i < 0) i = 0;
			}
			if (M.mat[i][col] == 0) continue;
			// 2. calculate the factor and do the operation
			factor = M.mat[i][col] / M.mat[col][col];
			M.mat[i][col] = 0;
			for (int j = col + 1; j < M.columns; j++)
				M.mat[i][j] -= (factor * M.mat[col][j]);
			answer *= M.mat[col][col];
		}
		col += 1;
	}
	return answer * M.mat[M.rows][M.columns];
}

int main(void)
{
	matrix M;
	printf("enter the dimensions of the matrix\n");
	scanf("%d %d", &M.rows, &M.columns);
	M.columns += 1;

	// dynamically allocate memory to the matrix
	for (int i = 0; i < M.rows; i++)
		M.mat = (int **)malloc(sizeof(int) * M.rows);
	M.coefficients = (int **)malloc(sizeof(int) * M.columns);
	for (int j = 0; j < M.columns; j++) {
		M.mat[j] = (int *)malloc(sizeof(int) * M.columns);
		M.coefficients[j] = (int *)malloc(sizeof(int) * M.columns);
	}

	// input the matrix values
	for (int i = 0; i < M.rows; i++) {
		printf("enter coefficients for equation %d\n", i + 1);
		for (int j = 0; j < M.columns - 1; j++) {
			printf("enter the coefficient of x%d : ", j + 1);
			scanf("%d", &M.mat[i][j]);
		}
		printf("enter the constant term for equation %d : ", i + 1);
		scanf("%d", &M.mat[i][M.columns - 1]);
	}

	printf("%d", Determinant(M));
	return 0;
}
