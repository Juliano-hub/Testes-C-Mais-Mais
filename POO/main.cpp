#include "Forma.h"

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char **argv){
    Forma forma(10, 5);
    cout << "Base: " << forma.GetBase() << " * Altura: " << forma.GetAltura() << " = " << forma.Area();
}