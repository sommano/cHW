#include <stdio.h>

#define SIZE 3

int main()
{
    char president[SIZE][8] = {
        "Clinton",
        "Bush",
        "Obama"
    };
    int x, index;

    for(x=0;x<SIZE;x++)
    {
        index = 0;
        while(president[x][index] != '\0')
        {
            putchar(president[x][index]);
            index++;
        }
        putchar('\n');
    }
    return(0);
}