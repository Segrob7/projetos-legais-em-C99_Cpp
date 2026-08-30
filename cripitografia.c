#include <stdio.h>
#include <ctype.h>
#include <string.h>


void operacao1(char *frase){
    for(int i = 0; frase[i] != '\0'; i++){
        if(isalpha(frase[i])){
            frase[i] +=3;
        }
    }
}
void operacao2(char *frase){
    int len = strlen(frase);
    for(int i = 0; i < len/2; i++){
        char temp = frase[i];
        frase[i] = frase[len - i- 1];
        frase[len - i - 1] = temp;
    }
}
void operacao3(char *frase){
    int start = 0;
    int end = strlen(frase);
    for(int i = (start + end)/2; i < end; i++){
        frase[i] -=1;
    }
}

int main(){
int n;
scanf("%d", &n); 
for(int i = 0; i < n; i++){
char frase[1000];
scanf(" %[^\n]s", frase);
operacao1(frase);
operacao2(frase);
operacao3(frase);
printf("%s\n", frase);
}
    return 0;
}