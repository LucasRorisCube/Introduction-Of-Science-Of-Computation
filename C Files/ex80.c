#include <stdio.h>
int main(void) {
  int n;
  scanf("%d",&n);
  int vetor[n];

  for(int i = 0;i<n;i++){
    scanf("%d",&vetor[i]);
  }

  for(int i = 0;i<n/2;i++){
    int aux = vetor[i];
    vetor[i] = vetor[n-1-i];
    vetor[n-1-i] = aux;
  }

  for(int i = 0;i<n;i++){
    printf("%d ",vetor[i]);
  }
}
