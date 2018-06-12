#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct entry {
        char actor[32];
        int year;
        char title[32];
    };
    struct entry bond;
    FILE *a007;
    int count=0;

    a007 = fopen("bond.db","r");
    if(!a007)
    {
        puts("SPECTRE wins!");
        exit(1);
    }
    while(fread(&bond,sizeof(struct entry),1,a007))
    {
        printf("%s\t%d\t%s\n",
            bond.actor,
            bond.year,
            bond.title);
        if(ftell(a007) > sizeof(struct entry))
            rewind(a007);
        count++;
        if(count>10) break;
    }
    fclose(a007);

    return(0);
}