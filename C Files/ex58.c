#include <stdio.h>
#include <string.h>
int main(void) {
float x1,v1,x2,v2 = 0;
char res[4];
scanf("%f",&x1);
scanf("%f",&v1);
scanf("%f",&x2);
scanf("%f",&v2);
float tempo = 0;

if (v2-v1 == 0){
  if(x1 == x2) strcpy(res,"SIM");
  else strcpy(res,"NAO");
}
else{
  tempo = (x1-x2)/(v2-v1);
  if(tempo<=0) strcpy(res,"NAO");
  else{
    if(tempo == (int)tempo) strcpy(res,"SIM");
    else strcpy(res,"NAO");
  }
}
//printf("%d\n",x1);
//printf("%d\n",v1);
//printf("%d\n",x2);
//printf("%d\n",v2);
//printf("%f\n",tempo);
printf("%s\n",res);
}