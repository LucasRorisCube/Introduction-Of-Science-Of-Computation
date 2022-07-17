#include <stdio.h>

int main(void) {
int n = 0;
int res = 1;
scanf("%d",&n);
int i;
for(i=1;i<=n;i++){
  res = res * i;
}
printf("%d\n",res);
}

