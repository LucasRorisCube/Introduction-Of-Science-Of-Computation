#include <stdio.h>
int main(void) {
  int n;
  scanf("%d",&n);
  int vetor[n+1];
  for(int i = 0;i<n;i++){
    scanf("%d",&vetor[i]);
  }
  int p,x;
  scanf("%d",&p);
  scanf("%d",&x);
  if(p>=0){
    if(p>n){
      p = n;
    }
    int i;
    for(i = n;i!=p;i--){
      vetor[i] = vetor[i-1];
    }
    vetor[i] = x;
    for(int j = 0;j<n+1;j++){
      printf("%d ",vetor[j]);
    }
  } else {
    printf("INVALIDO");
  }
}