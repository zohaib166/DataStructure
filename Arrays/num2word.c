/*Write a number in word ranging from 0-9999*/
#include <stdio.h>

int main()
{
	int num;
	int n1, pos, digit, div, tot_digit, flag;
	div =1;
	tot_digit =0;
	flag = 0;
	//clrscr();
	printf("Enter a number (0-9999): \n");
	scanf("%d", &num);
	n1 = num;
	if(num == 0)
	{
		printf("Zero\n");
		//getch();
		return 1;
	}
	if(num > 99999)
	{
		printf("Enter a number between 0 to 9999\n");
		//getch();
		return 1;
	}
	while(n1 > 9)
	{
		n1=n1/10;
		div = div*10;
		tot_digit++;
	}
	tot_digit++;
	//printf("tot_digit=%d div=%d", tot_digit, div);
	pos = tot_digit;
	while(num!=0)
	{
		digit = num / div;
		num = num % div;
		div = div /10;
		//printf("pos %d, digit %d  flag %d\n", pos, digit,flag);
		switch(pos)
		{
           	case 1:

				if(flag==1)
				{
					flag = 0;
					switch(digit)
					{
						case 0: printf("ten "); break;
						case 1: printf("eleven "); break;
						case 2: printf("twelve "); break;
						case 3: printf("thirteen "); break;
						case 4: printf("fourteen "); break;
						case 5: printf("fifteen "); break;
						case 6: printf("sixteen "); break;
						case 7: printf("seventeen "); break;
						case 8: printf("eighteen "); break;
						case 9: printf("nineteen "); break;
					}
				}
				else
				{
					switch(digit)
					{
						case 1: printf("one "); break;
						case 2: printf("two "); break;
						case 3: printf("three "); break;
						case 4: printf("four "); break;
						case 5: printf("five "); break;
						case 6: printf("six "); break;
						case 7: printf("seven "); break;
						case 8: printf("eight "); break;
						case 9: printf("nine "); break;
					}
				}
				break;
			case 4:
			case 3:
			    if(flag==1)
                {
                    flag==0;
                    switch(digit)
                    {
                        case 0: printf("ten "); break;
						case 1: printf("eleven "); break;
						case 2: printf("twelve "); break;
						case 3: printf("thirteen "); break;
						case 4: printf("fourteen "); break;
						case 5: printf("fifteen "); break;
						case 6: printf("sixteen "); break;
						case 7: printf("seventeen "); break;
						case 8: printf("eighteen "); break;
						case 9: printf("nineteen "); break;

                    }
                }
                else
                {
                    switch(digit)
					{
						case 1: printf("one "); break;
                        case 2: printf("two "); break;
                        case 3: printf("three "); break;
                        case 4: printf("four "); break;
                        case 5: printf("five "); break;
                        case 6: printf("six "); break;
                        case 7: printf("seven "); break;
                        case 8: printf("eight "); break;
                        case 9: printf("nine "); break;
					}
                }
				if(pos == 3 && digit != 0)
					printf("hundred ");
				if(pos == 4 || pos == 5)
					printf("thousand ");
				break;
            case 5:
			case 2:
				if(digit==1)
				{
					flag=1;
					//printf("i am here\n");
				}
				else
				{
					flag = 0;
					switch(digit)
					{
						case 2: printf("twenty "); break;
						case 3: printf("thirty "); break;
						case 4: printf("forty "); break;
						case 5: printf("fifty "); break;
						case 6: printf("sixty "); break;
						case 7: printf("seventy "); break;
						case 8: printf("eighty "); break;
						case 9: printf("ninety "); break;
					}
				}
				break;
		}
		pos--;
	}
	//getch();
	return 0;
}
