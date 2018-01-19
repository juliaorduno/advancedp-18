#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int doFullName(char *firstName,
               char *lastName,
               char **fullNameValue)
{
    int sizeFirstName = strlen(firstName);
    int sizeLastName = strlen(lastName);
    int sizeFullName = sizeFirstName + sizeLastName;

    char *fullName = (char *) malloc(sizeFullName * sizeof(char));

    strcpy(fullName, firstName);
    strcpy(fullName + sizeFirstName, " "); // " " string with space
    strcpy(fullName + sizeFirstName + 1, lastName);
    *fullNameValue = fullName;

    return 0;
}

int main()
{
    char firstName[] = "Julia";
    char lastName[] = "Paola";
    char *fullName;

    doFullName(firstName, lastName, &fullName);

    printf("%s \n", fullName);
    free(fullName);

    return 0;
}