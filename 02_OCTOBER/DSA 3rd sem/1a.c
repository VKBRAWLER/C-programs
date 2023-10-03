#include <stdio.h>
int main()
{
    int arr[50], i, n, sum = 0;
    printf("enter the range: ");
    scanf("%d", &n);
    printf("enter the elements: ");
    for (i = 0; i <= n - 1; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i <= n - 1; i++)
    {
        if (arr[i] % 2 == 0)
        {
            sum = sum + arr[i];
        }
    }
    printf("Sum of even elements:%d", sum);
    return 0;
}
