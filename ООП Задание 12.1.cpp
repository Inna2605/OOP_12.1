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
    cout << "\n\nФайл слова из семи букв и более.\n\n";
    inf.seekg(0);
    while (!inf.eof()) {
        inf >> strInput;
        int length = strInput.size();
        char a = ',', b = '.', c = '!', d = '"';
        if (strInput.find(a) || strInput.find(b) || strInput.find(c)) {
            length -= 1;
        }
        else if (strInput.find(d)) {
            length -= 2;
        }
        if (length >= 7) {
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