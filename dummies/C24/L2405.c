#include <stdio.h>
#include <stdlib.h>

/* prototypes */

void fillstructure(void);
void printstructure(void);

/* constants */

/* variables */

struct thing {
    char name[32];
    int age;
    };

typedef struct thing human;