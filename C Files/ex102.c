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
  int n;
  scanf("%d",&n);
  struct data data[n];
  for(int i = 0;i<n;i++){
    scanf("%d/%d/%d",&data[i].d,&data[i].m,&data[i].a);
  }
  for(int i = 0;i<n;i++){
    switch(data[i].m){
      case 1:
      if(data[i].d>31){
          printf("DATA INVALIDA\n");
        } else {
          printf("%d de janeiro de %d\n",data[i].d,data[i].a);
        }
        break;
      case 2:
        if(data[i].d>(28+bissesto(data[i].a))){
            printf("DATA INVALIDA\n");
          } else {
            printf("%d de fevereiro de %d\n",data[i].d,data[i].a);
          }
          break;
      case 3:
      if(data[i].d>31){
          printf("DATA INVALIDA\n");
        } else {
          printf("%d de março de %d\n",data[i].d,data[i].a);
        }
        break;
        case 4:
      if(data[i].d>30){
          printf("DATA INVALIDA\n");
        } else {
          printf("%d de abril de %d\n",data[i].d,data[i].a);
        }
        break;
      case 5:
      if(data[i].d>31){
          printf("DATA INVALIDA\n");
        } else {
          printf("%d de maio de %d\n",data[i].d,data[i].a);
        }
        break;
        case 6:
      if(data[i].d>30){
          printf("DATA INVALIDA\n");
        } else {
          printf("%d de junho de %d\n",data[i].d,data[i].a);
        }
        break;
      case 7:
      if(data[i].d>31){
          printf("DATA INVALIDA\n");
        } else {
          printf("%d de julho de %d\n",data[i].d,data[i].a);
        }
        break;
      case 8:
      if(data[i].d>31){
          printf("DATA INVALIDA\n");
        } else {
          printf("%d de agosto de %d\n",data[i].d,data[i].a);
        }
        break;
        case 9:
      if(data[i].d>30){
          printf("DATA INVALIDA\n");
        } else {
          printf("%d de setembro de %d\n",data[i].d,data[i].a);
        }
        break;
      case 10:
      if(data[i].d>31){
          printf("DATA INVALIDA\n");
        } else {
          printf("%d de outubro de %d\n",data[i].d,data[i].a);
        }
        break;
        case 11:
      if(data[i].d>30){
          printf("DATA INVALIDA\n");
        } else {
          printf("%d de novembro de %d\n",data[i].d,data[i].a);
        }
        break;
      case 12:
        if(data[i].d>31){
          printf("DATA INVALIDA\n");
        } else {
          printf("%d de dezembro de %d\n",data[i].d,data[i].a);
        }
        break;
      default:
        printf("DATA INVALIDA\n");
        break;
    }
  }
}