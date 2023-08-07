#include<stdio.h>
int main()
{
	int arr[10] = {0,0,1,1,0,0,1,1};
	int size = 8;
	int i;
	int start, end;	
	for(i=0; i<size; i++)
	{
		printf("%d ",arr[i]);
	}
	start = 0;
	end = i-1;
	while(start<end)
	{
		while(arr[start]==0 && start<end)
			start++;
		while(arr[end]==1 && start<end)
			end--;

		if(start<end)
		{
			arr[start] = 0;
			arr[end] = 1;
			start++;
			end--;
		}
	}
	printf("\n");
	for(i=0; i<size; i++)
	{
		printf("%d ",arr[i]);
	}
}
