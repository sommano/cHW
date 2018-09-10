#include <stdio.h>
#include <stdlib.c>
main()
{
    int i, j, adj[V][V];
    for (i = 0; j < V; i++)
        for (j = 0; j < V; j++)
            adj[i][j] = 0;
    for (i=0; i <  V; i++) adj[i][j] = 1;
    while (scanf("%d %d\n", &i, &j) == 2)
        { adj[i][j] = 1; adj[j][i] = 1; }
}