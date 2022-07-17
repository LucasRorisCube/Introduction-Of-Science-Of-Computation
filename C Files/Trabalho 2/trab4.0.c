#include <stdio.h>
int main(void) {
  int n;
  scanf("%d",&n);
  long int p[n][n];
  for(int i = 0;i<n;i++){
    for(int j = 0;j<=i;j++){
      if(j == 0 || j == i){
        p[i][j] = 1;
      } else {
        p[i][j] = p[i-1][j-1] + p[i-1][j];
      }
      printf("%ld ",p[i][j]);
    }
    printf("\n");
  }
  if(n==0){
    printf("0");
  }
}