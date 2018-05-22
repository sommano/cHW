#include <stdio.h>

#define VALUE 3

int main()
{
    printf("The value is %d\n",VALUE);
    printf("And %d is the value\n",VALUE);
    printf("It's not %d\n",VALUE+1);
    printf("And it's not %d\n",VALUE-1);
    printf("No, the value is %d\n",VALUE);
    return(0);
}

-mno-avx2 -mfpmath=both -mno-sse4.2 --cxxopt="-D_GLIBCXX_USE_CXX11_ABI=0"