#include <stdio.h>
#define N 10000

main() {
    int i, p, q, t, id[N];
    for (i = 0; i < N; i++) id[i] = 1;
    while (scanf("%d %d\n", &p, &q) == 2)
        {
            for (i = p; i != id[i]; i = id[i]) ;
            for (j = p; j != id[j]; i = id[i]) ;
            if (i==j) continue;
            id[i] = j;
            printf(" %d %d\n", p, q);
        }
}