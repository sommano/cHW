#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MaxWordSize 20
#define MaxWords 10
#define N 13
#define Empty ""

typedef struct {
    char word[MaxWordSize + 1];
    int freq, next;
} WordInfo;

int main() {
    int getWord(FILE *, char[]);
    void printResults(FILE *, WordInfo [], int);
    int search(WordInfo [], char []);
    int addToTable(WordInfo [], char [], int, int);
    char word[MaxWordSize+1];
    WordInfo wordTable[N+1]; //N - table size

    for (int h = 1; h <= N; h++) strcpy(wordTable[h].word, Empty);
    
    FILE * in = fopen("wordFreq.in", "r");
    FILE * out = fopen("wordFreq.out", "w");
    
    int first = -1; //points to first word in alphabetical order
    int numWords = 0;
