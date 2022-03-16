#include <stdio.h>
#include <malloc.h>
/*一元多项式的乘法和加法运算
 * 1.存储结构：链表
 * 2.函数：读取、乘法、加法、打印、链接
 * 3.声明单链表时为什么一定要有头节点？
 *  这是因为要使链表插入或删除在头部位置与其他位置的操作保持一致
*/
//结构体
typedef struct PolyNode *Polynomial;
typedef struct PolyNode{
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
    Attach(p->coef,p->expon,&rear);
  }
  t=p;p=p->next;free(t);
  return p;
}
/*
 * 链接：
 * 参数：coef,expon,next
 * 不需要有返回值
*/
void Attach(int c,int e,Polynomial* pRear){
  Polynomial p;
  p = (Polynomial)malloc(sizeof(struct PolyNode));
  p->next=NULL;
  p->coef=c;
  p->expon=e;
  (*pRear)->next=p;
  *pRear=p;
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
  int c,e;
  while(t2){
    //t1的第一项与t2逐一的相乘，然后链接成表
    Attach(t1->coef*t2->coef,t1->expon+t2->expon,&rear);
    t2=t2->next;
  }
  t1=t1->next;
  while(t2){
    t2=P2;
    rear = p;//每循环一次都要从头找插入的位置,但是要始终让rear处于被扫描节点的前一个
    //t1的下一项与t2逐一的相乘
    while(t2){
      //寻找t1×t2的项在表中插入的位置
      c=t1->coef*t2->coef;
      e=t1->expon+t2->expon;
      //如果扫描到的全都大于e,就一直往下扫描
      while(rear->next->expon>e&&rear->next){
        rear=rear->next;//最后一次循环中，rear->next->expon是<=e的
      }
      //如果扫描到的等于e
      if(rear->next&&rear->next->expon==e){
        if(rear->next->coef+c){//如果系数相加不为0
          rear->next->coef+=c;
        }else{//相加为0,去掉这个节点
          t=rear->next;
          rear->next=t->next;
          free(t);
        }
      }else{//小于e，插入到rear->next的前面，也就是rear的后面
        t=(Polynomial)malloc(sizeof(struct PolyNode));
        t->coef=c;t->expon=e;
        t->next=rear->next;
        rear->next=t;
        rear=rear->next;
      }
      t2=t2->next;
    }
    t1=t1->next;
  }
  t=p;p=p->next;free(t);
  return p;
}
/*
 * 相加
 * 加法运算和乘法不一样，乘法是两个链表每一项都要相互做乘法，
 * 加法是寻找两个链表中最大的一项加入到新链表中
 * 类似排序
*/
Polynomial Add(Polynomial P1,Polynomial P2){
  Polynomial p,rear,t1,t2,t;
  p=(Polynomial)malloc(sizeof(struct PolyNode));
  p->next=NULL;
  rear=p;
  int c,e;
  t1=P1;t2=P2;
  while(t1&&t2){
    if(t1->expon==t2->expon){
      c=t1->coef+t2->coef;
      e=t1->expon;
      //Attach(c,e,*rear);
      t1=t1->next;t2=t2->next;
    }else if(t1->expon>t2->expon){
      c=t1->coef;
      e=t1->expon;
      t1=t1->next;
    }else{
      c=t2->coef;
      e=t2->expon;
      t2=t2->next;
    }
    if(c){
      Attach(c,e,&rear);
    }   
  }
  if(t1){
    rear->next=t1;
  }
  if(t2){
    rear->next=t2;
  }
  t=p;p=p->next;free(t);
  return p;
}
/*
 * 打印
 * 打印格式：
 * 两个相邻字符中间有空格:每一个字符（第一个除外）前面有一个空格
 * 如果链表为空则打印0 0
*/
void PrintPoly(Polynomial P){
  if(!P){
    printf("0 0\n");
    return;
  }
  int flag=0;//
  while(P){
    if(!flag){
      flag=1;
    }else{
      printf(" ");
    }
    printf("%d %d",P->coef,P->expon);
    P=P->next;//遍历
  }
  printf("\n");
}
