#include <stdio.h>

int main()
{
    int c;

    printf("i'm waiting for a character: ");
    c = getchar();
    printf("I waited for the '%c' character.\n",c);
    return(0);
}