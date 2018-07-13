#include <stdio.h>
#define MaxNumbers 10

int main() {
    void selectionSort(int [], int, int);
    int num[MaxNumbers];
    printf("Type up to %d numbers followed by 0\n", MaxNumbers);
    int n = 0, v;
    scanf("%d", &v);
    while (v != 0 && n < MaxNumbers) {
        num[n++] = v;
        scanf("%d", &v);
    }
    if (v != 0) {
        printf("More than %d numbers entered\n", MaxNumbers);
        printf("First %d used\n", MaxNumbers);
    }
    //n numbers are stored from num[0] to num[n-1]
    selectionSort(num, 0, n-1);
    printf("\nThe sorted numbers are\n");
    for (int h = 0; h < n; h++) printf("%d ", num[h]);
    printf("\n");
}
