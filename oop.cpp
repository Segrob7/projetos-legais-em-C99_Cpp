#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Livro{
public:
    string Author;
    string Nameofthebook;
    vector <int> Date;


    Livro(string name, string book, vector<int> data){
        Author = name;
        Nameofthebook = book;
        Date =data;
    }

    void print(){
        cout << "Name of the Author: " << Author << endl;
        cout << "Book Name: " << Nameofthebook << endl;

        for(size_t i = 0; i < Date.size(); i++){
            printf("%02d", Date[i]);
            
            if(i < Date.size() - 1){
                cout << "/";
            }
        }

        cout << endl;
    }
};

    vector<Livro> Register(){
            vector<Livro> catalogo;
            int cont = 1;

            while(cont == 1){
                string Author, bookname;
                int day, month, year;

                cout << "Book registration" << endl;
                cout << "Author Name: ";
                getline(cin, Author);
                
                cout << "Book name: ";
                getline(cin, bookname);
 
                cout << "Digit the day, the month and the year respectively: ";
                cin >> day >> month >> year;
                vector <int> dataBook = {day, month , year};

                catalogo.emplace_back(Author, bookname, dataBook);

                cout << "Want to register another book?(1/0): ";
                cin >> cont;

                cin.ignore();
            }
            return catalogo;
    }

void SaveToFile(const vector<Livro>& catalogo, const string& filename){
    ofstream file(filename);

    if(!file.is_open()){
        cout << "ERROR , file couldn't be open \"" << filename << "\" for writining." << endl;
        return;
    }

    for(const auto& livro : catalogo){
        file << livro.Author << "\n";
        file << livro.Nameofthebook << "\n";
        file << livro.Date[0] << " " << livro.Date[1] << " " << livro.Date[2] << "\n";
    }

    file.close();
    cout << "Catalog saved in \"" << filename << "\" with success! (" << catalogo.size() << " book(s))" << endl;
}

vector<Livro> LoadFromFile(const string& filename){
    vector<Livro> catalogo;
    ifstream file(filename);

    if(!file.is_open()){
      
        return catalogo;
    }

    string author, bookname;
    int day, month, year;

    while(getline(file, author)){
        getline(file, bookname);
        file >> day >> month >> year;
        file.ignore(); 

        vector<int> dataBook = {day, month, year};
        catalogo.emplace_back(author, bookname, dataBook);
    }
    file.close();
    return catalogo;
}

int main(){

    const string filename = "catalogo.txt";

    vector<Livro> minecatalog = LoadFromFile(filename);
    cout << "Books loaded from the file: " << minecatalog.size() << "\n" << endl;

    char opcao;
    cout << "want to register new books? (y/n): ";
    cin >> opcao;
    cin.ignore();

    if(opcao == 'y' || opcao == 'Y'){
        vector<Livro> novosLivros = Register();

        for(const auto& livro : novosLivros){
        minecatalog.push_back(livro);
    }

        SaveToFile(minecatalog, filename);
}

    for (int i = 0; i < (int)minecatalog.size(); i++) {
        cout << "\nLivro #" << (i + 1) << endl;
        minecatalog[i].print();
    }

    return 0;
}