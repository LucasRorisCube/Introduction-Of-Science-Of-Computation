#include <stdio.h>
struct data{
  int d;
  int m;
  int a;
};

int bissesto(int a) {
int res;
if (a>0){
  if(((a%4 == 0)&&(a%100 != 0))||(a%400 == 0)){
    res = 1;
  }
  else{
    res = 0;
  }
}
else res = -1;
return res;
}

int main(void) {
  struct data data;
  scanf("%d/%d/%d",&data.d,&data.m,&data.a);
  switch(data.m){
    case 1:
    if(data.d>31){
        printf("DATA INVALIDA\n");
      } else {
        printf("%d de janeiro de %d",data.d,data.a);
      }
      break;
    case 2:
      if(data.d>(28+bissesto(data.a))){
          printf("DATA INVALIDA\n");
        } else {
          printf("%d de fevereiro de %d",data.d,data.a);
        }
        break;
    case 3:
    if(data.d>31){
        printf("DATA INVALIDA\n");
      } else {
        printf("%d de março de %d",data.d,data.a);
      }
      break;
      case 4:
    if(data.d>30){
        printf("DATA INVALIDA\n");
      } else {
        printf("%d de abril de %d",data.d,data.a);
      }
      break;
    case 5:
    if(data.d>31){
        printf("DATA INVALIDA\n");
      } else {
        printf("%d de maio de %d",data.d,data.a);
      }
      break;
      case 6:
    if(data.d>30){
        printf("DATA INVALIDA\n");
      } else {
        printf("%d de junho de %d",data.d,data.a);
      }
      break;
    case 7:
    if(data.d>31){
        printf("DATA INVALIDA\n");
      } else {
        printf("%d de julho de %d",data.d,data.a);
      }
      break;
    case 8:
    if(data.d>31){
        printf("DATA INVALIDA\n");
      } else {
        printf("%d de agosto de %d",data.d,data.a);
      }
      break;
      case 9:
    if(data.d>30){
        printf("DATA INVALIDA\n");
      } else {
        printf("%d de setembro de %d",data.d,data.a);
      }
      break;
    case 10:
    if(data.d>31){
        printf("DATA INVALIDA\n");
      } else {
        printf("%d de outubro de %d",data.d,data.a);
      }
      break;
      case 11:
    if(data.d>30){
        printf("DATA INVALIDA\n");
      } else {
        printf("%d de novembro de %d",data.d,data.a);
      }
      break;
    case 12:
      if(data.d>31){
        printf("DATA INVALIDA\n");
      } else {
        printf("%d de dezembro de %d",data.d,data.a);
      }
      break;
    default:
      printf("DATA INVALIDA\n");
      break;
  }
}