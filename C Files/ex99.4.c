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

  int res = 1;
  for(int i = 0;str[i]!='\n' && ana[i]!='\n';i++){
    if(str[i]!=' ' || ana[i]!=' '){
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