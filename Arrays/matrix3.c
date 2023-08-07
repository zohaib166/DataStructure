/*adding 2D matrix*/
#include <stdio.h>
#define ROWS 3
#define COLS 3
int main()
{
	int mat1[3][3], mat2[3][3], mat3[3][3];
	int i,j;
	printf("Enter the elements of the first matrix\n");
	for(i=0; i<ROWS; i++){
		for(j=0; j<COLS; j++)
			scanf("%d", &mat1[i][j]);
	}
	printf("Enter the elements of the second matrix\n");
	for(i=0; i<ROWS; i++){
		for(j=0; j<COLS; j++)
			scanf("%d", &mat2[i][j]);
	}

	for(i=0; i<ROWS; i++){
		for(j=0; j<COLS; j++)
			mat3[i][j] = mat1[i][j]+mat2[i][j];
	}
	printf("Addition of matrices\n");
	for(i=0; i<ROWS; i++){
		for(j=0; j<COLS; j++)
		   printf("%3d ", mat3[i][j]);
		printf("\n");
	}
}
