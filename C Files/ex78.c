#include <stdio.h>
int main(void) {
  int n;
  scanf("%d",&n);
  int vetor[n];
  int menor = 100000;
  int maior = -10000;
  int pmenor = 0;
  int pmaior = 0;
  int i;

  for(i = 0;i<n;i++){
    scanf("%d",&vetor[i]);
    if(vetor[i]<menor){
      menor = vetor[i];
      pmenor = i;
    }
    if(vetor[i]>maior){
      maior = vetor[i];
      pmaior = i;
    }
  }

  int aux = vetor[0];
  vetor[0] = vetor[pmenor];
  vetor[pmenor] = aux;

  for(int i = 0;i<n;i++){
    if(vetor[i]==maior){
      pmaior = i;
      break;
    }
  }
  
  int aux2 = vetor[n-1];
  vetor[n-1] = vetor[pmaior];
  vetor[pmaior] = aux2;

  for(int k = 0;k<n;k++){
    printf("%d ",vetor[k]);
  }
}
