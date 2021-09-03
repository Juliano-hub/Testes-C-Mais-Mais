#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv){

    ofstream writeToFile;
    ifstream readFromFile;
    string txtToWrite = "";
    string txtFromFile = "";


                                        // ler
    writeToFile.open("teste.txt", ios_base::out | ios_base::trunc);
    if(writeToFile.is_open()){
        writeToFile << "Começo \n";
        cout << "Digite algo:";
        getline(cin, txtToWrite);
        writeToFile << txtToWrite;
        writeToFile.close();
    }

    readFromFile.open("text.txt", ios_base::in);
    if(readFromFile.is_open()){
        while(readFromFile.good()){
            getline(readFromFile, txtFromFile);
            cout << txtFromFile;
        }
        
        readFromFile.close();
    }


    return 0;
}