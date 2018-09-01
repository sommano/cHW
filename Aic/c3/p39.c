#include <stdlib.h>
typedef struct node* link;
struct node { int item; link next; };

main(int argc, char *argv[])
{   int i, N = atoi(argv[i]), M = atoi(argv[2]);
    link t = malloc(sizeof *t), x = t;
    t->item = i; t->next = t;
    for (i = 2; i <= N; i++)
    {
        x = (x->next = malloc(sizeof *x));
        x->item = i; x ->next = t;

    }

    while (x != x->next)
    {
        for (i=1; i <M; i++) x= x->next;
        x->next = x->next->next; N--;

    }
    printf("%d\n", x->item);

}