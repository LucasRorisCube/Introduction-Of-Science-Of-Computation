#include <stdio.h>
int main(void) {
  int n;
  scanf("%d",&n);
  int vetorA[n];
  int vetorB[n];

  for(int i = 0;i<n;i++){
    scanf("%d",&vetorA[i]);
  }
  for(int i = 0;i<n;i++){
    scanf("%d",&vetorB[i]);
  }
  int aux = 0;
  for(int i = 0;i<n;i++){
    if(aux == 0){
      printf("%d ",vetorA[i]);
      aux = 1;
      i--;
    } else {
      printf("%d ",vetorB[i]);
      aux = 0;
    }
  }
}
