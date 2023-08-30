//Дан текстовый файл. Необходимо создать новый файл, в который переписать из исходного файла все слова, 
//состоящие не менее чем из семи букв.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Файл стихотворение.\n\n";
    ifstream inf("Skald.txt");
    if (!inf) {
        cerr << "Невозможно открыть файл для чтения!";
        exit(1);
    }
    string strInput;
    while (!inf.eof())
    {
       getline(inf, strInput);
       cout << strInput << endl;
    }
    inf.seekg(0);
    cout << "\n\nФайл слова из семи букв и более.\n\n";

    fstream iofile("Skald.txt", ios::in | ios::out);
    if (!iofile) {
        cerr << "Невозможно открыть файл!";
        exit(1);
    }
    char A;
    while (iofile.get(A)) {
        switch (A) {
        case ',':
        case '.':
        case '!':
            iofile.seekg(-1, ios::cur);
            iofile << ' ';
            iofile.seekg(iofile.tellg(), ios::beg);
            break;
        }
    }
    while (!inf.eof()) {
        inf >> strInput;
        if(strInput.size() >= 7 ){
            cout << strInput << endl;
            ofstream outf("Seven letters.txt", ios::app);
            if (!outf) {
                cerr << "Невозможно открыть файл для записи!";
                exit(1);
            }
            outf << strInput << endl;
        }
    }
}