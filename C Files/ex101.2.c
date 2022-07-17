#include <stdio.h>
struct data{
  int d;
  char sd[2];
  int m;
  int a;
};

int bissesto(int a) {
int res;
  if(((a%4 == 0)&&(a%100 != 0))||(a%400 == 0)){
    res = 1;
  }
  else{
    res = 0;
  }
return res;
}

int main(void) {
  struct data data;
  scanf("%d/%d/%d",&data.d,&data.m,&data.a);
  data.sd[0] = ((data.d)/10 +48);
  data.sd[1] = ((data.d)%10 +48);
  if(data.a > 0){
    switch(data.m){
      case 1:
      if(data.d>31){
          printf("DATA INVALIDA\n");
        } else {
          printf("%c%c de janeiro de %d",data.sd[0],data.sd[1],data.a);
        }
        break;
      case 2:
        if(data.d>(28+bissesto(data.a))){
            printf("DATA INVALIDA\n");
          } else {
            printf("%c%c de fevereiro de %d",data.sd[0],data.sd[1],data.a);
          }
          break;
      case 3:
      if(data.d>31){
          printf("DATA INVALIDA\n");
        } else {
          printf("%c%c de marco de %d",data.sd[0],data.sd[1],data.a);
        }
        break;
        case 4:
      if(data.d>30){
          printf("DATA INVALIDA\n");
        } else {
          printf("%c%c de abril de %d",data.sd[0],data.sd[1],data.a);
        }
        break;
      case 5:
      if(data.d>31){
          printf("DATA INVALIDA\n");
        } else {
          printf("%c%c de maio de %d",data.sd[0],data.sd[1],data.a);
        }
        break;
        case 6:
      if(data.d>30){
          printf("DATA INVALIDA\n");
        } else {
          printf("%c%c de junho de %d",data.sd[0],data.sd[1],data.a);
        }
        break;
      case 7:
      if(data.d>31){
          printf("DATA INVALIDA\n");
        } else {
          printf("%c%c de julho de %d",data.sd[0],data.sd[1],data.a);
        }
        break;
      case 8:
      if(data.d>31){
          printf("DATA INVALIDA\n");
        } else {
          printf("%c%c de agosto de %d",data.sd[0],data.sd[1],data.a);
        }
        break;
        case 9:
      if(data.d>30){
          printf("DATA INVALIDA\n");
        } else {
          printf("%c%c de setembro de %d",data.sd[0],data.sd[1],data.a);
        }
        break;
      case 10:
      if(data.d>31){
          printf("DATA INVALIDA\n");
        } else {
          printf("%c%c de outubro de %d",data.sd[0],data.sd[1],data.a);
        }
        break;
        case 11:
      if(data.d>30){
          printf("DATA INVALIDA\n");
        } else {
          printf("%c%c de novembro de %d",data.sd[0],data.sd[1],data.a);
        }
        break;
      case 12:
        if(data.d>31){
          printf("DATA INVALIDA\n");
        } else {
          printf("%c%c de dezembro de %d",data.sd[0],data.sd[1],data.a);
        }
        break;
      default:
        printf("DATA INVALIDA\n");
        break;
    }
  } else {
    printf("DATA INVALIDA");
  }
}