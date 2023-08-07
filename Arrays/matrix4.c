/*transpose of a matrix*/
#include <stdio.h>
#define ROWS 3
#define COLS 3
int main()
{
	int mat[ROWS][COLS],tmat[ROWS][COLS];
	int i,j;
	printf("Enter the elements of the matrix\n");
	for(i=0; i<ROWS; i++){
		for(j=0; j<COLS; j++)
			scanf("%d", &mat[i][j]);
	}
	for(i=0; i<ROWS; i++){
		for(j=0; j<COLS; j++)
			tmat[i][j] = mat[j][i];
	}
	printf("Original Matrix\n");
	for(i=0; i<ROWS; i++){
		for(j=0; j<COLS; j++)
			printf("%3d ", mat[i][j]);
		printf("\n");
	}
	printf("Transposed Matrix\n");
	for(i=0; i<ROWS; i++){
		for(j=0; j<COLS; j++)
			printf("%3d ", tmat[i][j]);
		printf("\n");
	}
}
