#include <stdio.h>
#include <malloc.h>
/*一元多项式的乘法和加法运算
 * 1.存储结构：链表
 * 2.函数：读取、乘法、加法、打印、链接
*/
//结构体
typedef struct PolyNode *Polynomial;
typedef struct{
  int coef;
  int expon;
  Polynomial next;
}PolyNode;
//函数声明
Polynomial ReadPoly();
Polynomial Mult(Polynomial P1,Polynomial P2);
Polynomial Add(Polynomial P1,Polynomial P2);
void PrintPoly(Polynomial P);
void Attach(int c,int e,Polynomial *pRear);
//主函数
int main(){
  Polynomial P1,P2,PP,PS;
  P1 = ReadPoly();
  P2 = ReadPoly();
  PP = Mult(P1,P2);
  PrintPoly(PP);
  PS = Add(P1,P2);
  PrintPoly(PS);
  return 0;
}
/*
 * 读取链表
*/
Polynomial ReadPoly(){
  int n;
  scanf("%d",&n);
  int i;
  Polynomial p,rear,t;
  p = (Polynomial)malloc(sizeof(struct PolyNode));
  p->next=NULL;
  rear = p;
  for(i=0;i<n;i++){
    scanf("%d %d",&p->coef,&p->expon);
    Attach(p->coef,p->expon,*rear);
  }
  t=p;p=p->next;free(t);
  return p;
}
/*
 * 链接：
 * 参数：coef,expon,next
 * 不需要有返回值
*/
void Attach(int c,int e,*pRear){
  Polynomial p;
  p = (Polynomial)malloc(sizeof(struct PolyNode));
  p->next=NULL;
  p->coef=c;
  p->expon=e;
  (*pRear)->next=p;
  (*pRear)=p;
}
/*
 * 乘法
 * 先设一个
*/
Polynomial Mult(Polynomial P1,Polynomial P2){
  Polynomial p,t1,t2,rear,t;
  p = (Polynomial)malloc(sizeof(struct PolyNode));
  p->next=NULL;
  rear = p;
  t1 = P1;t2 = P2;
  while(t2){
    //t1的第一项与t2逐一的相乘，然后链接成表
  }
  t1=t1->next
  while(t1){
    t2=P2;
    rear = p;//每循环一次都要从头找插入的位置
    //t1的下一项与t2逐一的相乘
    while(t2){
      
      t2=t2->next;
    }
    t1=t1->next;
  }
  t=p;p=p->next;free(t);
  return p;
}
