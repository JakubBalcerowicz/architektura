#include<stdio.h>

int main()
{
int x=5;
int x2=123;

asm volatile (
      ".intel_syntax noprefix;"
      "mov eax, %1;"
      "add eax,eax;"
      "mov %0,eax;"
      ".att_syntax prefix;"
      :"=r" (x2)
      :"r" (x)
      :"eax"
       
);


printf("x=%d  x2=%d", x, x2);

return 0;
}
