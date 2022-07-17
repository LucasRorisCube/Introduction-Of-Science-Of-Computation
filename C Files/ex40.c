#include <stdio.h>

int main(void) {
int n = 0;
int res = 0;
scanf("%d",&n);
int i = 1;
int div = 0;
while (i<=n){
  if(n%i==0){
    div++;
  }
  i++;
}
if(div == 2) res = 1;
else res = 0;

printf("%d\n",res);
}