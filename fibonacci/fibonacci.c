// find the nth term of the Fibonacci sequence 0, 1, 1... where n is determined by user input.
// this one uses Binet's Formula (explicit formula) because I wanted O(1)
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double fibonacci(int input);

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
        printf("Your input should be an integer greater or equal to 1.\n");
        return 2;
    }
    printf("The %ith term of the Fibonacci sequence is %.0f\n", index, fibonacci(index));
}

double fibonacci(int input)
{
    int index = input - 1;
    double fibonacci = (pow((1 + sqrt(5))/ 2, index) - pow((1 - sqrt(5))/ 2, index)) / sqrt(5);
    return fibonacci;
}
