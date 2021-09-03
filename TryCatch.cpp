#include <cstdlib>
#include <iostream>

using namespace std;


int main(int argc, char **argv){

    int a=10, b=0;

    try{
        if(b == 0){
            throw "Div por 0";
        }else{
            printf("%d / %d = %.2f", a, b, a/b);
        }
    }catch(const char *exp){
        cout << "Erro: " << exp << endl;
    }

    return 0;
}