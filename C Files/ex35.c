#include <stdio.h>

int main(void) {
int a,res;
scanf("%d",&a);
if (a>0){
  if(((a%4 == 0)&&(a%100 != 0))||(a%400 == 0)){
    res = 1;
  }
  else{
    res = 0;
  }
}
else res = -1;
printf("%d",res);
}