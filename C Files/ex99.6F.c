#include <stdio.h>

int main(void) {
  char str[100];
  fgets(str,100,stdin);
  char ana[100];
  fgets(ana,100,stdin);
  
  for(int i = 0;ana[i]!='\0';i++){
    if(ana[i]!=' ' && ana[i]!='\n'){
      for(int j = 0;str[j]!='\0';j++){
        if(ana[i] == str[j]){
          ana[i] = ' ';
          str[j] = ' ';
          break;
        }
      }
    }
  }
  int flag = 0;
  for(int i = 0;ana[i]!='\0';i++){
    if(ana[i]!=' ' && ana[i]!='\n'){
      flag++;
    }
  }
  for(int i = 0;str[i]!='\0';i++){
    if(str[i]!=' ' && str[i]!='\n'){
      flag++;
    }
  }
  if(flag == 0){
    printf("1");
  } else {
    printf("0");
  }
}