/*Insert an integer in a specified position in an array*/
#include <stdio.h>
int main()
{
	int arr[50];
	int i,j,pos,num;
	int size;
	printf("Enter the length of array\n");
	scanf("%d", &size);
	printf("Enter the elements of array one by one\n");
	for(i=0; i<size; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Array contain following elements\n");
	for(i=0; i<size; i++)
	{
		printf("%3d", arr[i]);
	}
	printf("\nEnter the number to be inserted and its position\n");
	scanf("%d %d", &num, &pos);
	if(pos>0 && pos<=size)
	{
		for(j=size; j>=pos; j--)
		{
			arr[j] = arr[j-1];
		}
		arr[pos-1] = num;
	}
	else if(pos == size+1)
		arr[size] = num;
	else
	{
		printf("Invalid position \n");
		exit(0);
	}
	printf("Array after insertion: \n");
	for(i=0; i<size+1; i++)
	{
		printf("%3d", arr[i]);
	}
}
