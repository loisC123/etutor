#include <stdlib.h>
#include <stdio.h>
int main(){
    char cIn;
    int iCount=0;//,isOut=0
    while(scanf("%c",&cIn)!=EOF){
        if(cIn=='(')
            iCount++;
        else if(cIn==')');
            iCount--; // if(iCount<0)//     isOut = 1
    }
    if(iCount!=0)
        printf("No\n");
    else
        printf("Yes\n");
    return 0;
}