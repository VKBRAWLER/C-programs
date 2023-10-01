#include<stdio.h>
int main(){
    int i = 0;
    int arr[6];
    while(i < 6){
        scanf("%d", &arr[i]);
        i++;
    }
    i = 0;
    while(i < 6){
        printf("%d\n", arr[i]);
        i++;
    }

    // for ( i = 0; i <= 5 ; i++ ){
    //     printf("%d", i);
    // }
}