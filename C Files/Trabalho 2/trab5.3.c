#include <stdio.h>
int main(void) {
  int n;
  scanf("%d\n",&n);

  char teste[n],texto[100],maior[n];
  fgets(texto,100,stdin);

  int aux = 0,i = 0,nmaior = 0;

  while(texto[i+aux]!='\n'){
    for(i = 0;i<n;i++){     //set do comparador
      teste[i]=texto[i+aux];
    }
    teste[i]='\0';
    int count = 0;
    int rep = 0;

    for(int j = 0;j<100;j++){ //percorrer a sting toda
      for(int p = 0;p<n;p++){ //comparador
        if(teste[p]==texto[p+j]){ // conta de 1 em 1 até n digitos
          count++;
        }
      }
      if(count == n){   //se as letras contadas forem todas iguais reulta em uma repetição
        rep++;
      }
      count = 0;
    }
    aux++;
    if(rep>nmaior){     //compara qual a expressão com maior repetições
      nmaior = rep;
      for(int m = 0;teste[m]!='\0';m++){   //set a resposta por ora
        maior[m] = teste[m];
      }
    }
  }
  int g = 0;
  while(g<n){ //print da resposta
    printf("%c",maior[g++]);
  }
}