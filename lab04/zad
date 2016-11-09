#include <stdio.h>

int main (void){
    
    char *s = "tqr  b qabxx xryc pqr";  // 0 1 2 3 4 5 mamy b potem 123456 od b do x
    int x, y;
    asm volatile (
          ".intel_syntax noprefix;"
          "mov ebx,%2;"
          



          
          "wyjscie:"
          "mov %0,eax;"
          "mov %1,ecx;"
          ".att_syntax prefix;"
          : "=r" (x), "=r" (y)    //argumenty wejsciowe
          : "r" (s)             // wyjscie
          : "eax", "ebx", "ecx"
    );
    printf("%hd,%hd\n", x, y);
    return 0;
}
      
