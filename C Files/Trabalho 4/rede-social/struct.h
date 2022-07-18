#define TAMNOME 40

typedef struct{
  char nick[TAMNOME];
  char nome[TAMNOME];
  int NPosts;
  int NSeguindo;
  char **Seguindo;
  int NSeguidores;
  char **Seguidores;
}dados;

typedef struct{
  char nick[TAMNOME];
  char Post[130];
}dadosPosts;

