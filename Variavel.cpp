#include <cstdlib>
#include <iostream>

using namespace std;
// para não precisar colocar o std:: toda hora

int main(int argc, char **argv){

    bool Verdade = true;
    char caracterA = 'A';
    float f1 = 1.1111;

    auto VarPegarTipo = 30;
    // serve como o var em JS ou não declarar no python, pega o tipo sozinho 

    printf("\nvalor = %.3f\n", f1);
    cout << sizeof(VarPegarTipo) << endl;
    return 0;
}