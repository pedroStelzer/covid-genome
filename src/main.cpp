#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"
#include "HashTable.h"
#include "Queue.h"

using namespace std;

int main() {

    ifstream file("genome.txt"); // Abre o arquivo para leitura

    if(!file) 
    {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    int size = 0;
    string a;

    while(getline(file, a))
        size++;

    // Reseta o ponteiro do arquivo para o início
    file.clear(); // Limpa o estado de EOF
    file.seekg(0); // Move o ponteiro para o início do arquivo

    HashTable genome_table(size*2*6);
    Queue<string> genomes;
    string line;

    while(getline(file, line)) // Recebe linha por linha do arquivo
    {
        int len_line = line.size();
        string six_block;

        int genoma = 1;
        for(int i = 0; i < len_line; i++) // Itera sobre todas as bases nitorgenadas
        {   
            six_block += line[i];

            if((i+1) % 6 == 0) // A cada 6 bases nitrogenadas, faz a contabilizacao na tabela
            {
                genome_table.insert(six_block);

                if(genome_table.search(six_block) == 1)
                    genomes.enqueue(six_block);

                six_block = ""; // Reseta o bloco de 6 bases nitrogenadas

            }
        }
    }

    while(!genomes.empty())
    {
        string genome = genomes.front();
        genomes.dequeue();

        cout << "Genoma: " << genome << " | Repetidos: " << genome_table.search(genome) << endl;
    }

    file.close(); // Fecha o arquivo

    return 0;
}
