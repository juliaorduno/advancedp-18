#include <stdio.h>
#include <string.h>

int makesCircle(char *coordinates){

    int x = 0, y = 0;
    for(int i=0; i<strlen(coordinates); i++){
        char coordinate = coordinates[i];
        if(coordinate == 'U'){
            y++;
        } else if(coordinate == 'D'){
            y--;
        } else if(coordinate == 'L'){
            x--;
        } else if(coordinate == 'R'){
            x++;
        }
    }

    if(!x && !y){
        return 1;
    } else{
        return 0;
    }
}

int main()
{
    char *coordinates;
    scanf("%s", coordinates);
    if(makesCircle(coordinates)){
        printf("%s\n","true");
    } else{
        printf("%s\n","false");
    }
    return 0;
}

