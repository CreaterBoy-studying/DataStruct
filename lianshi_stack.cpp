// Copyright [2022.11.11] Shan
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct node{
    ElemType data;
    struct node *next;
}node,*LinkStack;
//int *&p 表示 int *x = &p
void InitStack(LinkStack &ls){
    ls = NULL;
}
void DestroyStack(LinkStack &ls){
     node *pre=ls,*p;
     if(pre==NULL) return;
     while(p!=NULL){
        free(pre);
        pre=p;
        p=p->next;
     }
     free(pre);
}
int Push(LinkStack &ls,ElemType x){
    node *p;
    p = (node *)malloc(sizeof(node));
    p->data = x;
    p->next = ls;
    ls = p;
    return 1;
}
int Pop(LinkStack &ls,ElemType &x){
    node *p;
    if(ls==NULL){
        return 0;
    }
    else{
        p=ls;
        x = p->data;
        ls = p->next;
        free(p);
        return 1;
    }
}
int GetTop(LinkStack ls,ElemType &x){
    if(ls==NULL){
        return 0;
    }
    else{
        x = ls->data;
        return 1;
    }
}
int StackEmpty(LinkStack ls){
    if(ls==NULL) return 1;
    else return 0;
}

int main() { 
    ElemType e;
    LinkStack st;
    printf("初始化栈 st\n");
    InitStack(st);
    printf("栈%s\n",(StackEmpty(st)==1?"空":"不空"));
    printf("1进栈\n");
    Push(st,1);
    printf("2进栈\n");
    Push(st,2);
    printf("3进栈\n");
    Push(st,3);
    printf("栈%s\n",(StackEmpty(st)==1?"空":"不空"));
    GetTop(st,e);
    printf("栈顶元素,%d\n",e);
    printf("出栈次序：");
    while(!StackEmpty(st)){
        Pop(st,e);
        printf("%d ",e);
    }
    printf("\n");
    return 0; 
}