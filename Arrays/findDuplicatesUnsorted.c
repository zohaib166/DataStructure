#include <stdio.h>

int main()
{
    int arr[] = {3, 5, 6, 7, 3, 5, 7, 1, 2, 2};
    int count;
    int size = sizeof(arr) / sizeof(int);
    for (int i = 0; i < size - 1; i++)
    {
        count = 1;
        if (arr[i] != -1)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                    arr[j] = -1;
                }
            }
        }
        if (count>1)
            printf("%d: %d\n", arr[i], count);
    }
}