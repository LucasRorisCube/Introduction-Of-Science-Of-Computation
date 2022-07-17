#include <stdio.h>
int main(void) {
  char palavra[100];
  fgets(palavra,100,stdin);
  char c;
  c = getc(stdin);
  int o;
  for(int i = 0;palavra[i] != '\n';i++){
    if(palavra[i] == c){
      o++;
    }
  }
  printf("%d",o);
}
