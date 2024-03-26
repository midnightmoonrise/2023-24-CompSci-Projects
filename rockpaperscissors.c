#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool checkmove(char p1, char p2);
void play(char p1, char p2);

int main(void)
{
    char p1move;
    char p2move;
    char garbagecan;
    printf("Welcome to rock paper scissors! Enter r=rock, s=scissors, p=paper\n");
    printf("Enter first player's move: ");
    scanf("%c", &p1move);
    // my version of fflush(stdin)
    scanf("%c", &garbagecan);
    printf("Enter second player's move: ");
    scanf("%c", &p2move);
    // again, Knockoff fflush(stdin)
    scanf("%c", &garbagecan);
    p1move = tolower(p1move);
    p2move = tolower(p2move);
    if (!checkmove(p1move, p2move))
    {
        return 1;
    }
    play(p1move, p2move);
    return 0;
}

bool checkmove(char p1, char p2)
{
    if (p1 != 'r' && p1 != 's' && p1 != 'p')
    {
        printf("Player 1 guess invalid. Game terminated.\n");
        return false;
    }
    else if (p2 != 'r' && p2 != 's' && p2 != 'p')
    {
        printf("Player 2 guess invalid. Game terminated.\n");
        return false;
    }
    return true;
}

void play(char p1, char p2)
{
    if (p1 == p2)
    {
        printf("Tie!\n");
    }
    else if (p1 == 'r' && p2 == 's')
    {
        printf("Player 1 wins!\n");
    }
    else if (p1 == 's' && p2 == 'p')
    {
        printf("Player 1 wins!\n");
    }
    else if (p1 == 'p' && p2 == 's')
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
    return;
}
