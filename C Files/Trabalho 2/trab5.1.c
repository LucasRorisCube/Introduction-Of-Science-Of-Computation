#include <stdio.h>
int main(void) {
  char texto[100];
  int n;
  int r = 0;
  scanf("%d\n",&n);
  fgets(texto,100,stdin);
  for(r = 0;;r++){
    if(texto[r]=='\n'){
      break;
    }
  }
  char teste[n];
  int aux  = 0;
  int i=0;
  char maior[n];
  int nmaior = 0;
  while((i+aux) != (r-2)){
    for(i = 0;i<n;i++){
      teste[i]=texto[i+aux];
    }
    teste[i]='\0';
    int count = 0;
    int rep = 0;
    for(int j = 0;j<100;j++){
      for(int p = 0;p<n;p++){
        if(teste[p]==texto[p+j]){
          count++;
        }
      }
      if(count == n){
        rep++;
      }
      count = 0;
    }
    aux++;
    if(rep>nmaior){
      nmaior = rep;
      for(int m = 0;teste[m]!='\0';m++){
        maior[m] = teste[m];
      }
    }
  }
  int g = 0;
  while(g<n){
    printf("%c",maior[g++]);
  }
}