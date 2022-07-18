//inserir funcao verificar existencia

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAMNOME 40

typedef struct{
  char nick[TAMNOME];
  char NomeArquivo[TAMNOME];
  FILE *Ausuario;
  char nome[TAMNOME];
  int NPosts;
  char **Posts;
  int NSeguindo;
  char **Seguindo;
  int NSeguidores;
  char **Seguidores;
}dados;

int NumUsuarios(FILE *Usuarios){
  int c = ftell(Usuarios);
  fseek(Usuarios,0,SEEK_END);
  int f = ftell(Usuarios);
  f = f/(sizeof(char)*40*2);
  fseek(Usuarios,c,SEEK_SET);
  return f;
}

void Inicializar(FILE *Usuarios,dados *usuario){
  for(int k = 0;k<NumUsuarios(Usuarios);k++){
    fread(usuario[k].nick,sizeof(char)*40,1,Usuarios);
    fread(usuario[k].NomeArquivo,sizeof(char)*40,1,Usuarios);

    usuario[k].Ausuario = fopen(usuario[k].NomeArquivo,"a+");
    setbuf(stdin,NULL);
    fread(usuario[k].nome,sizeof(char)*40,1,usuario[k].Ausuario);




    ///ALOCACAO POSTS
    fread(&usuario[k].NPosts,sizeof(int),1,usuario[k].Ausuario);
    usuario[k].Posts = NULL;
    usuario[k].Posts = realloc(usuario[k].Posts,sizeof(char *)*5);
    if(usuario[k].Posts == NULL){
        printf("Erro de alocamento no Posts\n");
        exit(1);
      }

    for(int i = 0;i<usuario[k].NPosts;i++){
      usuario[k].Posts[i] = NULL;
      usuario[k].Posts[i] = realloc(usuario[k].Posts[i],sizeof(char)*130);
      if(usuario[k].Posts[i] == NULL){
        printf("Erro de alocamento no Posts**\n");
        exit(1);
      }
      fread(usuario[k].Posts[i],sizeof(char)*130,1,usuario[k].Ausuario);
    }




    ///ALOCACAO SEGUINDO
    fread(&usuario[k].NSeguindo,sizeof(int),1,usuario[k].Ausuario);
    usuario[k].Seguindo = NULL;
    usuario[k].Seguindo = realloc(usuario[k].Seguindo,sizeof(char *)*usuario[k].NSeguindo);
    if(usuario[k].Seguindo == NULL){
        printf("Erro de alocamento no Seguindo\n");
        exit(1);
      }

    for(int i = 0;i<usuario[k].NSeguindo;i++){
      usuario[k].Seguindo[i] = NULL;
      usuario[k].Seguindo[i] = realloc(usuario[k].Seguindo[i],sizeof(char)*40);
      if(usuario[k].Seguindo[i] == NULL){
        printf("Erro de alocamento no Seguindo**\n");
        exit(1);
      }
      fread(usuario[k].Seguindo[i],sizeof(char)*40,1,usuario[k].Ausuario);
    }




    ///ALOCACAO SEGUIDORES
    fread(&usuario[k].NSeguidores,sizeof(int),1,usuario[k].Ausuario);
    usuario[k].Seguidores = NULL;
    usuario[k].Seguidores = realloc(usuario[k].Seguidores,sizeof(char *)*usuario[k].NSeguidores);
    if(usuario[k].Seguidores == NULL){
        printf("Erro de alocamento no Seguidores\n");
        exit(1);
      }

    for(int i = 0;i<usuario[k].NSeguidores;i++){
      usuario[k].Seguidores[i] = NULL;
      usuario[k].Seguidores[i] = realloc(usuario[k].Seguidores[i],sizeof(char)*40);
      if(usuario[k].Seguidores[i] == NULL){
        printf("Erro de alocamento no Seguidores**\n");
        exit(1);
      }
      fread(usuario[k].Seguidores[i],sizeof(char)*40,1,usuario[k].Ausuario);
    }
  }
  ///
}

