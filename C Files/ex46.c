#include <stdio.h>
int mult(int n,int m){
  int soma = 0;
  int i;
  for(i=0;i<m;i++){
    soma = soma + n;
}
return(soma);
}

int main(void) {
int n,m,i = 0;
scanf("%d",&n);
scanf("%d",&m);
int res = 1;
for(i=0;i<m;i++){
  res = mult(res,n);
}
printf("%d\n",res);
}