#include <cstdio>

int main()
{
	int num1 = 100;
	int num2 = 120;
	printf("%d\n", GCD(num1, num2));
	return 0;
}
int GCD(int x, int y)
{
	if(y%x==0)
		return x;
	else
		return GCD(y, y%x);
}