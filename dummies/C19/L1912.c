#include <stdio.h>
 
 char *strrev(char *input);

 int main()
 {
     char string[64];

     printf("Type some text: ");
     fgets(string,62,stdin);
     puts(strrev(string));

     return(0);
 }

 char *strrev(char *input)
 {
     static char output[64];
     char *i, *o;

     i=input; o=output;

     while(*i++ != '\n');

     i--;

     while(i >= input)
        *o++ = *i--;
    *o = '\0';
    return(output);
 }