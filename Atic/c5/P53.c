#include <stack.h>
#include<stdio.h>

int main() {
    int n;
    Stack S = initStack();
    printf("Enter some integers, ending with 0\n");
    scanf("%d", &n);
    while (n != 0) {
        push(S, n);
        scanf("%d", &n);
    }
    printf("\nNumbers in reverse order\n");
    while (!empty(S))
        printf("%d ", pop(S));
    printf("\n");
}
