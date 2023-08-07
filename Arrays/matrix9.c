/*adding cols of 2d matrix*/
#include <stdio.h>
#define ROWS 3
#define COLS 3
int main()
{
	int mat1[3][3];
	int i,j;
	printf("Enter the elements of the first matrix\n");
	for(i=0; i<ROWS; i++) {
		for(j=0; j<COLS; j++)
			scanf("%d", &mat1[i][j]);
	}

    int colsSum[3] = {0};
	for(i=0; i<ROWS; i++) {
		for(j=0; j<COLS; j++)
			colsSum[i] += mat1[j][i];
	}
	printf("Addition of Columns\n");
	for(i=0; i<COLS; i++) {
		printf("%d ", colsSum[i]);
	}
}
