#include <stdio.h>   
#include <stdlib.h>   
 
#define MAX 80  
  
void inToPostfix(char*, char*); // 中序轉後序   
int priority(char); // 運算子優先權  
  
int main(void) {  
    char infix[MAX] = {'\0'};//  
    char postfix[MAX]= {'\0'};  
    int n,ss=0,s=0,i;//push=0  
    scanf("%d",&n);  
    getchar();  
    //fflush(stdin);  
    for(s=0;s<n;s++){  
            char infix[MAX] = {'\0'};  
            char postfix[MAX]= {'\0'};  
            gets(infix);   
            inToPostfix(infix,postfix);  
        for(i = 0; postfix[i] !='\0'; i++){  
            if(postfix[i]=='\r') break;  
            printf("%c ",postfix[i]);   
        }  
        printf("\n");  
    }  
    return 0;   
}   
  
void inToPostfix(char* infix, char* postfix){  
    char stack[MAX]={'\0'},space[MAX]={'\0'};  
    int i, j, top=0,m=0,number=0;  
    for(i = 0, j = 0, top = 0;i<MAX;i++){  
        if(m==0){  
            switch(infix[i]){   
                case '(':              // 運算子堆疊   
                    stack[++top] = infix[i];   
                    break;   
                case '+': case '-': case '*': case '/':   
                    while(priority(stack[top]) >= priority(infix[i])) {   
                        postfix[j++] = stack[top--];  
                    }   
                    stack[++top] = infix[i]; // 存入堆疊   
                    break;   
                case ')':   
                    while(stack[top] != '(') { // 遇 ) 輸出至 (   
                        postfix[j++] = stack[top--];  
                    }   
                    top--;  // 不輸出 (   
                    break;   
                case' ':case'\0':
                if(infix[i+1]=='\0') m=1;
                else if(infix[i-1]!='+'&&infix[i-1]!='-'&&infix[i-1]!='*'&&infix[i-1]!='/'){
                    postfix[j++]= number;
                    number=0;
                }
                    // if(infix[i+1]=='\0') m=1;  
                    break;    
                case'\r':  
                    break;  
                default:  // 運算元直接輸出 
                    number = number * 10 + infix[i] - 48;  
                    //postfix[j++] = infix[i];  
                    break;  
            }  
        }  
    }  
    while(top > 0) {   
        postfix[j++] = stack[top--];  
    }  
}   
int priority(char op) {   
    switch(op) {   
        case '+': case '-': return 1;  
        case '*': case '/': return 2;  
        default:            return 0;  
    }   
}  