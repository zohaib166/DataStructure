/*Parse the date in dd/mm/yyyy format and save date, month and year in three different variables.*/
#include <stdio.h>
int main()
{
    char str[11] = "05/02/1986";
    int dd,mm,yyyy,i=0,j=0;
    int place_value=10;
    int num;

    while(str[i]!='\0')
    {
        int temp;
        j=i;
        num=0;
        while(str[j]!='/' && str[j]!='\0')
        {

            temp = str[j]-48;
            num = num+temp*place_value;
            place_value = place_value/10;
            j++;
        }
        i=j;
        i++;
        if(j==2)
        {
            dd=num;
        }
        if(j==5)
        {
            mm=num;
            place_value=1000;
        }
        else
            place_value=10;
        if(j==10)
        {
            yyyy=num;
        }
    }
    printf("%d %d %d", dd, mm, yyyy);

}
