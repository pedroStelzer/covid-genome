#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"
#include "HashTable.h"
#include "Queue.h"

using namespace std;

int main() {

    // Insira o nome do arquivo de entrada
    string file_input = "random-genome.txt";

    // Insira o nome do arquivo de saída
    string file_output = "output-random-genome.txt";

    ifstream file(file_input); // Abre o arquivo para leitura

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

    HashTable genome_table(size*2*6); // Tabela com o par: Genoma(chave) e Repetições(valor)
    Queue<string> genomes; // Fila com os genomas que será usada para armazenar as chaves da tabela
    string line;

    while(getline(file, line)) // Recebe linha por linha do arquivo
    {
        int len_line = line.size();
        string six_block;

        for(int i = 0; i < len_line; i++) // Itera sobre todas as bases nitorgenadas
        {   
            six_block += line[i];

            if((i+1) % 6 == 0) // A cada 6 bases nitrogenadas, faz a contabilizacao na tabela
            {
                genome_table.insert(six_block);

                if(genome_table.search(six_block) == 1) // Se for encontrado uma unica vez, adiciona na fila
                    genomes.enqueue(six_block);

                six_block = ""; // Reseta o bloco de 6 bases nitrogenadas

            }
        }
    }

    // Abre o arquivo para salvar a saída
    ofstream output_file(file_output); // Abre o arquivo para escrita
    if (!output_file) {
        cout << "Erro ao criar o arquivo de saída!" << endl;
        return 1;
    }

    // Formata a tabela
    output_file << "  Genoma   | Repetidos" << endl;

    // Imprime os Genomas encontrados e a quantidade de repetições
    while(!genomes.empty())
    {
        string genome = genomes.front();
        genomes.dequeue();

        output_file << "  " << genome << "   |    " << genome_table.search(genome) << "     " << endl;
    }

    file.close(); // Fecha o arquivo
    output_file.close(); // Fecha o arquivo de saída

    return 0;
}
