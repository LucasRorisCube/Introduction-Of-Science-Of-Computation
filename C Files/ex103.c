#include <stdio.h>
#include<math.h>
struct ponto{
  float x;
  float y;
};

int main(void) {
  struct ponto p[2];
  for(int i = 0;i<2;i++){
    scanf("%f",&p[i].x);
    scanf("%f",&p[i].y);
  }
  float res = sqrt(pow(p[1].x - p[0].x,2) + pow(p[1].y - p[0].y,2));
  printf("%.4f",res);
}