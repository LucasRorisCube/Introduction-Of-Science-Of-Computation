#include <stdio.h>
int main(void) {
  int n;
  scanf("%d",&n);
  int vetor[n];
  for(int i = 0;i<n;i++){
    scanf("%d",&vetor[i]);
  }
  int i,j;
  scanf("%d",&i);
  scanf("%d",&j);

  if(i>j){
    int aux = i;
    i = j;
    j = aux;
  }
  if(i>=0 && i<=n && j>=0 && j<=n){
    int soma = 0;
    for(int k = i;k<=j;k++){
      soma+=vetor[k];
    }
    printf("%d\n",soma);
  } else {
    printf("INVALIDO");
  }
}