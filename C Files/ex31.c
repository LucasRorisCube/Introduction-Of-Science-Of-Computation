#include <stdio.h>

int main(void) {
  int a = 0;
  int b = 0;
  int res = 0;
  scanf("%d",&a);
  scanf("%d",&b);
  if (a>b){
    res = a;
  }
  else{
    res = b;
  }
  printf("%d\n",res);
}