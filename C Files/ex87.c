#include <stdio.h>
int main(void) {
  int n;
  scanf("%d",&n);
  int vetorA[n];
  for(int i = 0;i<n;i++){
    scanf("%d",&vetorA[i]);
  }
  int m;
  scanf("%d",&m);
  int vetorB[m];
  for(int i = 0;i<m;i++){
    scanf("%d",&vetorB[i]);
  }
  int vetorR[n+m];
  int flag = 0;
  int j = 0;
  int k = 0;
  for(int i = 0;i<n+m;i++){
    if(n>=m){

      if(flag == 0){  
        vetorR[i] = vetorA[j];
        j++;
      }
      if(flag == 1){
        vetorR[i] = vetorB[k];
        k++;
      }
      if(flag == 0 && (k<m && j<=n)){
        flag = 1;
      } else {
        flag = 0;
      }

    } else {

      if(flag == 0){  
        vetorR[i] = vetorB[j];
        j++;
      }
      if(flag == 1){
        vetorR[i] = vetorA[k];
        k++;
      }
      if(flag == 0 && (k<=m && j<=n)){
        flag = 1;
      } else {
        flag = 0;
      }
    }

  }
  for(int i = 0;i<n+m;i++){
    printf("%d ",vetorR[i]);
  }
}