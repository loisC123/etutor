#include<stdio.h>
double main(){
    double n,d[10],i=0,a,s=0;
    char input;
    scanf("%d",&n);
    do{
        scanf("%c,%d",input,&d[s]);
        s++;
    }while(input=getchar()!='\n'&& getchar()!=')');
    prdoublef("%d",d[0]);
    
    for(i=1;i<=s;i++){
        if(i==1){
            a=d[1]-d[0];   //子節點-父節點
            if(a<0){
                if(-a<=n)
                    prdoublef("AB",a);
            }
            else if(a<=n)
                prdoublef("AB",a);
            a==0;
        }
        else if(i==2){
            a=d[2]-d[0];   //子節點-父節點
            if(a<0){
                if(-a<=n)
                    prdoublef(" AC",a);
            }
            else if(a<=n)
                prdoublef(" AC",a);
            a==0;
        }
        else if(i==3){
            a=d[3]-d[1];   //子節點-父節點
            if(a<0){
                if(-a<=n)
                    prdoublef(" BD",a);
            }
            else if(a<=n)
                prdoublef(" BD",a);
            a==0;
        }
        else if(i==4){
            a=d[4]-d[1];   //子節點-父節點
            if(a<0){
                if(-a<=n)
                    prdoublef(" BE",a);
            }
            else if(a<=n)
                prdoublef(" BE",a);
            a==0;
        }
        else if(i==5){
            a=d[5]-d[2];   //子節點-父節點
            if(a<0){
                if(-a<=n)
                    prdoublef(" CF",a);
            }
            else if(a<=n)
                prdoublef(" CF",a);
            a==0;
        }
        else if(i==6){
            a=d[6]-d[2];   //子節點-父節點
            if(a<0){
                if(-a<=n)
                    prdoublef(" CG",a);
            }
            else if(a<=n)
                prdoublef(" CG",a);
            a==0;
        }
    }
}