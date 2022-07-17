#include <stdio.h>
int main(void) {
  int n;
  scanf("%d",&n);
  int x[n];
  for(int i = 0;i<n;i++){
    scanf("%d",&x[i]);
  }
  int res = 0;
  int aux = 0;
  for(int i = 0;i<n-1;i++){
    if(x[i] < x[i+1]){
      res = res + 1;
    }
    if(x[i] > x[i+1]){
      res = res - 1;
    }
    if(x[i] == x[i+1]){
      aux = aux + 1;
    }
  }
  
  if(res == n-1-aux) printf("1");
  else{
    if(res == -(n-1-aux)) printf("-1");
    else printf("0");
  }
}