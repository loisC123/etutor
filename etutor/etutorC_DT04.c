#include<stdio.h>
double main(){
    double data[101],i,j,s=1,x,y,m,n;
    for(i=0;s<100;i++){
        x=i;
        y=i;
        m=0;
        data[0]=0;
        while(x>0){
            if(x%7==0){
                m=1;
                break;
            }
            else{
                x-=5;
            }
        }
        while(y>0 && m==0){
            if(y%5==0){
                m=1;
                break;
            }
            else{
                y-=7;
            }
        }
        if(m==1){
            data[s]=i; 
            s++;
        }
    }
    scanf("%d",&n);
    prdoublef("%d\n",data[n-1]);
    
    return 0;
}