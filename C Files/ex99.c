#include <stdio.h>

int main(void) {
  char str[100];
  fgets(str,100,stdin);
  int l1=0;
  while(str[++l1]!='\0'){
  }
  l1--;
  char ana[100];
  fgets(ana,100,stdin);
  int l2=0;
  while(str[++l2]!='\0'){
  }
  l2--;
  int igual = 0;
  if(l1 == l2){
    for(int i = 0;i<l1;i++){
      for(int j = 0;j<l2;j++){
        if(str[i] == '\n'){
          continue;
        }
        if(str[i] == ana[j]){
          igual++;
          str[i] = '0';
          break;
        }
      }
    }
  }
  if(igual == l1){
    printf("1");
  } else {
    printf("0");
  }
}