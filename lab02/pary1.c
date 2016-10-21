
#include<stdio.h>

int main()
{
int x=-1;
int x2;

asm volatile (
      ".intel_syntax noprefix;"
      "mov eax, %1;"
      "xor ebx,ebx;"  
      "xor ecx,ecx;" 
      "petla:"

      "shl eax;"                   //   111   ---->    1 | 11
      "jnc a2;"                    //   1 | 11  --->  1 | 1
      "a1:"
      "shl eax;"
      "jnc a2;"
      "inc ebx;"
      "jmp a1;"
      

      "a2:"
      
      
      
      	
      
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
