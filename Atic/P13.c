#include <stdio.h>
#include <string.h>
#define MaxNameSize 14
#define MaxNameBuffer MaxNameSize+1
#define MaxNames 8

int main() {
    void insertionSort3(int, int, int max, char [][max]);
    char name[MaxNames][MaxNameBuffer] = {"Taylor, Victor", "Duncan, Denise",
        "Ramdhan, Kamal", "Singh, Krishna", "Ali, Michael",
        "Sawh, Anisa", "Khan, Carol", "Owen, David" };
        
    insertionSort3(0, MaxNames-1, MaxNameBuffer, name);
    printf("\nThe sorted names are\n\n");
    for (int h = 0; h < MaxNames; h++) printf("%s\n", name[h]);
} //end main
