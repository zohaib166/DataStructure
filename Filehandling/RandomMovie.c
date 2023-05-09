#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    char movies[10][100];
    FILE *fp = fopen("movies.txt", "r");
    int i = 0;
    while(fgets(movies[i],100,fp) != NULL) {
        i++;
    }
    time_t t;
    srand((unsigned) time (&t));
    int movie_index = rand() % 10;
    printf("%s",movies[movie_index]);
}