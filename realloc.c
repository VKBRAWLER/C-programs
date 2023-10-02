#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
char *ptr;
ptr = (char *) malloc (18);
ptr = "Understanding DMA";
printf("%s is in memory block\n", ptr);
ptr = (char *) realloc (ptr,40);
printf("%s is in memory block\n",ptr);
strcpy(ptr, "Understanding Dynamic Memory Allocation"); 
printf("Now %s is in memory block", ptr);
return (0);
}