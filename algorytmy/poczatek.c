#include<stdio.h>
#include<string.h>


typedef struct {

    char word[255];
    //int word;
    }Lista;

int main(){

Lista tab[5];


char slowo[255];
int dlugosc;
printf("podaj slowo: ");

scanf("%s", &slowo);

strcpy(tab[0].word,slowo);
strcpy(tab[1].word,slowo);
printf("%s \n%s\n",tab[0].word,tab[1].word);

return 0;
}