dados Cadastro(FILE *Usuarios){
  int n = NumUsuarios(Usuarios);
  dados usuario;
  printf("Escreve o seu nick: ");
  setbuf(stdin,NULL);
  fgets(usuario.nick,40,stdin);
  printf("Escreve o seu nome: ");
  setbuf(stdin,NULL);
  fgets(usuario.nome,40,stdin);
  strcpy(usuario.NomeArquivo,usuario.nick);
  int r = 0;
  while(usuario.NomeArquivo[r++] != '\0');
  usuario.NomeArquivo[r-2] = '.';
  usuario.NomeArquivo[r-1] = 't';
  usuario.NomeArquivo[r] = 'x';
  usuario.NomeArquivo[r+1] = 't';
  usuario.NomeArquivo[r+2] = '\0';
  usuario.Ausuario = fopen(usuario.NomeArquivo,"a+");
  usuario.NPosts = 0;
  usuario.NSeguindo = 0;
  usuario.NSeguidores = 0;
  return usuario;
}

void RemoverUsuario(FILE *Usuarios,dados *usuario,int NumeroUsu){
  printf("Digite o nick do usuario que deseja deletar: ");
  setbuf(stdin,NULL);
  char remover[40];
  fgets(remover,40,stdin);
  int r = 0;
  while(strcmp(remover,usuario[r++].nick) != 0);
  printf("Removi %s",usuario[r].nick);
  for(int i = r-1;i<NumeroUsu;i++){
    printf("coloquei %s no %s\n",usuario[i+1].nick,usuario[i].nick);
    usuario[i] = usuario[i+1];
  }
  remove(usuario[r].NomeArquivo);
}

void Salvar(dados *usuario,FILE *Usuarios,int NumeroUsu){
  for(int i = 0;i<NumeroUsu;i++){
    remove(usuario[i].NomeArquivo);
    usuario[i].Ausuario = fopen(usuario[i].NomeArquivo,"a+");
    printf("ok");
    fwrite(usuario[i].nome,sizeof(char)*40,1,usuario[i].Ausuario);
    printf("%s", usuario[i].nome);
    
    fwrite(&usuario[i].NPosts,sizeof(int),1,usuario[i].Ausuario);
    for(int j = 0;j<usuario[i].NPosts;j++){
      fwrite(usuario[i].Posts[j],sizeof(char)*130,1,usuario[i].Ausuario);
    }
    fwrite(&usuario[i].NSeguindo,sizeof(int),1,usuario[i].Ausuario);
    for(int j = 0;j<usuario[i].NSeguindo;j++){
      fwrite(usuario[i].Seguindo[j],sizeof(char)*40,1,usuario[i].Ausuario);
    }
    fwrite(&usuario[i].NSeguidores,sizeof(int),1,usuario[i].Ausuario);
    for(int j = 0;j<usuario[i].NSeguidores;j++){
      fwrite(usuario[i].Seguidores[j],sizeof(char)*40,1,usuario[i].Ausuario);
    }
    fclose(usuario[i].Ausuario);
    usuario[i].Ausuario = fopen(usuario[i].NomeArquivo, "a+");
  }
  remove("usuarios.txt");
  Usuarios = fopen("usuarios.txt","a+");
  for(int i = 0;i<NumeroUsu;i++){
    fwrite(usuario[i].nick,sizeof(char)*40,1,Usuarios);
    printf("%s", usuario[i].nick);
    fwrite(usuario[i].NomeArquivo,sizeof(char)*40,1,Usuarios);
  }
  fclose(Usuarios);
  Usuarios = fopen("usuarios.txt","a+");
}

