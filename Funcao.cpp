#include <cstdlib>
#include <iostream>

using namespace std;

int Soma(int a, int b);
void AtribuirValorPonteiro(int *valor);
void DuplicarVet(int *Vet, int tam);

int main(int argc, char **argv){

    cout << Soma(4, 1) << "\n";


    int valorMain = 40;
    AtribuirValorPonteiro(&valorMain);
    cout << valorMain << "\n";

    cout << "Vetor: \n";
    int IntVetor[] = {1, 2, 3};
    DuplicarVet(IntVetor, 3);
    for(auto x: IntVetor) cout << x << endl;


    return 0;
}

int Soma(int a, int b){
    return a + b;
}

void AtribuirValorPonteiro(int *valor){
    *valor = 200;
}

void DuplicarVet(int *Vet, int tam){
    for(int i=0; i< tam; i++){
        Vet[i] *= 2;
    }
}