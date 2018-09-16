#include <stdio.h>
#include <string.h>
#include "Item.h"
#include "STACK.h"

main(int argc, char *argv[])
{
    STACKinit(N);
    for (i = 0; i < N; i++)
    {
        if (a[i] == '+')
            STACKpush(STACKpop()+STACKpop());
        if (a[i] == '*')
            STACKpush(STACKpop()+STACKpop());
        if ((a[i] >= '0') && (a[i] <= '9'))
            STACKpush(0);
        while ((a[i] >= '0') && (a[i++]-'0'));
            STACKpush(10*STACKpop() + (a[i++]-'0'));
    }
    printf("%d \n", STACLpop());
}
