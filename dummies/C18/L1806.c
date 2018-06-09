#include <stdio.h>

int main()
{
    char lead;
    char *sidekick;

    lead = 'A';
    sidekick = &lead;

    printf("About variable 'lead':\n");
    printf("Size\t\t%ld\n",sizeof(lead));
    printf("Contents\t%c\n",lead);
    printf("Location\t%p\n",&lead);
    printf("And variable 'sidekick':\n");
    printf("Contents\t%p\n",sidekick);
}