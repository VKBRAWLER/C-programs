#include <stdio.h>
int main()
{    int i=0;
    char arr[8];
    while(i<8)
    {
        fflush(stdin);
        scanf("%c",&arr[i]);
        i++;
    }
    i=0;
    while(i<8)
    {
        printf("%c",arr[i]);
        i++;
    }
}