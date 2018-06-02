#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Press Enter to clear the screen:");
    getchar();
    system("cls");  /* Windows only*/
    system("clear");/* mac - unix */
    puts("That's better");
    return(0);
}