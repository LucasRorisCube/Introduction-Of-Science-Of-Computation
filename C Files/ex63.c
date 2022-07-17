#include <stdio.h>

int main(void) {
int n;
scanf("%d",&n);
long int f[n];
for(int i = 0;i<n;i++){
  if (i==0){
    f[i]=1;
  }
  else{
    if(i==1){
    f[i]=1;
    }
    else{
      f[i]=f[i-1]+f[i-2];
    }
  }
}
for(int i = 0;i<n;i++){
  printf("%ld ",f[i]);
}
}