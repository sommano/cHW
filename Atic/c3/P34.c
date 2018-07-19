#include <stdio.h>

int main() {
    void makeTable(int, int, double (*fp) (int));
    double reciprocal(int);
    makeTable(1, 10, reciprocal);
} //end main

void makeTable(int first, int last, double (*fp) (int)) {
    for (int h = first; h <= last; h++)
        printf("%2d    %0.3f\n", h, (*fp)(h));
} //end makeTable

double reciprocal(int x) {
    return 1.0 / x;
} //end reciprocal
