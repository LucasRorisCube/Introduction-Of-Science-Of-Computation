#include <stdio.h>

int main(void) {
  char str[100];
  fgets(str,100,stdin);
  char ana[100];
  fgets(ana,100,stdin);

  for(int i = 0;ana[i]!='\n';i++){
    if(ana[i]!=' '){
      for(int j = 0;str[j]!='\n';j++){
        if(ana[i] == str[j]){
          str[j] = ' ';
          ana[i] = ' ';
          //printf("%s%s\npassou\n",str,ana);
          break;
        }
      }
    } 
  }
  int flag = 0;
  int flag2 = 0;
  int res = 1;
  for(int i = 0;str[i]!='\n' && ana[i]!='\n';i++){
    if(str[i]!='\n'){
      flag = 1;
    }
    if(ana[i]!='\n'){
      flag = 1;
    }
    if((str[i]!=' ' && flag == 0) || (ana[i]!=' ' && flag2 == 0)){
      //printf("%d,%d",str[i],ana[i]);
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