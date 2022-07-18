#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char nome[40];
  char nick[40];
  int NPosts;
  char *Posts[10];
  int NSeguindo;
  char *Seguindo[20];
  int NSeguidores;
  char *Seguidores[20];
}dados;



int Nelementos(FILE *file){
  int c = ftell(file);
  fseek(file,0,SEEK_END);
  int n = ftell(file);
  int Ncoisas = n/(sizeof(char)*40);
  fseek(file,c,SEEK_SET);
  return Ncoisas;
}

char* NickParaArquivo(char *nick){
  char *nickaux = nick;
  int i = 0;
  while(nickaux[i++] != '\0');
  nickaux[i-2] = '.';
  nickaux[i-1] = 't';
  nickaux[i] = 'x';
  nickaux[i+1] = 't';
  nickaux[i+2] = '\0';
  return nickaux;
}

void CadastroInicial(char *nick){
  char *ArquivoNick = NickParaArquivo(nick);
  FILE *file = fopen(ArquivoNick,"a+");
  dados usuario;
  printf("Digite seu nome: ");
  setbuf(stdin,NULL);
  fgets(usuario.nome,40,stdin);
  strcpy(usuario.nick,nick);
  fwrite(&usuario,sizeof(dados),1,file);
}

void ConsultarUsuarios(FILE *usuarios){
  fseek(usuarios,0,SEEK_SET);
  for(int i = 0;i<Nelementos(usuarios);i++){
    char teste[40];
    fread(teste,sizeof(char)*40,1,usuarios);
    printf("Nome: %s",teste);
  }
}

void ConsultarUsuario(char *nick){
  printf("entrei\n");
  char *ArquivoNick = NickParaArquivo(nick);
  FILE *file = fopen(ArquivoNick,"a+");
  fseek(file,0,SEEK_SET);
  dados usuario;
  fread(&usuario,sizeof(dados),1,file);
  printf("%s",usuario.nome);
}

int VerificarExistencia(FILE *file,char *nome){
  char teste[40];
  int c = ftell(file);
  fseek(file,0,SEEK_SET);
  for(int i = 0;i<Nelementos(file);i++){   
    fread(teste,sizeof(char)*40,1,file);
    if(strcmp(teste,nome) == 0){
      fseek(file,c,SEEK_SET);
      return 1;
    }
  }
  fseek(file,c,SEEK_SET);
  return 0;
}

void InserirUsuario(FILE *usuarios){
  char nome[40];
  printf("Escolha um nick para cadastrar: ");
  setbuf(stdin,NULL);
  fgets(nome,40,stdin);
  char teste[40];
  if(VerificarExistencia(usuarios,nome) == 0){
    fwrite(nome,sizeof(char)*40,1,usuarios);
    CadastroInicial(nome);
    printf("Usuario cadastrado com sucesso!\n");
  } else {
    printf("Já existe um usuario com esse nick!\n");
  }
}

void RemoverUsuario(FILE *usuarios){
  char nome[40];
  printf("Escolha um nick para remover: ");
  setbuf(stdin,NULL);
  fgets(nome,40,stdin);
  char nomesteste[10][40];
  char teste[40];
  int n = 0;
  if(VerificarExistencia(usuarios, nome) == 1){
    fseek(usuarios,0,SEEK_SET);
    for(int p = 0;p<Nelementos(usuarios);p++){  
      fread(teste,sizeof(char)*40,1,usuarios);
      if(strcmp(teste,nome) != 0){
        strcpy(nomesteste[n],teste);
        n++;
      }
    }
    fclose(usuarios);
    remove("usuarios.txt");
    usuarios = fopen("usuarios.txt","a+");
    fseek(usuarios,0,SEEK_SET);
    for(int i = 0;i<n;i++){
      fwrite(nomesteste[i],sizeof(char)*40,1,usuarios);
    }
    char *ArquivoNick = NickParaArquivo(nome);
    remove(ArquivoNick);
    printf("Usuario removido com sucesso!\n");
  } else {
    printf("Não existe esse usuario!\n");
  }
}

int main(void) {
  FILE *usuarios = fopen("usuarios.txt","a+");
  if(usuarios == NULL){
    printf("Erro no usuario.dat\n");
    exit(1);
  }
  int flag = 0;
  while(flag == 0){
    int Ncoisas = Nelementos(usuarios);
    fseek(usuarios,0,SEEK_SET);
    char Tnomes[Ncoisas][40];
    for(int i = 0;i<Ncoisas;i++){
      fread(Tnomes[i],sizeof(char)*40,1,usuarios);
    }
    int x;
    printf("Escolha um opcao: ");
    scanf("%d",&x);
    if(x == 1){
      InserirUsuario(usuarios);
    }
    if(x == 2){
      RemoverUsuario(usuarios);
    }
    if(x == 3){
      ConsultarUsuarios(usuarios);
    }
    if(x == 4){
      fclose(usuarios);
      flag = 1;
    }
    if(x == 5){
      setbuf(stdin, NULL);
      char nick[40];
      fgets(nick,40,stdin);
      ConsultarUsuario(nick);
    }
  }
}