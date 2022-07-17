#include <stdio.h>

int main(void) {
int n = 0;
float i = 0;
double res = 0;
scanf("%d",&n);
for(i = 1;i<=n;i++){
res = res + 1.0/i;
}
printf("%.4f",res);
}