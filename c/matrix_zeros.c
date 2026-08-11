#include <stdio.h> 
#include <stdbool.h>

void matrix_zeros(int row, int col, int matrix[row][col]) {
	bool zero_col = false;
	// mark the initial zeros of from each cell 
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if(matrix[i][j] == 0) {
				// set the border matrix to 0. that sets the row/ col as a marker 
				matrix[i][0] = 0;
				if ( j == 0) {
					zero_col = true;
				} else {
					matrix[0][j] = 0;
				}
			}
		}
	}
	
	// traverse inner cells and set to zero if marked
	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {
			if (matrix[i][0] == 0 || matrix[0][j] == 0) {
				matrix[i][j] =0;
			}
		}
	}

	// setting for first row
	if (matrix[0][0] == 0) {
		for (int j = 0; j < col; j++) {
			matrix[0][j] = 0;
		}
	}

	// setting for fir column
	if (zero_col) {
		for (int i = 0; i < row; i++) {
			matrix[i][0] = 0;
		}
	} 

}

void print_matrix(int row, int col, int matrix[row][col]) {
	for (int i = 0; i < row; i++) {
		for ( int j = 0; j < col; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
int main() {
	int row, col;
	
	printf("Enter the number of rows: ");
	scanf("%d", &row);
	
	printf("Enter the number of columns: ");
	scanf("%d",&col);

	int matrix[row][col];

	printf("Enter elements: ");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%d",&matrix[i][j]);	
		}
	}

	matrix_zeros(row, col, matrix);
	print_matrix(row, col, matrix);
	return 0;
}
