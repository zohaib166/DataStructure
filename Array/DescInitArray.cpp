#include <iostream>
#include <cstdio>
#include <cstdlib>
//1D array
int main() {
	//static (compile time) memory allocation of array
	int num[20] = {2,3,4,5,6}; //declaration & initialization
	int arr[] = {5,6,7,8,9}; //decl through initialization

	
	//dynamic memory allocation
	//C method
	int *ptr = (int*) malloc(5*sizeof(int));
	
	for(int i=0;i<5;i++) {
		ptr[i] = (i+1) * 2;
	}
	
	int *x;
	x = ptr;
	
	for(int i=0;i<5;i++) {
		printf("%d ", *x);
		x++;
	}
	
	//c++ method
	int *ptr1 = new int[5];

	

	
	
	
	
	
}
