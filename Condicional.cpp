#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char **argv){

    string SIdade;
    cout << "Digite sua idade:";
    cin >> SIdade;

    int IIdade = stoi(SIdade);

    if(IIdade >= 18){
        cout << "Maior de idade\n";
    }else{
        cout << "Menor de idade\n";
    }

    // if e else
    bool maior = (IIdade >= 18) ? true : false; 
    cout.setf(ios::boolalpha);
    // converte
    
    cout << maior;


    return 0;
}