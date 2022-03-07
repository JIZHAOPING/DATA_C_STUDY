#include <stdio.h>
//最大子列和：分治
int findMax(int *a,int low,int high,int *q,int *m);
int Compare(int a,int b,int c);

int main(){
  int i,k,n,AddSum;
  scanf("%d",&k);
  int a[k];
  for(i=0;i<k;i++){
    scanf("%d",&a[i]);
  }
  int low=0;
  int high=k-1;
  int *q=&low;
  int *m=&high;
  AddSum = findMax(a,low,high,q,m);
  if(AddSum<0){
    AddSum=0;
    *q=0;
    *m=k-1;
  }
  printf("%d %d %d\n",AddSum,a[*q],a[*m]);
  return 0;
}
int findMax(int *a,int low,int high,int *q,int *m){
  if(low==high) return a[low];
    
  int mid = (low+high)/2;
  int leftMaxSum=findMax(a,low,mid,q,m);
  int rightMaxSum=findMax(a,mid+1,high,q,m);
  int lmax=a[mid];
  int rmax = 0;
  int sum=0;

  int i,j;
  for(i = mid;i>=low;i--){
    sum+=a[i];
    if(lmax<=sum){//有等于号
      lmax=sum;
      *q=i;
    }
  }
  sum=0;
  for(j = mid+1;j<=high;j++){
    sum+=a[j];
    if(rmax<sum){
      rmax=sum;
      *m=j;
    }
  }  
  sum = lmax+rmax;
  if(leftMaxSum>=sum&&leftMaxSum>=rightMaxSum){
    *m=mid;
  }else if(rightMaxSum>sum&&rightMaxSum>=leftMaxSum){
    *q=mid+1;
  }

  return Compare(leftMaxSum,rightMaxSum,sum);
}
int Compare(int a,int b,int c){
  int max=0;
  max=a>b?a:b;
  max=max>c?max:c;
  return max;
}

