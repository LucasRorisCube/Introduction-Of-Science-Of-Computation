#include <stdio.h>

int main(void) {
int a,b,temp;
scanf("%d",&a);
scanf("%d",&b);
while (b!=0){
temp = b;
b = a%b;
a = temp;
}
printf("%d",a);
}