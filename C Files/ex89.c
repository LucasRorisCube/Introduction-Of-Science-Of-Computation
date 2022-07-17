#include <stdio.h>
int main(void) {
  char palavra[100];
  fgets(palavra,100,stdin);
  for(int i = 0;palavra[i] != '\n';i++){
    printf("%c ",palavra[i]);
  }
}
