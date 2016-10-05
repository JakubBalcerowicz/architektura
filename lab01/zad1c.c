//x20
#include<stdio.h>

int main()
{
int x=5;
int x2=123;

asm volatile (
      ".intel_syntax noprefix;"
      "mov eax, %1;"  //x
      "add eax,eax;"   //2x
      "add eax,eax;"   //4x
      "mov ebx,eax;"
      "add eax,eax;"  //8x
      "add eax,eax;"  //16x
      "add eax,ebx;"
      
      "mov %0,eax;"
      ".att_syntax prefix;"
      :"=r" (x2)
      :"r" (x)
      :"eax"
       
);


printf("x=%d  x2=%d", x, x2);

return 0;
}
