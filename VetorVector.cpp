#include <cstdlib>
#include <iostream>

#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char **argv){

    int vetorNum[] = {1, 2, 3};
    int vetorNum2[5] = {1, 2, 3};

// --------------------------------------------

    vector<int> vectorNum(2);
    vectorNum[0] = 55;
    vectorNum[1] = 66;

    cout << "Tamanho do vector antes do push_back: " << vectorNum.size() << endl;

    // vai aumentar também o tamanho do vetor para 3
    vectorNum.push_back(77);

    cout << "Valor da posicao do push_back: " << vectorNum[2] << "\n";
    cout << "Tamanho do vector depois do push_back: " << vectorNum.size() << endl;

    cout << "-----Todos os elementos do vetor:";
    for(int i = 0; i < vectorNum.size(); i++)
        cout << " " << vectorNum[i];

// --------------------------------------------
    
    vector<string> palavras;
    stringstream ss("\nPalavra aleatoria");
    string palavra;
    
    while(getline(ss, palavra, ' ')){
        palavras.push_back(palavra);
        // quebra a palavra para printar em linhas separadas
    }

    for(int i = 0; i < palavras.size(); i++){
        cout << palavras[i] << endl;
        // printa em linhas separadas
    }

// --------------------------------------------

    int vetorNum3[] = {1, 2, 3};
    for(auto x: vetorNum3) cout << x << endl;


    return 0;
}