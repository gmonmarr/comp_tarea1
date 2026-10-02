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

    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.push(11); // deberíamos tener un mensaje de stack overflow (comprobar a mano)

    // borrar 10 elementos (todo el stack)
    for (int i = 0; i < 10; i++){
        cout << "Valor: " << s.pop() << " eliminado" << endl;
    }

    assert(s.isEmpty() == true);
    assert(s.peek() == -1); // debería regresar -1, stack vacío (e imprimir stack underflow)
    assert(s.pop() == -1); // stack vacío (e imprimir stack underflow)
    
}