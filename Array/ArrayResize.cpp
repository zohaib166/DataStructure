#include <cstdio>
#include <cstdlib>

int main() 
{
	//declare a smaller array
	int *p = (int*) calloc(4,sizeof(int));
	//fill data
	for(int i=0;i<4;i++) {
		p[i] = 2*(i+1);
	}
	printf("%x\n", p);
	//declare a larger array
	int *q = (int*) calloc(10,sizeof(int));
	for(int i=0;i<4;i++) {
		q[i] = p[i];
	}
	free(p);
	printf("%x\n", p);
	q = p;
	p=NULL;
	printf("%x\n", p);
}
