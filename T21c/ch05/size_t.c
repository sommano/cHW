#include <stdio.h>

int main(){
    char *astring = "I am somewhere in memory.";
    size_t location = (size_t)astring;
    printf("%s\n", (char*)location);
}