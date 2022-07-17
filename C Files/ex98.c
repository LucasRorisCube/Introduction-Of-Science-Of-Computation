#include <stdio.h>

int main(void) {
  char str[100];
  fgets(str,100,stdin);
  int i=0;
  while(str[i]!='\0'){
    i++;
  }
  i--;
  int j = 0;
  int k = i;
  while(j<i/2){
    if(str[j]=='\n' || str[j]==' '){
      j++;
    }
    if(str[k]=='\n' || str[k]==' '){
      k--;
    }
    if(str[j] != str[k]){
      printf("0");
      return 0;
    }
    j++;
    k--;
  }
  printf("1");
}