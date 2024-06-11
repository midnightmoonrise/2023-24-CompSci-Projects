#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binarytoascii(char *binary);
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./decode [.txt file]");
        return 1;
    }
    char *buffer = malloc(sizeof(char) * 9);
    FILE *infile = fopen(argv[1], "r");
    while (fgets(buffer, 10, infile))
    {
        buffer[strlen(buffer) - 1] = '\0';
        int ascii = binarytoascii(buffer);
        printf("%c", ascii);
    }
    fclose(infile);
    free(buffer);
    printf("\n");
    return 0;
}

int binarytoascii(char *binary)
{
    int ascii = 0;
    for (int i = 0; i < 8; i++)
    {
        // find the digit
        int digit = (int) binary[i]; // apparently this auto-converts to ascii, i think
        digit -= 48;
        // multiply by the corresponding power of 2. 
        int exponent = strlen(binary) - i - 1;
        ascii += digit * (int) pow((double) 2, (double) exponent);
    }
    return ascii;
}
