#include <stdio.h>
#include <string.h>

int main(void) {
  int i;
  char res[20] = {};
scanf("%d",&i);
if (i <16) strcpy(res, "DISPENSADO");
else{
  if (i <18) strcpy(res, "FACULTATIVO");
  else{
    if (i < 70) strcpy(res, "OBRIGATORIO");
    else strcpy(res, "DISPENSADO");
}
}
printf("%s",res);
}
