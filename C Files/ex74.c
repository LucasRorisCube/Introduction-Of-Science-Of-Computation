#include <stdio.h>
int main(void) {
  int n;
  scanf("%d",&n);
  int vetor[n];
  int vetor2[n];
  for(int i = 0;i<n;i++){
    scanf("%d",&vetor[i]);
  }
  for(int i = 0;i<n;i++){
    scanf("%d",&vetor2[i]);
  }

  for(int i = 0;i<n;i++){
    printf("%d ",vetor[i]+vetor2[i]);
  }
}