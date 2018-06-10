#include <stdio.h>

int main()
{
    char alphabet[27];
    int x;
    char *pa;

    pa = alphabet;

    for(x=0;x<26;x++)
    {
        *pa=x+'A';
        pa++;
    }

    pa = alphabet;

    for(x=0;x<26;x++)
    {
        putchar(*pa);
        pa++;
    }

    putchar('\n');

    return(0);
}