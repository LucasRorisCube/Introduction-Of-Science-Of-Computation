#include <stdio.h>
int main(void) {
  int n;
  scanf("%d",&n);
  int vetor[n];
  for(int i = 0;i<n;i++){
    scanf("%d",&vetor[i]);
  }

  int c;
  scanf("%d",&c);
  int j = 0;
  int aux = 0;
  for(int i = 0;i<n;i++){
    if(vetor[i]==c){
      aux++;
    } else {
      vetor[j] = vetor[i];
      j++;
    }
  }
  for(int i = 0;i<=j-1;i++){
    printf("%d ",vetor[i]);
  }
  if(aux == n){
    printf(" \n");
  }
}