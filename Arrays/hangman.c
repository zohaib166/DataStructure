#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
void main()
{
	FILE *fptr;
	char buff[10][255];
	char hidden[255];
	char guess[50];
	fptr = fopen("emp.rec", "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
	int i=0;
    for(i=0;i<10;i++)
    {
        fgets(buff[i], 255, (FILE*)fptr);
    }
    time_t t;
    srand((unsigned) time (&t));
    int movie_index = rand() % 10;
	int attempts = 7;
	int len;
	int blank=0,flag=0,count=0;
	int success = 0;
	char x;
	strcpy(hidden,buff[movie_index]);
	fputs(hidden, stdout);
	len = strlen(hidden);
	printf("Start guessing the letters\n");
	printf("You have %d attempts\n", attempts);
	for(i=0; i<len; i++)
	{
	    if(hidden[i]==' '){
            guess[i]=' ';
            printf(" ");
	    } else {
            printf("-");
            guess[i] = '-';
	    }
	}
	guess[i] = '\0';
	printf("\n");
	while(attempts>0)
	{
		x = getc(stdin);
		fflush(stdin);
		flag = 0;
		count=0;
		for(i=0; i<len; i++)
		{
			if(x == hidden[i] && guess[i]=='-')
			{
				guess[i] = hidden[i];
				count++;
			}
			else
			{
				flag++;
			}
		}
		if(flag>0&&count==0)
		{
			attempts--;
		}
		blank = 0;
		for(i=0; i<len; i++)
		{
			if(guess[i] == '-')
			{
				blank++;
			}
		}
		if(blank==0)
		{
			success = 1;
			break;
		}

		printf("\t\t%s\n", guess);
		printf("attempts left: %d\n", attempts);
	}

	if(success == 1)
	{
	    printf("The String was:\n");
	    puts(hidden);
		printf("you win\n");
	}
	else
	{
		printf("you lose\n");
	}
    fclose(fptr);
}

