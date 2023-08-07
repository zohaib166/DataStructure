#include <stdio.h>
void reverse_str(char str[], int start, int end) {
    char temp;
    while(start<end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
int main()
{
    char str[100];
    printf("Enter a sentence\n");
    scanf("%[^\n]s", str);
    int start = 0, end = 0;
    while(str[end]!='\0') {
        end = start;
        for(end = start; str[end] && str[end]!=' ';end++);
        reverse_str(str, start, end-1);
        start = end+1;
    }

    printf("%s", str);
}