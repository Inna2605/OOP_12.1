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

    //даний початковий файл
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

    //записуємо з файлу Skald в інший файл Skald_2 і працюємо вже з цим файлом, щоб початковий файл Skald залишився не змінним
    ofstream outf("Skald_2.txt");
    if (!outf) {
        cerr << "Невозможно открыть файл!";
        exit(1);
    }
    while (!getline(inf, strInput).eof()) {
        outf << strInput << endl;
    }
    cout << "\n\nФайл слова из семи букв и более.\n\n";
    inf.close();
    outf.close();
    //працюємо з файлом Skald_2 - копією першого початкового файлу
    fstream iofile("Skald_2.txt", ios::in | ios::out);
    if (!iofile) {
        cerr << "Невозможно открыть файл!";
        exit(1);
    }
    char A;
    while (!iofile.eof()) {
        iofile.get(A);
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
    iofile.close();
    iofile.open("Skald_2.txt");
    while (!iofile.eof()) {
        iofile >> strInput;
        if(strInput.size() >= 7 ){
            cout << strInput << endl;

            //записуємо в файл Seven letters слова, які мають не менше семи букв
            ofstream outf("Seven letters.txt", ios::app);
            if (!outf) {
                cerr << "Невозможно открыть файл для записи!";
                exit(1);
            }
                outf << strInput << endl;
        }
    }
}