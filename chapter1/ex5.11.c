#include<stdio.h>
/* copy input to output; 1sr version */
int main(void){
int c;
c=getchar();
while(c != EOF){
putchar(c);
c = getchar();
}
}

