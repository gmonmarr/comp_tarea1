// https://www.geeksforgeeks.org/cpp/stack-implementation-in-cpp/
// el ejemplo de gfg usa array[100] para implementar el stack

// funciones necesarias para stack
// push() nuevo elemento
// pop() regresar y eliminar elemento
// peek() regresar elemento sin eliminarlo
// isEmpty() comprobar si la pila está vacía

# include <cassert>
# include <iostream>
using namespace std;

class Stack {
    int arr_[10]; // arreglo de tamaño 10 para demostrar el stack overflow
    int topidx_; // índice del último elemento agregado
public:
    Stack() { // constructor
        topidx_ = -1; // inicializar el índice a -1 (pila vacía)
    }

    void push(int value) {
        if (topidx_ >= 9) { // comprobar si la pila está llena
            cout << "Stack overflow pushing val: " << value << endl;
            return;
        }
        arr_[++topidx_] = value; // incrementar el índice y agregar el valor
        // IMPORTANTE ++ antes de asignar el valor, 
        // si no quedaremos con el valor en el índice 0 y no en el 1
    }

    bool isEmpty() {
        return topidx_ < 0; // si el índice es menor que 0, la pila está vacía
    }

    int peek() {
        if (isEmpty()) { // comprobar si la pila está vacía
            cout << "Stack underflow" << endl;
            return -1; // valor de error
        }
        return arr_[topidx_]; // regresar el valor sin decrementar el índice
    }

    int pop(){
        if (isEmpty()) { // comprobar si la pila está vacía
            cout << "Stack underflow" << endl;
            return -1; // valor de error
        }
        return arr_[topidx_--]; // regresar el valor y decrementar el índice 
        // cuando volvamos a poner un valor, se sobreescribirá el valor anterior
    }
};

int main(){
    Stack s; // llamar a mi función 

    s.push(1); // agregar 1
    s.push(2); // agregar 2
    s.push(3); // agregar 3

    assert(s.pop() == 3); 
    assert(s.peek() == 2);
    assert(s.isEmpty() == false);

    for(int i = 3; i <= 11; i++){ // agregar 3 a 11
        s.push(i); // en el 11vo debería imprimir stack overflow
    }

    // borrar 10 elementos (todo el stack)
    for (int i = 0; i < 10; i++){
        assert(10 - i == s.pop()); // debería regresar 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
    }

    assert(s.isEmpty() == true);
    assert(s.peek() == -1); // debería regresar -1, stack vacío (e imprimir stack underflow)
    assert(s.pop() == -1); // stack vacío (e imprimir stack underflow)
    
}