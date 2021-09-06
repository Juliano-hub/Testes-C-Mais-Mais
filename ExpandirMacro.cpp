#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#include <vector>
#include <sstream>
#include <algorithm>    // std::find

using namespace std;

struct macro{
        string nome;
        vector<string> params; 
        vector<string> paramsDaChamadaNoMain;
        vector<string> DefinicaoDaMacro;
        bool PassouDefinicao = false;

        void addNome(string nome){
            this->nome = nome;
        }
};

struct macro MacroMain;
fstream LerEntrada, Saida;

void AchouMacro(string Linha);
void AchouChamada(string Linha);
void SubstituirPelaMacro();

int main(int argc, char **argv){


                            // escrever
    //LerEntrada.open("macro.txt", ios::out);
    
                            // adiciona no final
    //LerEntrada.open("macro.txt", ios::app);

                            // ler
    LerEntrada.open("macro.txt", ios::in);


    Saida.open("saida.txt", ios::out);

    if(LerEntrada.is_open() && Saida.is_open()){
        string Linha;

        // Linha vai receber a linha atual enquanto conseguir ler pelo getline()
        while(getline(LerEntrada, Linha)){

                size_t ProcuraDefMacro = Linha.find("MACRO");
                size_t ProcuraChamadaMacro = Linha.find(MacroMain.nome);


            if(ProcuraDefMacro != string::npos){
                // vai pegar as infos da macro se ele achou a string MACRO na linha atual
                AchouMacro(Linha);   

                // ler toda a def da macro
                    size_t ProcuraFimMacro = Linha.find("ENDM");
                do{
                    ProcuraFimMacro = Linha.find("ENDM");

                        getline(LerEntrada, Linha);
                        MacroMain.DefinicaoDaMacro.push_back(Linha);

                }while(ProcuraFimMacro == string::npos);
                    MacroMain.DefinicaoDaMacro.resize(MacroMain.DefinicaoDaMacro.size() - 2);
                    // para remover a última linha que ele pega, o 'ENDM'

                MacroMain.PassouDefinicao = true;
            }else if(ProcuraChamadaMacro != string::npos && MacroMain.PassouDefinicao == true){
                // achou uma chamada da macro no código main

                //for(int i=0; i < MacroMain.DefinicaoDaMacro.size(); i++){
                //cout << MacroMain.DefinicaoDaMacro[i] << "\n";
                //}


                AchouChamada(Linha);
                SubstituirPelaMacro();

                

            
                MacroMain.paramsDaChamadaNoMain.clear();
                // limpa os parametros de chamada do main, para que os novos sejam alocados
            }else{
                Saida << Linha;
                Saida << "\n";
            }

        }
    }

    Saida.close();
    LerEntrada.close();
    return 0;
}

void SubstituirPelaMacro(){
    string LinhaAtualMacro;

    for(int i=0; i < MacroMain.DefinicaoDaMacro.size(); i++){
        LinhaAtualMacro = MacroMain.DefinicaoDaMacro[i];

        // verificar e fazer as substituições
        for(int j=0; j < MacroMain.params.size(); j++){
            size_t SubstiturPeloParametro = LinhaAtualMacro.find(MacroMain.params[j]);
            if(SubstiturPeloParametro != string::npos){
                // se ele achou a linha que deve ocorrer a substituição
                LinhaAtualMacro.replace(LinhaAtualMacro.find(MacroMain.params[j]), MacroMain.params[j].size(), MacroMain.paramsDaChamadaNoMain[j]);
            
            }
        }

    Saida << LinhaAtualMacro;
    Saida << "\n";
    }
}

void AchouChamada(string Linha){
    size_t Procura;
    int contador = 0;

    vector<string> palavras;
    stringstream ss = stringstream(Linha);
    string palavra;
    
    while(getline(ss, palavra, ' ')){
        palavras.push_back(palavra);
        contador ++;
        // quebra a palavra para printar em linhas separadas
    }

    int i = 1;
    for(i; i < contador; i++){

        if(palavras[i].find(",") != std::string::npos){
            // remover a virgula

            palavras[i].replace(palavras[i].find(','), palavras[i].find(','), ',', ' ');
            palavras[i].resize(palavras[i].size() - 44);
            // 44 o tamanho da virgula, pego o tamanho total da string e diminuo os 44 da virgula
        }

        MacroMain.paramsDaChamadaNoMain.push_back(palavras[i]);
    }
}

void AchouMacro(string Linha){
    size_t Procura;
    int contador = 0;

    vector<string> palavras;
    stringstream ss = stringstream(Linha);
    string palavra;
    
    while(getline(ss, palavra, ' ')){
        palavras.push_back(palavra);
        contador ++;
        // quebra a palavra para printar em linhas separadas
    }
    
    MacroMain.addNome(palavras[0]);
    //cout << "Nome: " << MacroMain.nome << "\n";

    int i = 2;
    for(i; i < contador; i++){

        if(palavras[i].find(",") != std::string::npos){
            // remover a virgula

            palavras[i].replace(palavras[i].find(','), palavras[i].find(','), ',', ' ');
            palavras[i].resize(palavras[i].size() - 44);
            // 44 o tamanho da virgula, pego o tamanho total da string e diminuo os 44 da virgula
        }

        MacroMain.params.push_back(palavras[i]);

        // printa em linhas separadas
        //cout << "Param" << (i-2) << ":" << MacroMain.params[i - 2] << "\n";
    }
}