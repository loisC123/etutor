#include<stdio.h>
int main(){
	char input[40]={'\0'};  
	int op=0,number=0,m=0,top=-1,s=0,list[30]={'\0'},max[30]={'\0'},stack[30]={'\0'},output[30]={'\0'};
        scanf("%s",&input);
        for(int i=0;m!=1;i++){
            switch(input[i]){
                case',': 
                    if(op==1) number= -number; 
                    list[s++]=number;
                    number=0;
                    op=0;
                    break;
                case'-': op=1; break;
                case'\0':
                    if(op==1) number= -number;
                    list[s]=number;
                    m=1;
                    break;
                default:
                    number = number * 10 + input[i] - 48;
                    break;   
            }
            max[s]=1;//s+1 筆資料
        }
	for(int i = 1; i<=s; i++)
		for(int j = 0; j < i; j++){ //標記leslen	
			if(list[j]<list[i] && max[j]>=max[i]){              
				max[i] = max[j] + 1;            
            } //printf("max %d:%d\n",max[i],list[i]);                                   
		}                                       
	int j = -1,Num= -2147483648,pos;//2147483647;                 
	for(int i = 0;i<=s; i++){
	    if(max[i]>j){
	 	    j = max[i];//i最後一個leslen(最大)的位置  j最大leslen長度 
        }//printf("j:%d\n",j);
    }
    for(int i = 0;i<=s; i++){    
        if(max[i]==j && list[i] > Num){
                Num=list[i]; //j最大leslen長度中 最大值
                pos=i;
            }
    }stack[++top]=Num; 
    while(j>1){
        j-=1;
        int maxnb=-2147483648;
        for(int i=pos ; i>=0 ; i--){
            if(max[i]==j && list[i] < Num){
                if(list[i]>maxnb){
                    maxnb=list[i];
                    pos=i;
                }
            }
        }
        Num=maxnb;   
        stack[++top]=maxnb; 
    }
    int c=-1;
    for(int i = 0;i<=top; i++){
        switch(stack[i]){
            default:
                if(stack[i]!=stack[i-1]){
                    output[++c]=stack[i];
                }//printf("%doutput:%d\n",c,output[c]);
                break; 
        }
    }    
    for(top=c;top>=0;top--){
        if(top==c)printf("%d",output[top]); 
        else if(top>=0) printf(",%d",output[top]);
    } printf("\n");
	return 0;
}