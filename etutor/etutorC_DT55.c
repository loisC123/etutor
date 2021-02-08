#include <stdio.h>   
#include <stdlib.h>   
#define MAX 100  
  
void inToPostfix(char*, char*); // 中序轉後序   
int priority(char); // 運算子優先權  
double cal(char op,double p1,double p2) { 
    switch(op) { 
        case '+': return (p1*p1) + (p2*p2); 
        case '-': return (p1*p1) - (p2*p2); 
        case '*': return (p1*p1) * (p2*p2); 
        case '/': return (p1*p1) / (p2*p2);
    } 
}
int main() {  
    char infix[MAX] = {'\0'};
    char postfix[MAX]= {'\0'};
    double calculation[MAX]={'\0'};  
    int top,i,m=0,ansewr;  
        gets(infix);   
        inToPostfix(infix,postfix); 
        //printf("%s\n",postfix);//確認中序轉後序
    for(top = 0, i = 0; m!=1; i++){
        switch(postfix[i]){ 
            case '+': case '-': case '*': case '/':
                calculation[top - 1] = cal(postfix[i],calculation[top - 1],calculation[top]); 
                top--; 
                break;
            case'\0':case' ':
                if(postfix[i+1]=='\0') m=1;
                break;
            default:
                   calculation[++top]=postfix[i]-48;
                   //printf("%f\n",calculation[top]); //查證存入陣列數字
                break;
        }
    }   
        ansewr =(int)(calculation[top]*100)/100;//小數無條件捨去
        printf("%d\n",ansewr); 
    return 0;   
}   
  
void inToPostfix(char* infix, char* postfix){  
    char stack[MAX]={'\0'};  
    int i, j, top=0,m=0;  
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
                    break;
            case'\r':   
                    break;       
            default:  // 運算元直接輸出   
                    postfix[j++] = infix[i];  
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