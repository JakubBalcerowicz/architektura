#include<stdio.h>

int main()
{
int x=0xFF00;
int x2;

asm volatile (
      ".intel_syntax noprefix;"
      "mov eax, %1;"
      "xor ebx,ebx;"  
      "xor ecx,ecx;"
      "xor edx,edx;" 
      "petla:"

                       
      "a1:"
      "shl eax;"
      "jc a3;"
      "inc ebx;"
      "jmp a1;"
	
      "a3:"
      
      "cmp edx,ebx;"
      "jae a2;"
      "mov edx,ebx;"
      
      
      
      
     
      "a2:"
      "mov ebx,0;"
      	
      
      "inc ecx;"
      "cmp ecx,32;" //porwnaj exc z 32 jezli 0 koniec jezli nie idz dalej 
      "jnz petla;"  //jezli nie zapolona flaga Z idz do petla
    
      
      "mov %0,edx;"
      ".att_syntax prefix;"
      :"=r" (x2)
      :"r" (x)
      :"eax","ebx","ecx","edx"
       
);


printf("x=%d  x2=%d", x, x2);

return 0;
}
// flagi jezli wynik czegos 1 zapala flage jezli 0 nie zapala 
