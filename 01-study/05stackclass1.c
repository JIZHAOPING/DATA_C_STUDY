//堆栈基本操作

//定义
typedef int Position;
struct SNode{
  ElementType *Data;/*存储元素的数组*/
  Position Top;     /*栈顶指针*/
  int MaxSize;      /*堆栈最大容量*/
};
typedef struct SNode *Stack;

//创建一个空栈
Stack CreateStack(int Maxsize){
  Stack S = (Stack)malloc(sizeof(struct SNode));
  S->Data = (ElementType *)malloc(Maxsize * sizeof(ElementType));
  S->Top  = -1;
  S->MaxSize=Maxsize;
  return S;
}

//判满
bool isFull(Stack S){
  return (S->Top == S->MaxSize-1);
}

//判空
bool isEmpty(Stack S){
  return (S->Top==-1);
}

//push
bool Push(Stack S,ElementType X){
  if(isFull(s)){
    printf("堆栈满");
    return false;
  }else{
    S->Data[++(S->Top)]=X;
    return true;
  }
}
//pop
ElementType Pop(Stack S){
  if(isEmpty(S)){
    printf("堆栈为空！");
    return ERROR;
  }else{
    return (S->Data[(S->Top)--]);
  }
}
