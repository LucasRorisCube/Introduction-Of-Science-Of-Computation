#include <stdio.h>
int main(void) {
  int n;
  scanf("%d",&n);
  int vetor[n];
  int vetor2[n];
  for(int i = 0;i<n;i++){
    scanf("%d",&vetor[i]);
  }

  int x;
  scanf("%d",&x);

  int u = 0;
  for(int j = 0;j<n;j++){
    if(vetor[j]>x){
      vetor2[u] = vetor[j];
      u++;
    }
  }
  if(u != 0){
    for(int k = 0;k<u;k++){
      printf("%d ",vetor2[k]);
    }
  } else {
    printf(" ");
  }
}
