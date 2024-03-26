// find the nth term of the Fibonacci sequence 0, 1, 1... with n being a user input
// But do it recursively.
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int index);
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./fibonacci [index]\n");
        return 1;
    }
    int index = atoi(argv[1]);
    if (index == 0 || index < 1)
    {
        printf("Your input should be an INTEGER greater or equal to 1.\n");
        return 2;
    }
    printf("The %ith term of the Fibonacci sequence is %i\n", index, fibonacci(index));
}

int fibonacci(int index)
{
    int count = 3;
    int a = 0;
    int b = 1;
    int *holding;
    while (count < index)
    {
        holding = &a;
        *a = &b;
        b = *holding + a;
        count++;
    }
    return c;
}
