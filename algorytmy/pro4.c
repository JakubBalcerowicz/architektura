#include<stdio.h>
#include<string.h>


typedef struct {

    char word[255];
    //int word;
    }Lista;

int main(){

Lista tab[5];

strcpy(tab[0].word,"kosma to dupa");
strcpy(tab[1].word,"kosma to dupa");
printf("%s \n%s dana struturalna\n",tab[0].word,tab[1].word);

return 0;
}
