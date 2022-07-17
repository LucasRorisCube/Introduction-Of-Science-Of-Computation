#include <stdio.h>

int main(void) {
int x;
int y = 0;
int res = 0;
scanf("%d",&x);
scanf("%d",&y);
while(y>=0){
if (y == x){
res = res + 1;
}
scanf("%d",&y);
}
printf("%d\n",res);
}
