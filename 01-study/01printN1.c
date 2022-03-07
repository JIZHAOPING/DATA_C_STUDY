#include <stdio.h>
void printN(int n);
int main(){
  int n;
  scanf("%d",&n);
  printN(n);
  return 0;
}
void printN(int n){
  int i;
  for(i=0;i<n;i++){
    printf("%d\n",n-i);
  }
}
