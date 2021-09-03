#include <cstdlib>
#include <iostream>


using namespace std;

int main(int argc, char **argv){
    int num, numAleat;
    
    numAleat = rand() % 10;
    num = 0;

    do{

        cout << "Digite um valor:";
        cin >> num;

    }while(num != numAleat);

        cout << "Correto! num:" << numAleat << endl;

    return 0;
}