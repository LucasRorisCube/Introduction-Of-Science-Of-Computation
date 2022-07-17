#include <stdio.h>
int main(void) {
  int n;
  scanf("%d",&n);
  int vetor[n];
  for(int i = 0;i<n;i++){
    scanf("%d",&vetor[i]);
  }
  int aux = 0;
  int aux2 = 0;
  if(n%2==1){
    aux2 = 1;
  }
  for(int j = 0;j<n-aux2;j+=2){
    aux = vetor[j];
    vetor[j] = vetor[j+1];
    vetor[j+1] = aux;
  }

  for(int i = 0;i<n;i++){
    printf("%d ",vetor[i]);
  }
}