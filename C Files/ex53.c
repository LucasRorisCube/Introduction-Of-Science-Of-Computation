#include <stdio.h>
int main(void) {
int n,i,x;
int m = -10000000;
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d",&x);
if(x>m){
  m = x;
}
}
printf("%d\n",m);
}
