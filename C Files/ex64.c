#include <stdio.h>

int main(void) {
int n;
scanf("%d",&n);
  int soma = 0;
  for(int i = 1;i<n;i++){
    if(n%i==0){
      soma+=i;
    }
  }
  if (soma == n) printf("S");
  else printf("N");
}
