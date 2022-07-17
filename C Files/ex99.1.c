#include <stdio.h>

int main(void) {
  char str[100];
  fgets(str,100,stdin);

  char ana[100];
  fgets(ana,100,stdin);

  int res = 1;
  for(int i = 0;ana[i]!='\n';i++){
    int flag = 0;
    if(ana[i]!=' '){
      for(int j = 0;str[j]!='\n';j++){
        if(str[j] != ' '){
          if(ana[i] == str[j]){
            str[j] = ' ';
            flag = 1;
            break;
          }
        } else {
          flag = 1;
        }
      }
    } else {
      continue;
    }
    if(flag == 0){
      res = 0;
      break;
    }
  }
  if(res){
    printf("1");
  } else {
    printf("0");
  }
}