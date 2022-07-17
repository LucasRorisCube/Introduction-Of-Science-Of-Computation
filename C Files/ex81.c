#include <stdio.h>
int main(void) {
  int n;
  scanf("%d",&n);
  int m;
  scanf("%d",&m);
  int vetor[n][m];

  for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
      scanf("%d",&vetor[i][j]);
    }
  }

  for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
      printf("%d ",vetor[i][j]);
    }
    printf("\n");
  }
}
