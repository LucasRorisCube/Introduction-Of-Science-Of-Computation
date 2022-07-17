#include <stdio.h>
int main(void) {
  char palavra[100];
  fgets(palavra,100,stdin);
  int c;
  for(int i = 0;palavra[i] != '\n';i++){
    if(palavra[i]=='a' || palavra[i]=='e' || palavra[i]=='i' || palavra[i]=='o' || palavra[i]=='u' || palavra[i]==' '){
    } else {
      c++;
    }
  }
  printf("%d",c);
}
