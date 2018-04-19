#include <stdio.h>
#include <math.h>
#include "hash.h"

int twoMovies(int num_movies, int flight_length, int movie_lengths[], HashInt hash)
{
    int result = 0;
    for (int i = 0; i < num_movies; i++)
    {
        int num = movie_lengths[i];
        int pairValue = flight_length - num;
        int size = (int)((ceil(log10(pairValue)) + 1) * sizeof(char));
        char str[size];
        sprintf(str, "%d", pairValue);
        int *value = hashGet(&hash, str);

        if (value != NULL)
        {
            result = 1;
            break;
        }
        size = (int)((ceil(log10(pairValue)) + 1) * sizeof(char));
        str[size];
        sprintf(str, "%d", num);
        value = hashGet(&hash, str);

        if (value == NULL)
        {
            hashInsert(&hash, str, pairValue);
        }
    }

    return result;
}

int main()
{
    //Minutes
    int flight_length, num_movies;

    scanf("%d", &flight_length);
    scanf("%d", &num_movies);

    int movie_lengths[num_movies];

    for(int i=0; i<num_movies; i++){
        scanf("%d", &movie_lengths[i]);
    }

    HashInt hash;
    hashInit(&hash, 100);

    int res = twoMovies(num_movies, flight_length, movie_lengths, hash);
    char *output;
    if(res){
        output = "You can't watch two movies.";
    } else{
        output = "You can watch two movies!";
    }
    printf("%s\n", output);
    return 0;
}