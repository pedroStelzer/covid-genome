#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename T> class Table
{
    private:

    public:


};

int main() {

    ifstream arquivo("genome.txt"); // Abre o arquivo para leitura

    if (!arquivo) 
    {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    string linha;
    while (getline(arquivo, linha)) 
    {
        //
    }

    arquivo.close(); // Fecha o arquivo
    return 0;
}