void Terminar(FILE *Usuarios, dados *usuario, int NumeroUsu){
  fclose(Usuarios);
  for(int i = 0;i<NumeroUsu;i++){
    for(int j = 0;j<usuario[i].NPosts;j++){
      free(usuario[i].Posts[j]);
    }
    if(usuario[i].NPosts > 0){
      free(usuario[i].Posts);
    }
    for(int j = 0;j<usuario[i].NSeguindo;j++){
      free(usuario[i].Seguindo[j]);
    }
    if(usuario[i].NSeguindo > 0){
      free(usuario[i].Seguindo);
    }
    for(int j = 0;j<usuario[i].NSeguidores;j++){
      free(usuario[i].Seguidores[j]);
    }
    if(usuario[i].NSeguidores > 0){
      free(usuario[i].Seguidores);
    }
    fclose(usuario[i].Ausuario);
  }
  free(usuario);

}

void ConsultarUsuario(dados *usuario){
  printf("Digite o nick do usuario que deseja consultar: ");
  setbuf(stdin,NULL);
  char consultar[40];
  fgets(consultar,40,stdin);
  int r = 0;
  while(strcmp(consultar,usuario[r++].nick) != 0);
  r--;
  printf("%s",usuario[r].nome);
  printf("%d\n",usuario[r].NPosts);
  for(int i = 0;i<usuario[r].NPosts;i++){
    printf("%s",usuario[r].Posts[i]);
  }
  printf("%d\n",usuario[r].NSeguindo);
  for(int i = 0;i<usuario[r].NSeguindo;i++){
    printf("%s",usuario[r].Seguindo[i]);
  }
  printf("%d\n",usuario[r].NSeguidores);
  for(int i = 0;i<usuario[r].NSeguidores;i++){
    printf("%s",usuario[r].Seguidores[i]);
  }
}

void AdicionarPost(dados *usuario,int r){
  usuario[r].Posts = realloc(usuario[r].Posts, sizeof(char*)*(usuario[r].NPosts + 1));

  usuario[r].Posts[usuario[r].NPosts] = realloc(usuario[r].Posts[usuario[r].NPosts],sizeof(char)*130);

  setbuf(stdin,NULL);
  fgets(usuario[r].Posts[usuario[r].NPosts],130,stdin);
  usuario[r].NPosts++;
}

int main(void) {
  FILE *Usuarios = fopen("usuarios.txt","a+");
  dados *usuario;
  usuario = (dados*)malloc(sizeof(dados)*10);
  if(usuario == NULL){
    printf("Erro no alocamento\n");
    exit(1);
  }
  fseek(Usuarios,0,SEEK_SET);
  printf("Numero de Usuarios: %d\n",NumUsuarios(Usuarios));
  
  Inicializar(Usuarios,usuario);
  
  int NumeroUsu = NumUsuarios(Usuarios);
  while(1){
    int x;
    printf("Escolha uma opÃ§Ã£o: ");
    scanf("%d",&x);
    fseek(Usuarios,0,SEEK_SET);
    if(x == 1){
      for(int i = 0;i<NumeroUsu;i++){
        printf("%s",usuario[i].nick);
        printf("%s\n",usuario[i].NomeArquivo);
      }
    }
    if(x == 2){
      usuario[NumeroUsu] = Cadastro(Usuarios);
      NumeroUsu = NumeroUsu + 1;
      Salvar(usuario,Usuarios,NumeroUsu);
    }
    if(x == 3){
      RemoverUsuario(Usuarios,usuario,NumeroUsu);
      NumeroUsu = NumeroUsu - 1;
      Salvar(usuario,Usuarios,NumeroUsu);
    }
    if(x == 4){
      Salvar(usuario,Usuarios,NumeroUsu);
      Terminar(Usuarios, usuario, NumeroUsu);
      break;
    }
    if(x == 5){
      ConsultarUsuario(usuario);
    }
    if(x == 6){
      printf("Digite o nick do login: ");
      setbuf(stdin,NULL);
      char login[40];
      fgets(login,40,stdin);
      int r = 0;
      while(strcmp(login,usuario[r++].nick) != 0);
      r--;
      printf("APERTA 1 CACETE: ");
      scanf("%d",&x);
      if(x == 1){
        AdicionarPost(usuario,r);
        Salvar(usuario,Usuarios,NumeroUsu);
      }
      
    }
    else if(x == 7){
      system("clear||cls");
      system("./main");
    }
  }
 

  //FINAL
}