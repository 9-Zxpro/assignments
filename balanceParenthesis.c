#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stk[MAX], top = -1;

int main(){
    char exp[MAX], tmp;
    int flag = 1, i=0;
    printf("Enter the expressoin : ");
    scanf("%s" , exp);

    char pop() {
        if(top == -1)
            printf("underflow");
        else
            return stk[top--];
    }

    void push(char c) {
        if (top == MAX-1)
            printf("overflow");
        else
            stk[++top];
    }

    while (exp[i] != '\0'){
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(top == -1)
                flag = 0;
            else{
                tmp = pop();
                if(exp[i] == ')' && (tmp == '{' || tmp == '['))
                    flag = 0;
                if(exp[i] == '}' && (tmp == '(' || tmp == '['))
                    flag = 0;
                if(exp[i] == ']' && (tmp == '{' || tmp == '('))
                    flag = 0;
            }
        }
        i++;
    }

    if(top >= 0)
        flag = 0;
    if (flag == 1)
        printf("balanced");
    else
        printf("Not balanced");
    

    return 0;
}