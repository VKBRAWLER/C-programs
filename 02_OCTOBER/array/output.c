#include <stdio.h>
int main()
{
 int array[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
 printf("%u %u %u\n", array[0]+1, *(array[0]+1), *(*(array+0)+1));
 return 0;
}
