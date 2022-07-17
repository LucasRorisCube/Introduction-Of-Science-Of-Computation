#include <stdio.h>
int comparacao(char str1[100],char str2[100]){
  int flag = 1;
  for(int i = 0;str1[i]!='\0';i++){
    if(str1[i] != str2[i]){
      flag = 0;
      break;
    }
  }
  return flag;
}
int main(void) {
  int n;
  scanf("%d\n",&n);
  
  char senha[100];
  fgets(senha,100,stdin);
  int tam = 0;
  while(senha[tam++]!='\n');
  tam--;
  char possib[tam-(n+1)][n+1];
  int i;
  for(int j = 0;senha[j]!='\0';j++){
    for(i = 0;i<n;i++){
      possib[j][i] = senha[j+i];
    }
    possib[j][i] = '\0';
  }
  int maior = 0;
  int smaior = 0;
  int l = 0;
  for(l = 0;possib[l][0]!='\0';l++){
     int count = 0;
    for(int k = 0;possib[k][n-1]!='\0';k++){
      if(comparacao(possib[l],possib[k]) == 1){
        count++;
      }
    }
    if(count>maior){
      maior = count;
      smaior = l;
    }
  }
  printf("%s",possib[smaior]);
}