#include<stdio.h>

int main(){

	   char* s = "tqr  b qabxx xryc pqr";
        int x,y;
	  asm volatile (

          ".intel_syntax noprefix;"

                "mov ebx, %2;"
                "mov eax, 0;"
                "mov ecx, 0;"

        "petla:"
                "mov ecx, 0;"
                "cmp byte ptr [ebx], 'b';"
                "jne sprawdzp;"
                "inc ebx;"
                "inc eax;"
                 "inc ecx;"
                "jmp sprawdznotx;"

        "sprawdzp:"

                "cmp byte ptr [ebx], 'a';"
                "jne sprawdz0;"
                "inc ebx;"
                "inc eax;"
                 "inc ecx;"

        "sprawdznotx:"

                "cmp byte ptr [ebx], 'x';"
                "jne sprawdz1;"
                "inc ebx;"
                "inc eax;"
                 "inc ecx;"
                 "jmp petla;"

        "szukaniex:"

                "cmp byte ptr [ebx], 'x';"
                "jne sprawdz1;"

                "jmp wyjscie;"



        "sprawdz0:"
                 "cmp byte ptr [ebx], 0;"
                 "je wyjscie;"
                 "inc ebx;"
                 "inc eax;"
                 "jmp petla;"


        "sprawdz1:"
                 "cmp byte ptr [ebx], 0;"
                 "je wyjscie;"
                 "inc ebx;"
                 "inc ecx;"
                 "jmp szukaniex;"


            "wyjscie:"
                "add eax,-1;"        //odejmuje -1 bo konczy liczyc dopiero  po sprawdzeniu drugiej litery
                "add ecx,1;"
                "mov %0, eax;"
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
