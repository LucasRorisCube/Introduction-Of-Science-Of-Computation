#include <stdio.h>
#include<math.h>
int main(void) {
  int n;
  scanf("%d",&n);
  int v1[n];
  for(int i = 0;i<n;i++){
    scanf("%d",&v1[i]);
  }
  int m;
  scanf("%d",&m);
  int v2[m];
  for(int i = 0;i<m;i++){
    scanf("%d",&v2[i]);
  }
  int vr[n+m];
  int j = 0;
  int k = 0;
  int flag1 = 0;
  int flag2 = 0;

  for(int i = 0;i<n+m;i++){
    if((v1[j]<=v2[k] || flag2 == 1) && flag1 == 0){
      vr[i] = v1[j];
      j++;
      if(j == n){
        flag1 = 1;
      }
    } else {
        vr[i] = v2[k];
        k++;
        if(k == m){
          flag2 = 1;
        }   
    }
  }
  for(int i = 0;i<(n+m);i++){
    printf("%d ",vr[i]);
  }
  if(n == 0 && m == 0){
    printf(" ");
  }
}