#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int main(){
    int n, k, count=0, num[MAX], tmp[MAX];
    printf("Enter the elements in array[-1 for stop] : ");
    for(int i=0; i<MAX; i++){
        scanf("%d", &n);
        if(n==-1)
            break;
        num[i]=n;
        count++;
    }
    printf("Enter the left rotation number : ");
    scanf("%d", &k);

    for(int i=0; i<k; i++){
        tmp[i]=num[i];
    }
    for(int i=k; i<count; i++){
        num[i-k]=num[i];
    }
    for(int i=0; i<k; i++){
        num[count-k+i]=tmp[i];
    }

    printf("After rotation array is : ");
    for(int i=0; i<count; i++){
        printf("%d ", num[i]);
    }

    return 0;
}