#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char **argv){
    string palavra1 = "Digite um valor:";
    string num1, num2;
    int soma;


    cout << palavra1;
    // printa a mensagem


    cin >> num1;
    cout << "Digite outro valor:";
    cin >> num2;
    // é como o scanf, mas atribui direto


    int InteiroNum1 = stoi(num1);
    int InteiroNum2 = stoi(num2);
    // converte de string para int


    soma = InteiroNum1 + InteiroNum2;
    printf("A soma é: %d", soma);

    return 0;
}