/*delete an element from a specified position in an array*/
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
		printf("%d ", arr[i]);
	}
	printf("\nEnter the position of the number to be deleted\n");
	scanf("%d", &pos);
	if(pos>=0 && pos<size)
	{
		for(i=pos; i<size; i++)
		{
			arr[i-1] = arr[i];
		}
		size = size-1;
	}
	else if(pos == size)
    {

        arr[size] = 0;
        size = size-1;
    }
	else
	{
		printf("Invalid position \n");
		exit(0);
	}
	printf("Array after insertion: \n");
	for(i=0; i<size; i++)
	{
		printf("%d ", arr[i]);
	}
}
