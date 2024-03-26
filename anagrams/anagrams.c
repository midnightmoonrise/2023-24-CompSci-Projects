// check tos ee if two words are anagrams of each other
// slightly faulty
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_string(char *input_text);
void sortbyascii(char *input);
int toascii(char c);

int main(void)
{
    char *word1 = get_string("Enter the first word: ");
    char *word2 = get_string("Enter the second word: ");
    if (word1 == NULL || word2 == NULL)
    {
        printf("No input.\n");
        free(word1);
        free(word2);
        return 1;
    }
    // rearrange the letters to be in ASCIIbetical order, remember to tolower()
    if (strlen(word1) != strlen(word2))
    {
        printf("Not anagrams.\n");
        free(word1);
        free(word2);
        return 0;
    }
    int length = strlen(word1);
    for (int i = 0; i < length; i++)
    {
        word1[i] = tolower(word1[i]);
        word2[i] = tolower(word2[i]);
    }
    sortbyascii(word1);
    sortbyascii(word2);
    printf("%s\n", word1);
    printf("%s\n", word2);
    if (strcmp(word1, word2) == 0)
    {
        printf("These are anagrams of each other.\n");
    }
    else
    {
        printf("These are not anagrams!!\n");
    }
    free(word1);
    free(word2);
    return 0;
}

char *get_string(char *input_text)
{
    printf("%s", input_text);
    char *buffer = malloc(sizeof(char));
    scanf("%s", buffer);
    return buffer;
}

void sortbyascii(char *input)
{
    int length = strlen(input);
    int changed = 1;
    char temp;
    for (int i = 0; i < length - 1; i++)
    {
        if (toascii(input[i]) > toascii(input[i + 1]))
        {
            temp = input[i + 1];
            input[i + 1] = input[i];
            input[i] = temp;
            changed = 0;
        }
    }
    if (changed)
    {
        sortbyascii(input);
    }
    return;
}
