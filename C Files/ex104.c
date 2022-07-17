#include <stdio.h>
#include<math.h>
struct ponto{
  double x;
  double y;
};

int main(void) {
  struct ponto p[2];
  for(int i = 0;i<2;i++){
    scanf("%lf",&p[i].x);
    scanf("%lf",&p[i].y);
  }

  double res = fabs(p[1].x - p[0].x) *fabs(p[1].y - p[0].y);
  printf("%.4lf",res);
}