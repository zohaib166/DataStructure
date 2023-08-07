/*product of 2D matrices*/
#include <stdio.h>
#define ROWS 3
#define COLS 3
int main()
{
	int mat1[3][3], mat2[3][3], mat3[3][3]={0};
	int i,j,k;
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
		for(j=0; j<COLS; j++){
			for(k=0; k<COLS; k++)
				mat3[i][j] = mat3[i][j] + mat1[i][k]*mat2[k][j];
		}
	}
	printf("product of matrices\n");
	for(i=0; i<ROWS; i++){
		for(j=0; j<COLS; j++)
		   printf("%3d ", mat3[i][j]);
		printf("\n");
	}
}
