#include <stdio.h>

int main(void) {
  int n = 0;
  scanf("%d",&n);
  int num[n-1];
  int maior=-1000000;
  int pos = 0;
  for(int i = 0;i<n;i++){
    scanf("%d",&num[i]);
    if(num[i]>maior){
      maior=num[i];
      pos = i;
    }
  }
  printf("%d\n",maior);
  printf("%d\n",pos);
}
