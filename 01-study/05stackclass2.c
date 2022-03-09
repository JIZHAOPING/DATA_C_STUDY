//堆栈链表操作

//定义
typedef struct SNode *PtrToSNode;
typedef struct SNode{
  ElementType Data;
  PtrToSNode Next;
}
typedef PtrToSNode Stack;

//创建一个栈（初始化
Stack CreateStack(){
  Stack S;
  S = (Stack)malloc(sizeof(struct SNode));//？？类型为啥不用SNode
  S->Next=NULL;
  return S;
}

//判空
bool isEmpty(Stack S){
  return (S->Next == NULL);
}
//判满：没有。链表没有满的时候

//push
bool Push(Stack S,ElementType X){
  PtrToSNode TmpCell;

  TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
  TmpCell->Data = X;
  TmpCell->Next = S->Next;
  S-Next = TmpCell;
  return true;
}
//pop
ElementType Pop(){
  PtrToSNode FirstCell;
  ElementType TopElem;

  if(isEmpty(S)){
    printf("堆栈为空");
    return ERROR;
  }else{
    FirstCell = S->Next;
    TopElem = FirstCell->Data;
    S->Next = FirstCell->Next;
    free(FirstCell);
    return TopElem;
  }
}

