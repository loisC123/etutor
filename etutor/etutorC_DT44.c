#include <stdlib.h>
#include <stdio.h>
typedef struct node{
    int data;
    struct node *next;
}LNode;
LNode* Create(int,int);
LNode* GetNode(LNode *);
LNode *p;
int main(){
    int Print(LNode *,int);
    int n,k,m;
    scanf ("%d%d%d",&n,&k,&m);//n人數 k起始 m數字
    p=Create(n,k);
    Print(p,m);
    return 0;
}
LNode* Create(int n,int k){/*循環列*/
    int start=k-1;
    LNode *s,*p,*L=0,*t;
    if (start==0) start=n;
    while (n!=0){
        s=(LNode *)malloc(sizeof(LNode));
        if (L==0) p=s;
        if (n==start) t=s;
        s->data=n;
        s->next=L;
        L=s;
        n--;
    }
    p->next=L;
    return t;
}
LNode* GetNode(LNode *p){/*淘汰*/
    LNode *q;
    for (q=p;q->next!=p;q=q->next);
    q->next=p->next;
    free (p);
    return (q);
}
int Print(LNode *p,int m){/*輸出*/
    int i;
    while (p->next!=p){
        for (i=1;i<=m;i++)
        p=p->next;
        printf ("%d ",p->data);
        p=GetNode(p);
    }
    printf("%d\n",p->data);
    return 0;
}