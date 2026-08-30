#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char nome[1000];
    char escritor[1000];
    int available;

}Livraria;

void SaveToFile(Livraria *livros, int n){
    FILE *file = fopen("biblioteca.txt", "w");
    if(file == NULL){
        printf("error when opening the file");
        return;
    }
    fprintf(file, "%d\n", n);
    for(int i = 0; i < n; i++){
        fprintf(file, "%d\n%s\n%s\n%d\n", livros[i].id, livros[i].nome, livros[i].escritor, livros[i].available);
    }
    fclose(file);
}
void LoadFromFile(Livraria *livros, int *n){
    FILE *file = fopen("biblioteca.txt", "r");
    if(file == NULL){
    return;
    }
    fscanf(file, "%d", n);

    for (int i = 0; i < *n; i++) {
        fscanf(file, "%d\n", &livros[i].id);
        fscanf(file, " %[^\n]\n", livros[i].nome);
        fscanf(file, " %[^\n]\n", livros[i].escritor);
        fscanf(file, "%d\n", &livros[i].available);
    }
    fclose(file);
    printf(">>> %d books from 'biblioteca.txt' <<<\n\n", *n);
}

void Search(Livraria *livros, int n){
char search[1000];
printf("write the name of the book u want to search for");
scanf(" %[^\n]", search);
int achou = 0;
for(int i = 0; i < n; i++){
    if(strcmp(livros[i].nome, search) == 0){
        printf("it's in the canon");
        achou =1;
        break;
    }
    if(achou == 0){
        printf("it isnt't in the canon");
    }
}

}
void Display(Livraria *livros, int n){
    for(int i = 0; i < n; i++){

        printf("position: %d\n%d\n%s\n%s\n%d\n", i, livros[i].id, livros[i].nome, livros[i].escritor, livros[i].available);
    }
}
void Borrow(Livraria *livros, int n){
    int remove;
    scanf("%d", &remove);
    if(remove >=  0 && remove < n){
    livros[remove].available = 0;
    printf("book borrowed\n");
    SaveToFile(livros, n);
    }
    else{
        printf("invalid position\n");
    }
}
int Register(Livraria *livros, int *n){

    printf("enter the id");
    scanf("%d", &livros[*n].id);

    printf("enter the name of the book");
    scanf(" %[^\n]", livros[*n].nome);

    printf("enter the writer name");
    scanf("%[^\n]", livros[*n].escritor);

    printf("use '1' to register");
    scanf("%d", &livros[*n].available);

    (*n)++;
    SaveToFile(livros, *n);
    printf("book registred with sucesses");
    return *n;
}

int main(){

    int n = 0; // n of books 
    Livraria livros[100];
    int command;

    printf("Welcome to the Pedro's library\n");
    printf("1) to search a book; 2) to borrow ; 3) to register; 4) display all books aviables( 1 == avaible, 0 == not avaible)\n");

    while(scanf("%d", &command)!= EOF){
    switch(command){
        case 1:
        Search(livros, n);
        break;

        case 2:
        Display(livros, n);
        printf("chose the position/number of the book u want to borrow");
        Borrow(livros, n);
        break;

        case 3:
        Register(livros, &n);
        break;

        case 4:
        Display(livros, n);
        break;

        default:
        break;
    }
    printf("\n1) Search; 2) Borrow; 3) Register; 4) Display (Ctrl+C to exit)\n");

}
    return 0;
}