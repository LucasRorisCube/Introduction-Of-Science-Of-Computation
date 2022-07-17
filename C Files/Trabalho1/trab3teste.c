#include <stdio.h>

int main(void) {
  int n;
  scanf("%d",&n);
   int cont = 0;
  if(n>1){
    int pedras = 0;
    int auxc,auxl;
    int flag = 0;
    for(int c = 2;;c+=1){
      for(int l = 2;pedras < n;l+=1){
        pedras = 2*c*l-(c+l)+1; // determina a quantidade de pedregulhos
        if(l == 2 && n < pedras){ // tem a função de encerrar o programa
          flag = 1;
          break;
        }
        if(pedras == n){
          if((auxc == l && auxl == c)||auxc == auxl){ //tem a função de encerrar o programa
            flag = 1;
            break;
          }
          auxc = c;
          auxl = l;
          printf("%d %d\n",c,l); // correção do print
          cont++;
        }
      }
      if(flag){
        break;
      }
      pedras = 0;
    }
  } else {
    if(n == 1){
      printf("1 1\n");
      cont++;
    }
  }
  printf("%d\n",cont);
}
