int AuxPontuacao(peca **Tabuleiro,int x,int auxX,int y,int auxY,int *Ptemp);
void Pontuacao(peca **Tabuleiro,int x, int y,int *Ptemp);
void TrocarPeca(dados *Jogador,int r,peca **PecasRestantes,int *qPecasRestantes);
void SortearPecas(dados *Jogador,int r,peca **PecasRestantes,int *qPecasRestantes);
void PrintPecasRestantes(peca **PecasRestantes);
void InicializarPecasRestantes(peca **PecasRestantes);
peca **Jogada(dados *Jogador,int r,peca **Tabuleiro,int *tam,int Largura[2],int Altura[2],int cheat,int possibilidades[4],int *Ptemp);