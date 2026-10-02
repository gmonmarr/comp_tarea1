// hash table

// prompt para chatgpt: "write a really simple hash table self implementation in c++ leave out the collision handling for demonstration, with key-value pairs. Only implement insert and get"
// https://chatgpt.com/s/t_6abf329d78b881919f032d3640fbc3b4

#include <iostream>
#include <string>
using namespace std;

class HashTable {
private:
    static const int SIZE = 10; // declarar tamaño de la tabla

    pair<string, int> table[SIZE]; // crear un array de tupla key-value

    // función hash simple que suma los valores ASCII
    // const string& para no modificar y no copiar el string
    int hashFunction(const string& key) {
        int hash = 0;
        for (char c : key)
            hash += c;
        return hash % SIZE;
    }

public:
    // añadir a la tabla hash
    // pedí key value pair para demostrar la colisión
    void insert(const string& key, int value) {
        int index = hashFunction(key);
        table[index] = {key, value}; 
    }
    
    // obtener valor de la tabla hash
    int get(const string& key) {
        int index = hashFunction(key);

        if (table[index].first == key)
            return table[index].second;

        return -1; // key not found
    }
};

int main() {
    HashTable ht; // declarar

    ht.insert("ab", 10); // insertar
    cout << ht.get("ab") << '\n'; // obtener 10

    ht.insert("ba", 20); // insertar otro valor con la misma suma de ASCII
    cout << ht.get("ba") << '\n'; // obtener 20 (se reemplazó el valor anterior)
}
