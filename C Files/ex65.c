#include <stdio.h>

int main(void) {
int n;
scanf("%d",&n);
int d[n];
int aux = 0;
int resf = 0;
for(int i = 0;i<n;i++){
  scanf("%d",&d[i]);
}

for(int j=0;j<n-1;j++){
  if(d[j]<=d[j+1]){
    aux++;
  }
  else aux=0;
  if(aux > resf){
    resf = aux;
  }
}
printf("%d",resf+1);
}