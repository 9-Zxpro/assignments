#include <stdio.h>
#include <stdlib.h>

int main(){
    char a  = 'v';
    char *ptr = (char *)malloc(sizeof(char));
    ptr = &a;
    free(ptr);
    printf("%c", *ptr);
    return 0;

}