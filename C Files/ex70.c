#include <stdio.h>

int main(void) {
  int n;
  scanf("%d",&n);
  int num[n];
  for(int i = 0;i<n;i++){
    scanf("%d",&num[i]);
  }
  int x;
  scanf("%d",&x);
  int pos = -1;
  for(int j = 0;j<n;j++){
    if(num[j] == x){
      pos = j;
      j = n;
    }
  }
  printf("%d",pos);
}
