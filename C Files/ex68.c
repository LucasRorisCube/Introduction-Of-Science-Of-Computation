#include <stdio.h>

int main(void) {
  int n = 0;
  scanf("%d",&n);
  int num[n];
  for(int i = 0;i<n;i++){
    scanf("%d",&num[i]);
  }
  for(int i = 0;i<n;i++){
    printf("%d ",num[i]);
  }
}
