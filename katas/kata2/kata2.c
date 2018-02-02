#include <stdio.h>
#include <string.h>

////// BRUTE FORCE ///////
int strongPasswordChecker(char *password)
{
    int passwordSize = strlen(password),
        minimumChanges = 0,
        hasLower = 0,
        hasUpper = 0,
        hasNumber = 0,
        asciiValue = 0,
        repeated = 0;

    if (passwordSize < 6)
        minimumChanges = 6 - passwordSize;
    else if (passwordSize > 20)
        minimumChanges = passwordSize - 20;

    for (int i = 0; i < passwordSize; i++)
    {

        if (asciiValue == (int)password[i])
            repeated++;
        else if (repeated && asciiValue != (int)password[i])
            repeated = 2 * ((int)repeated / 2);

        asciiValue = (int)password[i];

        if (asciiValue > 47 && asciiValue < 58 && !hasNumber)
            hasNumber = 1;
        else if (asciiValue > 64 && asciiValue < 91 && !hasUpper)
            hasUpper = 1;
        else if (asciiValue > 96 && asciiValue < 123 && !hasLower)
            hasLower = 1;
    }

    if (!hasLower)
        minimumChanges++;
    if (!hasUpper)
        minimumChanges++;
    if (!hasNumber)
        minimumChanges++;
    if (repeated)
        minimumChanges += (int)repeated / 2;

    return minimumChanges;
}

int main()
{
    char password[] = "passsdddeeef33";
    int min = strongPasswordChecker(password);
    printf("Minimum Changes: %d\n", min);
    return 0;
}