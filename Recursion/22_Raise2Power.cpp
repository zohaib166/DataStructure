#include <cstdio>

long int raise2power(int, int);

int main()
{
	int base = 8;
	int exp = 5;
	long int ans = raise2power(base,exp);
	printf("%ld", ans);
}

long int raise2power(int x, int y)
{
	if(y!=1)
	{
		return (x*raise2power(x, y-1));
	} 
	else
	{
		return x;
	}
}