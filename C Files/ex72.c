#include <stdio.h>

int main(void) {
  int n;
  scanf("%d",&n);
  int num[n-1];
  for(int i = 0;i<n;i++){
    scanf("%d",&num[i]);
  }
  for(int i = n-1;i>=0;i--){
    printf("%d ",num[i]);;
  }
}
