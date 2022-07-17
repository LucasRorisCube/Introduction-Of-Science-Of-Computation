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
  for(int i = 0;i<n+m;i++){
    if(v1[j]<=v2[k]){
      if(j<n){
        vr[j+k] = v1[j];
        j++;
      } else {
        vr[j+k] = v2[k];
        k++;
      }
    } else {
      if(k<m){
        vr[j+k] = v2[k];
        k++;
      } else {
        vr[j+k] = v1[j];
        j++;
      }
    }
    
  }
  if(n == 0 && m==0){
    printf(" \n");
  }

  for(int i = 0;i<(n+m);i++){
    printf("%d ",vr[i]);
  }
}