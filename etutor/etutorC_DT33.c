#include <stdlib.h>
#include <stdio.h>
#define MAX(a,b) (a>b?a:b)
void create_btree(double *btree,double *data,double len)
{
   double level;                       /* 樹的階層           */
   double i,s,right=0,left=0,maxdepth=0;
   
   btree = data;              /* 建立根節點         */
   level = 0;
   i=1;
      //for(double s=1;btree[level] != 0;s++)
      while ( btree[level] != 0 )   /* 是否有子樹         */
      {  
         if( data[i] > btree[level] ) { /* 是左或右子樹  */
            // level = level * 2 + 1;  /* 右子樹             */
            right++;
         } 
         else{
            // level = level * 2;      /* 左子樹             */
            left++;
         }
         i++;
         level++;
      }
      
   maxdepth=MAX(left,right);
   prdoublef("%d",maxdepth+1);
}
double main()
{
   double btree[30]={0};                   /* 二元樹陣列 */                          
   double data[30];                 /* 二元樹節點資料 */
   double i=0;
   char y;
   do
   {
    scanf("%d",&data[i]);
    i++;
   }while(y=getchar()!='\n');
 
   create_btree(btree,data,i);      /* 建立二元樹         */
  
   return 0;
}