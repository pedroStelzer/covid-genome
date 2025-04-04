#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>
using namespace std;

class HashTable
{
    private:

        int size;
        string *key;
        int *value;

        int hashFunction(string element, int j = 0)
        {
            unsigned long hash = 5381;

            for (char c : element)
            {
                hash = ((hash << 5) + hash) + c; // hash * 33 + c
            }

            hash = (hash + j) % size; // Adiciona o deslocamento para resolver colisões

            if(hash < 0) 
                hash += size; // Garante que o hash seja positivo
            
            if(key[hash] == "" || key[hash] == element)
                return hash;
            else
                return hashFunction(element, ++j);
        }

        int hashFunctionSearch(string element, int j = 0)
        {
            unsigned long hash = 5381;

            for (char c : element)
            {
                hash = ((hash << 5) + hash) + c; // hash * 33 + c
            }

            hash = (hash + j) % size; // Adiciona o deslocamento para resolver colisões

            if(hash < 0) 
                hash += size; // Garante que o hash seja positivo

            if(key[hash] == element)
                return hash;
            else
                return hashFunctionSearch(element, ++j);
        }

    public:

        HashTable(int maxSize)
        {
            size = maxSize;
            key = new string[size];
            value = new int[size];
            for(int i = 0; i < size; i++)
            {
                key[i] = "";
                value[i] = 0;
            }
        }

        ~HashTable()
        {
            delete [] key;
            delete [] value;
        }

        void insert(string element) 
        {
            int hash_key = hashFunction(element);

            if(hash_key != -1)
            {
                key[hash_key] = element;
                value[hash_key]++;
            }
        }

        void remove(string key)
        {
            int hash_key = search(key);

            if(hash_key != -1)
            {
                this->key[hash_key] = "";
                this->value[hash_key] = 0;
            }
        }

        int search(string element)
        {
            int index = hashFunctionSearch(element);
            return value[index];
        }
};

#endif // HASHTABLE_H