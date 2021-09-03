#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

struct Forma{
    double base, altura;
    
    Forma(double b, double a){
        this->base = b;
        this->altura = a;
    }
    double Area(){
        return base * altura;
    }

    private:
        int id;

};

/*
struct Circulo: Forma{
    Circulo(double altura){
        this->altura = altura;
    }
    double Area(){
        return 3.14 * pow((this->altura / 2), 2);
    }
};
*/

int main(int argc, char **argv){

    Forma forma1(10, 10);
    cout << "Area da forma:" << forma1.Area();

    //Circulo Circulo1(10);
    //cout << "Area do circulo:" << Circulo1.Area();

    return 0;
}