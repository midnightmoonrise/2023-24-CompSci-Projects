/* from a user determined low and high bound, print all integers, substituting "fizz" for those divisible by 3, "buzz" for those divisible by 5, and "fizzbuzz"
for those divisible by both. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int low;
    printf("Please enter a low bound: ");
    scanf("%i", &low);
    int high;
    printf("Please enter a high bound: ");
    scanf("%i", &high);
    if (low >= high)
    {
        printf("Error. Low bound should be strictly less than the high bound.\n");
        return 1;
    }
    for(int i = low; i <= high; i++)
    {
        int div = 0;
        if (i % 3 == 0)
        {
            printf("fizz");
            div = 1;
        }
        if (i % 5 == 0)
        {
            printf("buzz");
            div = 1;
        }
        if (!div)
        {
            printf("%i", i);
        }
        printf("\n");
    }
    printf("Program has finished.\n");
    return 0;
}
// 0 is false and 1 is true.
