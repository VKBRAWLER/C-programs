#include<stdio.h>

int main() {
char *str_constant = "I point to a string literal";
char str_buf[] = "I am an array of char initialized with a string literal";

printf("string literal = %s\n", "I am a string literal");
printf("str_constant = %s\n", str_constant);
printf("str_buf = %s\n", str_buf);

scanf("%55s", str_buf);
printf("str_buf = %s\n", str_buf);
}