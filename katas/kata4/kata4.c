#include <stdio.h>
#include <string.h>

int isNumeric(char *value)
{
    int counter = 0;
    int current;
    int isFloat = 0;
    int size = strlen(value);
    int isExp = 0;
    int hasCommas = 0;
    int digitCounter;

    while (value[counter] == ' ')
    {
        counter++;
    }

    if (value[counter] == '+' || value[counter] == '-')
    {
        counter++;
    }

    while (counter < size)
    {
        current = (int)value[counter];

        if (current > 47 && current < 58)
        {
            if (hasCommas)
            {
                if (digitCounter < 3)
                {
                    digitCounter++;
                }
                else
                {
                    return 0;
                }
            }
        }
        else if (hasCommas && digitCounter < 3)
        {
            return 0;
        }
        else if (current == 46 && !isFloat && !isExp && counter < (size - 1))
        {
            hasCommas = 0;
            isFloat = 1;
        }
        else if (current == 101 && !isExp && counter < (size - 1))
        {
            hasCommas = 0;
            isExp = 1;
            if (value[counter+1] == '+' || value[counter+1] == '-')
            {
                counter++;
            }
        }
        else if (current == 44 && counter < (size - 1) && !isExp && !isFloat && counter > 0)
        {
            if (!hasCommas && counter < 4)
            {
                hasCommas = 1;
            }
            digitCounter = 0;
        }
        else if (current == 32)
        {
            break;
        }
        else
        {
            return 0;
        }
        counter++;
    }

    while (value[counter] == ' ')
    {
        counter++;
    }

    if (counter == size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *toValidate;
    scanf("%s", toValidate);
    int result = isNumeric(toValidate);
    if (result)
    {
        printf("%s is numeric! :D", toValidate);
    }
    else
    {
        printf("%s is not numeric :(", toValidate);
    }
    return 0;
}