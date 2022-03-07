#include <stdio.h>
int main(){
  int i,j,k,n;
  int thisSum=0,MaxSum=0;
  scanf("%d",&k);
  int a[k];
  for(n=0;n<k;n++){
    scanf("%d",&a[n]);                                
  }
  for(i=0;i<k;i++){
    thisSum=0;
    for(j=i;j<k;j++){
      thisSum+=a[j];
      if(thisSum>MaxSum){
        MaxSum=thisSum;                                                
    }
  }
  printf("%d\n",MaxSum);
  return 0;
}
