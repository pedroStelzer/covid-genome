#include <iostream>
#include <fstream>
#include <string>
#include <random>

using namespace std;

int main() 
{

    // Cria um gerador de números aleatórios
    random_device rd; // Fonte de entropia
    mt19937 gen(rd()); // Mersenne Twister para geração de números aleatórios

    // Define o intervalo dos números aleatórios
    uniform_int_distribution<> distrib(1, 100); // Gera números entre 1 e 100

    // Abre o arquivo para salvar a saída
    ofstream random_genome("random-genome.txt"); // Abre o arquivo para escrita
    if (!random_genome) {
        cout << "Erro ao criar o arquivo de saída!" << endl;
        return 1;
    }
    
    // Gera 500 sequências de 60 bases nitrogenadas aleatórias
    for(int i = 0; i < 500; i++)
    {
        for(int j = 0; j < 60; j++)
        {
            int num = distrib(gen);
            num %= 4;

            if(num == 0)
                random_genome << "A";
            else if(num == 1)
                random_genome << "C";
            else if(num == 2)
                random_genome << "G";
            else if(num == 3)
                random_genome << "T";
        }

        random_genome << endl; // Adiciona uma nova linha após cada sequência de 60 bases
    }

    random_genome.close(); // Fecha o arquivo de saída

    return 0;
}