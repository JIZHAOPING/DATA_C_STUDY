#include <stdio.h>
#include <malloc.h>
//如果不加头文件，会出现"隐式声明与内建函数malloc不兼容"的错误
/*
1.确定存储结构：链表
2.确定函数主体流程 main
*/
//必须先声明结构体
typedef struct PolyNode * Polynomial;
typedef struct PolyNode{
  int coef;
  int expon;
  Polynomial link;
}PolyNode;//如果这里不写，那么就会出现"空声明字指定存储类无用"的错误
//函数声明
Polynomial ReadPoly();
Polynomial Mult(Polynomial P1,Polynomial P2);
Polynomial Add(Polynomial P1,Polynomial P2);
void PrintPoly(Polynomial P);
void Attach(int c,int e,Polynomial *pRear);

int main(){
  Polynomial P1,P2,PP,PS;
  P1 = ReadPoly();
  P2 = ReadPoly();
  //PP = Mult(P1,P2);
  //PrintPoly(PP);
  PS = Add(P1,P2);
  PrintPoly(PS);
  //printf("%d",P1->coef);
  //PrintPoly(P1);
  //PrintPoly(P2);
  return 0;
}
Polynomial ReadPoly(){
  Polynomial P,Rear,t;
  P = (Polynomial)malloc(sizeof(struct PolyNode));
  Rear = P;
  P->link = NULL;
  int c,e,n;
  scanf("%d",&n);
  while(n--){
    scanf("%d %d",&c,&e);
    Attach(c,e,&Rear);//调用函数改变指针指向必须用二级指针
  }
  t = P;P = P->link;free(t);
  return P;
}
void Attach(int c,int e,Polynomial *pRear){//返回值是void，因为是通过改变指针，所以不需要有返回值
  Polynomial p;
  p = (Polynomial)malloc(sizeof(struct PolyNode));
  p->link = NULL;
  p->coef = c;
  p->expon = e;
  (*pRear)->link = p;//加括号！
  *pRear = p;
}
Polynomial Mult(Polynomial P1,Polynomial P2){
  //方法
  int c,e;
  Polynomial t1,t2,p,Rear,t;
  t1=P1;t2=P2;
  if(!P1||!P2) return NULL;
  p=(Polynomial)malloc(sizeof(struct PolyNode));
  p->link=NULL;
  Rear = p;
  while(t2){
    Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
    t2=t2->link;
  }
  t1=t1->link;
  while(t1){
    //t1=t1->link;
    t2=P2;
    Rear = p;
    while(t2){
      c=t1->coef*t2->coef;
      e=t1->expon+t2->expon;
      while(Rear->link&&Rear->link->expon>e){
        Rear=Rear->link;
      }
      if(Rear->link->expon==e&&Rear->link){//判断Rear->link不指向空！
        if(Rear->link->coef+c){
          Rear->link->coef+=c;
          //Rear = Rear->link;为什么不需要这一句，是因为必须使Rear指向前一个吗
        }else{
          t=Rear->link;
          Rear->link = t->link;
          free(t);
        }
      }else{
          t = (Polynomial)malloc(sizeof(struct PolyNode));
          t->coef=c;t->expon=e;
          t->link = Rear->link;
          Rear->link=t;
          Rear=Rear->link;
      }
      t2=t2->link;
    }
    t1=t1->link;
  }
  
  t2= p;p=p->link;free(t2);
  return p;
}
Polynomial Add(Polynomial P1,Polynomial P2){
  Polynomial p,Rear,t1,t2,t,s;
  int c,e;
  p = (Polynomial)malloc(sizeof(struct PolyNode));
  p->link=NULL;
  Rear=p;
  t1=P1;t2=P2;
  while(t1&&t2){
    t = (Polynomial)malloc(sizeof(struct PolyNode));
    t->link=NULL;
    if(t1->expon==t2->expon){
      t->coef=t1->coef+t2->coef;
      t->expon=t1->expon;
      t1=t1->link;t2=t2->link;
    }else if(t1->expon>t2->expon){
      t->coef=t1->coef;
      t->expon=t1->expon;
      t1=t1->link;
    }else{
      t->coef=t2->coef;
      t->expon=t2->expon;
      t2=t2->link;
    }
    Rear->link=t;
    Rear=t;
  }
  if(t1){
    Rear->link=t1;
  }
  if(t2){
    Rear->link=t2;
  }
  s=p;p=p->link;free(s);
  return p;
}
void PrintPoly(Polynomial P){
  int flag=0;
  if(!P){
    printf("0 0\n");
    return;
  }
  while(P){
    if(!flag){
      flag=1;
    }else{
      printf(" ");
    }
    printf("%d %d",P->coef,P->expon);
    P=P->link;
  }
  printf("\n");
}
