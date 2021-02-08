#include <stdio.h> 
#include <stdlib.h> 
#define MAX 60

double cal(char,double,double); 

int main() { 
    char infix[MAX] = {'\0'}; 
    double stack[MAX]={0.0}; 
    
    gets(infix);
    int top,i,m=0,ansewr;
    double number=0.0;
    for(top = 0, i = 0; m!=1; i++){
        switch(infix[i]){ 
            case '+': case '-': case '*': case '/':
                stack[top - 1] = cal(infix[i], stack[top - 1], stack[top]); 
                top--; 
                break;
            case' ':case'\0':
                if(infix[i+1]=='\0') m=1;
                else if(infix[i-1]!='+'&&infix[i-1]!='-'&&infix[i-1]!='*'&&infix[i-1]!='/'&&infix[i-1]!='%'){
                    stack[++top]= number;
                    number=0.0;
                }
                break;
            default:
                   number = number * 10 + infix[i] - 48;  
                break;
        }
    }   
        ansewr =(int)(stack[top]*100)/100;
        printf("%d\n",ansewr); //小數無條件捨去 floor()小於等於某數的最大整數
    return 0; 
} 

double cal(char op,double p1,double p2) { 
    switch(op) { 
        case '+': return (p1*p1) + (p2*p2); 
        case '-': return (p1*p1) - (p2*p2); 
        case '*': return (p1*p1) * (p2*p2); 
        case '/': return (p1*p1) / (p2*p2);
    } 
}