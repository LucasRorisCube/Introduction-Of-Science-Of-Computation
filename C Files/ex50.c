#include <stdio.h>

int main(void) {
float L,A,C,M,preco;
scanf("%f",&L);
scanf("%f",&A);
scanf("%f",&C);
scanf("%f",&M);
float area = L*A;
float QL = area/M;
if (QL == (int)QL) QL = (int)QL;
else QL = (int)(QL+1);
preco = QL*C;
printf("%.0f\n",QL);
printf("%.2f\n",preco);
}
