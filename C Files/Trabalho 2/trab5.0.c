#include <stdio.h>
int main(void) {
  char texto[100];
  int n;
  scanf("%d\n",&n);
  fgets(texto,100,stdin);

  char teste[n];
  int aux  = 0;
  int i=0;
  char maior[n];
  int nmaior = 0;
  while(texto[i+aux]!='\n'){
    for(i = 0;i<n;i++){
      teste[i]=texto[i+aux];
    }
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
      for(int m = 0;m<n;m++){
        maior[m] = teste[m];
      }
    }
  }
  int g = 0;
  while(g<n){
    printf("%c",maior[g++]);
  }
}