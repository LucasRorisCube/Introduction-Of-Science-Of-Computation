#include <stdio.h>

int main(void) {
int x,y;
scanf("%d",&x);
int m1=-1000000000;
int m2=-1000000000;
int i;
for(i=0;i<x;i++){
  scanf("%d",&y);
  if(y>=m1){
    m2 = m1;
    m1 = y;
  }
  else{
    if (y>m2) m2 = y;
  }
}
if(m2 == -1000000000) m2 = m1;
printf("%d\n",m1);
printf("%d",m2);
}