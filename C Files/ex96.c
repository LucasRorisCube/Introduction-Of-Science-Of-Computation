#include <stdio.h>
#include<math.h>
int main(void) {
  char bin[100];
  fgets(bin,100,stdin);
  int i = 0;
  while(bin[i++] != '\n');
  i--;
  int res = 0;
  int j = 0;
  while(i>=0){
    if(bin[j++] == '1'){
      res += pow(2,i-1);
    }
    i--;
  }
  printf("%d",res);
}