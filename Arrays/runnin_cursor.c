#include <stdio.h>
#include <stdlib.h>

void advance_cursor();
void delay();
char cursor[4] = {'/','-','\\','|'};
int main()
{
	int i;

	for(i=0; i<75; i++)
	{
		advance_cursor();
        delay();
	}
	printf("\n");
	return 0;
}
void advance_cursor()
{
	static int pos=0;
	printf(".%c\b",cursor[pos]);
	pos = (pos+1) % 4;
}
void delay()
{
   int c = 1, d = 1;

   for ( c = 1 ; c <= 5000 ; c++ )
       for ( d = 1 ; d <= 50000 ; d++ )
       {}
}
