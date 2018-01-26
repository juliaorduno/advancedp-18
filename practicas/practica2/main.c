#include <stdio.h>
#include "operations.h"

int main()
{
    int operator1, operator2;
    char operations[200];
    printf("%s\n","What is the operation?");
    scanf("%s", operations);
    printf("%s\n", operations);
    scanf("%d %d", &operator1, &operator2);
    printf("result: %d\n", add(operator1, operator2));
    return 0;
}