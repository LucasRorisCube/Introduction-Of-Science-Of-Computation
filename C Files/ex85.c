#include <stdio.h>
int main(void) {
  int n;
  scanf("%d",&n);
  int vetor[n];
  for(int i = 0;i<n;i++){
    scanf("%d",&vetor[i]);
  }
  int p;
  scanf("%d",&p);

  if(p>=0 && p<n){
    int i;
    for(i = p;i!=n;i++){
      vetor[i] = vetor[i+1];
    }
    for(int j = 0;j<n-1;j++){
      printf("%d ",vetor[j]);
    }
  } else {
    printf("INVALIDO");
  }
  if(n==1 && p == 0){
    printf(" \n");
  }
}