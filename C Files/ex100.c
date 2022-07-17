#include <stdio.h>

int main(void) {
  char str[500];
  fgets(str,500,stdin);
  printf("%s",str);
  for(int i = 0;str[i] != '\0';i++){
    switch(str[i]){
      case 'A':
        printf("T");
        break;
      case 'T':
        printf("A");
        break;
      case 'C':
        printf("G");
        break;
      case 'G':
        printf("C");
        break;
    }
  }
  if(str[0]=='\0' || str[0] == '\n'){
    printf(" ");
  }
}