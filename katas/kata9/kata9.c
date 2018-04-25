#include <stdio.h>
#include <stdlib.h>

int *get_bits(int n)
{
    int *bits = malloc(sizeof(int) * 8);

    int k;
    for (k = 0; k < 8; k++)
    {
        int mask = 1 << k;
        int masked_n = n & mask;
        int thebit = masked_n >> k;
        bits[k] = thebit;
    }

    return bits;
}

int main()
{
    int array_length;
    printf("Array Length: ");
    scanf(" %d", &array_length);

    int *input = (int *)malloc(sizeof(int) * array_length);

    int i;
    printf("Type numbers:\n");
    for (i = 0; i < array_length; i++)
    {
        scanf("%d", &input[i]);
    }

    int nth_byte = 0;
    int is_valid = 1;

    for (i = 0; i < array_length; i++)
    {
        int *bits = get_bits(input[i]);
        int first_bit = bits[7];

        if (!nth_byte)
        {
            nth_byte = first_bit;

            if (nth_byte)
            {
                is_valid = 0;
                int j, current_bit;
                for (j = 6; j >= 0; j--)
                {

                    current_bit = bits[j];
                    if (current_bit)
                    {
                        nth_byte++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            nth_byte--;
            if (nth_byte)
            {
                int second_bit = bits[6];
                if (first_bit && !second_bit)
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
            else
            {
                is_valid = 1;
            }
        }
    }

    char *output;
    if (is_valid)
    {
        output = "Is valid";
    }
    else
    {
        output = "Is not valid";
    }
    printf("%s\n", output);
}