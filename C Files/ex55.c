#include <stdio.h>
#include <string.h>
int main(void) {
int a,b,c;
char res[20];
scanf("%d",&a);
scanf("%d",&b);
scanf("%d",&c);
if(a+b<c || a+c<b || b+c<a) strcpy(res,"INVALIDO");
else{
if(a==b && b==c) strcpy(res,"EQUILATERO");
else{
  if(a==b || a==c || b==c) strcpy(res,"ISOSCELES");
  else strcpy(res,"ESCALENO");
}
}
printf("%s\n",res);
}
