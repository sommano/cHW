#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));
    printf("%i\n", rand());
}