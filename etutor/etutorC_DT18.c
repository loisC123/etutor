#include <stdio.h>   
#include <stdlib.h>   
#define MAX 60  
int cal(char,int,int);   
  
int main(void) {   
    char infix[MAX] = {'\0'};   
    int stack[MAX]={0},space[MAX];   
    gets(infix);  //getchar();  
    int top,i,m=0,number=0;  
    for(top = 0, i = 0; m!=1; i++){  
        switch(infix[i]){   
            case '+': case '-': case '*': case '/': case '%':  
                stack[top - 1] = cal(infix[i], stack[top - 1], stack[top]);   
                top--;   
                break;  
            case' ':case'\0':  
                if(infix[i+1]=='\0') m=1;  
                else if(infix[i-1]!='+'&&infix[i-1]!='-'&&infix[i-1]!='*'&&infix[i-1]!='/'&&infix[i-1]!='%'){  
                    stack[++top]= number;  
                    number=0;  
                }  
                break;  
            default:   
                   number = number * 10 + infix[i] - 48;       
                break;  
        }  
    }  
        printf("%d\n",stack[top]);  
    return 0;   
}   
int cal(char op,int p1,int p2) {   
    switch(op) {   
        case '+': return p1 + p2;   
        case '-': return p1 - p2;   
        case '*': return p1 * p2;   
        case '/': return p1 / p2;  
        case '%': return p1 % p2;  
    }   
}