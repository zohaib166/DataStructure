/*display upper diagonal matrix*/
#include <stdio.h>
int main()
{
	int mat[20][20];
	int i,j;
	int order;
	printf("Enter the order of the matrix\n");
	scanf("%d",&order);
	printf("Enter the elements of the matrix\n");
	for(i=0; i<order; i++) {
		for(j=0; j<order; j++) 
			scanf("%d", &mat[i][j]);
	}
	printf("Original Matrix\n");
	for(i=0; i<order; i++){
		for(j=0; j<order; j++)
			printf("%3d ", mat[i][j]);
		printf("\n");
	}
	for(i=0; i<order; i++) {
		for(j=0; j<order; j++) {
			if(i>j)
				mat[i][j] = 0;
		}
	}
	printf("Upper Diagonal Matrix\n");
	for(i=0; i<order; i++) {
		for(j=0; j<order; j++)
			printf("%3d ", mat[i][j]);
		printf("\n");
	}
}
