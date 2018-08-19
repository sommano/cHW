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

    while (getWord(in, word) != 0) {
        int loc = search(wordTable, word);
        if (loc > 0) wordTable[loc].freq++;
        else //this is a new word
            if (numWords < MaxWords) { //if table is not full
                first = addToTable(wordTable, word, -loc, first);
                ++numWords;
            }
            else fprintf(out, "'%s' not added to table\n", word);
    }
    printResults(out, wordTable, first);
    fclose(in);
    fclose(out);
} // end main

int getWord(FILE * in, char str[]) {
// stores the next word, if any, in str; word is converted to lowercase
// returns 1 if a word is found; 0, otherwise
    char ch;
    int n = 0;
    // read over non-letters
    while (!isalpha(ch = getc(in)) && ch != EOF) ; //empty while body
        if (ch == EOF) return 0;
    str[n++] = tolower(ch);
    while (isalpha(ch = getc(in)) && ch != EOF)
    if (n < MaxWordSize) str[n++] = tolower(ch);
    str[n] = '\0';
    return 1;
} // end getWord

int search(WordInfo table[], char key[]) {
//search for key in table; if found, return its location; if not,
//return -loc if it must be inserted in location loc
    int convertToNumber(char []);
    int keyNum = convertToNumber(key);
    int loc = keyNum % N + 1;
    int k = keyNum % (N - 2) + 1;
    while ((strcmp(table[loc].word, Empty) != 0) &&
            (strcmp(table[loc].word, key) != 0)) {
        loc = loc + k;
        if (loc > N) loc = loc - N;
    }
    if (strcmp(table[loc].word, Empty) == 0) return -loc;
    return loc;
} // end search
