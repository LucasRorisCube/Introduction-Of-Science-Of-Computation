#include <stdio.h>
struct dados{
  char nome[40];
  char sexo[10];
  char RA[20];
  char data[20];
  char curso[50];
};
void eliminaesp(char *s){
  while(*s++ != '\n' && *s != '\0');
  s--;
  *s = '\0';
}
int main(void) {
  struct dados aluno[200];
  int tam = 0;
  for(int i = 0;;i++){
    fgets(aluno[i].nome,20,stdin);
    if(aluno[i].nome[0] == 'F' && aluno[i].nome[1] == 'I' && aluno[i].nome[2] == 'M'){
      tam = i;
      break;
    }
    eliminaesp(aluno[i].nome);
    fgets(aluno[i].sexo,10,stdin);
    fgets(aluno[i].RA,10,stdin);
    eliminaesp(aluno[i].RA);
    fgets(aluno[i].data,12,stdin);
    eliminaesp(aluno[i].data);
    fgets(aluno[i].curso,50,stdin);
    eliminaesp(aluno[i].curso);
  }
  for(int i = 0;i<tam;i++){
    printf("Registro %d:\n",i+1);
    printf("Nome: %s - ",aluno[i].nome);
    if(aluno[i].sexo[0] == 'F'){
      printf("Sexo: Feminino - ");
    } else{
      printf("Sexo: Masculino - ");
    }
    printf("RA: %s\n",aluno[i].RA);
    printf("Ingresso: %s - Curso: %s\n",aluno[i].data,aluno[i].curso);
    printf("==========\n");
  }
}