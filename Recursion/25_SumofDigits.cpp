#include <cstdio>

int add_digits(long);

int main()
{
	long num = 3245;
	printf("%d", add_digits(num));
}

int add_digits(long n)
{
	if (n != 0)
	{
		return (n % 10 + add_digits(n / 10));
	}
	else
	{
		return 0;
	}
}
