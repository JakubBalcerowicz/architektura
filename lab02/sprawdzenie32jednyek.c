#include<stdio.h>

int main()
{
int x=100;
int x2=0;

asm volatile (
      ".intel_syntax noprefix;"
      "mov eax, %1;"
      "xor ebx,ebx;"  
      "xor ecx,ecx;" 
      "petla:"

      "shl eax;"
      "jnc a1;"
      "inc ebx;"
      "a1:"
      "inc ecx;"
      "cmp ecx,32;" //porwnaj exc z 32 jezli 0 koniec jezli nie idz dalej 
      "jnz petla;"  //jezli nie zapolona flaga Z idz do petla
    
      
      "mov %0,ebx;"
      ".att_syntax prefix;"
      :"=r" (x2)
      :"r" (x)
      :"eax","ebx","ecx"
       
);


printf("x=%d  x2=%d", x, x2);

return 0;
}
