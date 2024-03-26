// swap the values of two integer variables x and y without the use of a third holding variable.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./intswap [x] [y]");
        return 1;
    }
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    x = y - x;
    y = y - x;
    x = y + x;
    printf("x hath become %i, y hath become %i.\n", x, y);
    return 0;
}
