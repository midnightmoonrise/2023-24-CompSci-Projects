// Determine if a word is a palindrome.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

char *get_string(char *input_text);
char *reverse(char *input);

int main(void)
{
    char *string = get_string("GIVE ME A STRING (max 100 characters): ");
    int length = strlen(string);
    for (int i = 0; i < length; i++)
    {
        if (string[i] == ' ')
        {
            for (int j = i; j < length - 1; j++)
            {
                string[j] = string[j + 1];
            }
            string[length - 1] = '\0';
        }
    }

    char *reversed = reverse(string);
    length = strlen(reversed);
    for (int i = 0; i < length; i++)
    {
        if (tolower(string[i]) != tolower(reversed[i]))
        {
            printf("is NOT palindrome!!\n");
            free(string);
            free(reversed);
            return 0;
        }
    }
    printf("is palindrome!!\n");
    free(string);
    free(reversed);
    return 0;
}

char *get_string(char *input_text)
{
    printf("%s", input_text);
    char *buffer = malloc(51 * sizeof(char));
    fgets(buffer, 50, stdin);
    return buffer;
}

char *reverse(char *input)
{
    int length = strlen(input);
    char *reversed = malloc(sizeof(char));
    for (int i = 0; i < length; i++)
    {
        reversed[i] = input[length - 1 - i];
    }
    for (int i = 0; i < length - 1; i++)
    {
        reversed[i] = reversed[i + 1];
    }
    reversed[length - 1] = '\0';
    return reversed;
}
