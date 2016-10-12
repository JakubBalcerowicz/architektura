#include<stdio.h>

int main()
{
int x=-1;
int x2=0;

asm volatile (
      ".intel_syntax noprefix;"
      "mov eax, %1;"
      "mov ebx,0;"     //wyzerowanie ebx      (xor ebx,ebx)  zeruje ebx
      "shl eax;"     //przeusnbice o 1 w lewo
      "jnc a1;"      //jnc jezli bit jets nie zaplony skacze do a1
      "add ebx,1;"    // inc ebx; dodaje 1 ebx
      "a1:"
      "shl eax;"
      "jnc a2;"
      "add ebx,1;"
      "a2:"
      "mov %0,ebx;"
      ".att_syntax prefix;"
      :"=r" (x2)
      :"r" (x)
      :"eax"
       
);


printf("x=%d  x2=%d", x, x2);

return 0;
}
