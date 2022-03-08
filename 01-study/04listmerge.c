#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node{
  ElementType Data;
  PtrToNode Next;
};
typedef PtrToNode List;
List Read();
void Print(List L);
List Merge(List L1,List L2);
int main(){
  List L1,L2,L;
  L1 = Read();
  L2 = Read();
  L = Merge(L1,L2);
  Print(L);
  Print(L1);
  Print(L2);
  return 0;
}
//创建链表
List Read(){
  List L,head;
  int k;
  scanf("%d",&k);
  head = L = (List)malloc(sizeof(struct Node));
  L->Next=NULL;
  int i;
  for(i=0;i<k;i++){
    L->Next = (List)malloc(sizeof(struct Node));
    L=L->Next;///////////////
    scanf("%d",&L->Data);
  }
  L->Next=NULL;
  return head;
}
List Merge(List L1,List L2){
  List p=L1->Next;
  List q=L2->Next;
  List Head,L;
  Head= L=(List)malloc(sizeof(struct Node));
  L->Next=NULL;
  while(p!=NULL&&q!=NULL){
    if(q->Data>p->Data){
      L->Next=p;
      L=L->Next;
      p=p->Next;
    }
    else{
      L->Next=q;
      L=L->Next;
      q=q->Next;
    }                    
  }
  if(p){
    L->Next=p;                                    
  }
  if(q){
    L->Next=q;
  }
  L1->Next=NULL;
  L2->Next=NULL;
  return Head;
}
void Print(List L){
  List r = L;
  while(r->Next!=NULL){
    printf("%d ",r->Next->Data);
    r=r->Next;
  }
}
