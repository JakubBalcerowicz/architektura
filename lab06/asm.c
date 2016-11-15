#include<stdio.h>

int main(){

	   char* s = "tqr  b qabxx xryc pqr";
        int x,y;
	  asm volatile (

          ".intel_syntax noprefix;"

                "mov eax, %2;"
                "mov ebx, 0;"
                "mov ecx, 0;"

        "petla:"
                "mov ecx, 0;"
                "cmp byte ptr [eax], 'b';"
                "jne sprawdzp;"
                "inc eax;"
                "inc ebx;"
                 "inc ecx;"
                "jmp sprawdznotr;"

        "sprawdzp:"

                "cmp byte ptr [eax], 'a';"
                "jne sprawdz0;"
                "inc eax;"
                "inc ebx;"
                 "inc ecx;"

        "sprawdznotr:"

                "cmp byte ptr [eax], 'x';"
                "jne sprawdz1;"
                "inc eax;"
                "inc ebx;"
                 "inc ecx;"
                 "jmp petla;"

        "szukanier:"

                "cmp byte ptr [eax], 'x';"
                "jne sprawdz1;"

                "jmp wyjscie;"



        "sprawdz0:"
                 "cmp byte ptr [eax], 0;"
                 "je wyjscie;"
                 "inc eax;"
                 "inc ebx;"
                 "jmp petla;"


        "sprawdz1:"
                 "cmp byte ptr [eax], 0;"
                 "je wyjscie;"
                 "inc eax;"
                 "inc ecx;"
                 "jmp szukanier;"


            "wyjscie:"
                "add ebx,-1;"        //odejmuje -1 bo konczy liczyc dopiero  po sprawdzeniu drugiej litery
                "add ecx,1;"
                "mov %0, ebx;"
                "mov %1, ecx;"

                ".att_syntax prefix;"
                :"=r" (x), "=r" (y)
                :"r" (s)
                :"al","eax", "ebx", "ecx"
        );
        printf("[ab][^x]=%hd\n +x=%hd", x, y);
        getchar();
        return 0;
}
