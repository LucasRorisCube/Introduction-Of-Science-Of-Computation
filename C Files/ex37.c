#include <stdio.h>

int main(void) {
int n,m;
int res = 0;
scanf("%d",&n);
scanf("%d",&m);
if(n>m){
  while(m<=n){
    res = res + m;
    m++;
  }
}
else{
  while(n<=m){
    res = res + n;
    n++;
  }
}
printf("%d\n",res);
}