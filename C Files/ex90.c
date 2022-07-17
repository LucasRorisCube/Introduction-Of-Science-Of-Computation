#include <stdio.h>
int main(void) {
  char palavra[100];
  fgets(palavra,100,stdin);
  int i;
  for(i = 0;palavra[i] != '\n';i++){
  }
  for(int j = i;j >=0;j--){
    if(palavra[j]!='\n'){
      printf("%c ",palavra[j]);
    }
  }
}
