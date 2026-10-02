// obligatorio
// estructura fifo (first in, first out)
// [1, 2, 3, 4, 5] -> pop() -> 1

// https://www.geeksforgeeks.org/cpp/queue-cpp-stl/

// funciones para quque
// front() -> devuelve el primer elemento (sin borrarlo)
// back() -> devuelve el ultimo elemento (sin borrarlo)
// empty() -> T/F si la fila está vacía
// size() -> devuelve el tamaño de la fila
// push() -> agrega un elemento al final de la fila
// pop() -> elimina el primer elemento de la fila

// funciones que no implementaré
// emplace() -> agrega un elemento al final de la fila
// swap() -> intercambia los elementos de dos colas
// push_range() -> agrega un rango de elementos al final de la fila
// operadores de comparación -> compara dos colas

// https://www.geeksforgeeks.org/cpp/cpp-program-to-implement-queue-using-linked-list/
// recomendable usar linked list para implementar la fila
// beneficio es que no hay límite de tamaño
// estaré copiando el código de esa página

# include <cassert>
# include <iostream>
using namespace std;

// declarar un nodo de la linked list
struct Node {
    int data; // guarda información (sólo int por ahora)
    Node* next; // ptr al siguiente nodo
};

class Queue {
    Node* front_; // ptr al primer nodo
    Node* back_; // ptr al último nodo
    int size_; // tamaño de la fila
    // uso de var_ para diferenciar entre las variables y funciones
public:
    // constructor vacío
    Queue() {
        // inicializar ptrs a null
        front_ = nullptr;
        back_ = nullptr;
        size_ = 0;
    }

    // destructor
    ~Queue() {
        // eliminar todos los nodos
        while (front_ != nullptr) {
            Node* temp = front_; // guardar el ptr al nodo actual
            front_ = front_->next; // avanzar al siguiente nodo
            delete temp; // borrar el nodo actual
        } // repetir hasta que front sea null
    }
    
    // regresar el primer elemento de la fila
    int front(){
        return front_->data;
    }

    // regresar el último elemento de la fila
    int back(){
        return back_->data;
    }

    // T/F si la fila está vacía
    bool empty(){
        return front_ == nullptr;
    }

    // devuelve el tamaño de la fila
    int size(){
        return size_;
    }

    // agregar elemento al final de la fila 
    void push(int val){
        Node* newNode = new Node(); // crear un nuevo nodo
        newNode->data = val; // asignar el valor al nodo
        newNode->next = nullptr; // no hay siguiente nodo aún
        size_++; // incrementar el tamaño de la fila

        if (front_ == nullptr) { // si es el primer elemento agregado
            front_ = newNode; 
            back_ = newNode;
            // como front y back son ptrs, ambos apuntarán al mismo nodo
            // cuando se agregue el segundo elemento, back (el primer nodo) se actualiza a apuntar (next) al segundo nodo
            // 
        } else { // si no es el primer elemento agregado
            back_->next = newNode; // enlazar el nuevo nodo al final (como front y back son ptrs, )
            back_ = newNode; // actualizar el ptr al último nodo
        }
    }
    
    int pop(){
        Node* temp; // nuevo nodo temp
        temp = front_; // guardar el ptr al primer nodo
        int value = temp->data; // guardar el valor antes de borrar el nodo
        front_ = front_->next; // avanzar en la linked list
        
        if (front_ == nullptr) {
            back_ = nullptr; // si la fila está vacía, actualizar back a null
        }

        size_--; // decrementar el tamaño de la fila
        delete temp; // borrar el primer nodo
        return value; // regresar el valor del primer nodo
    }
};

// test de la clase Queue
// creado por GitHub Copilot
// prompt: "how do I avoid the collision between the function size() and the int size() also help me add more tests, and give me the macos compile cpp command"
int main(){
    Queue q; // llamada a mi propia clase Queue

    // asert() para obligar el funcionamiento correcto, regresa un error si la condición es falsa
    assert(q.empty());
    assert(q.size() == 0);

    q.push(1); // 1
    q.push(2); // 1 2
    q.push(3); // 1 2 3

    assert(!q.empty()); // not empty
    assert(q.size() == 3); // size 3
    assert(q.front() == 1); // front 1
    assert(q.back() == 3); // back 3

    assert(q.pop() == 1); // pop 1 (regresa el valor del primer nodo)
    assert(q.size() == 2); // actualización correcta
    assert(q.front() == 2); // front 2
    assert(q.back() == 3); // back 3

    assert(q.pop() == 2); // doble pop
    assert(q.pop() == 3);

    assert(q.empty()); // sea vacío
    assert(q.size() == 0); 

    q.push(42); // que una una queue instanciada funcione correctamente
    assert(q.front() == 42);
    assert(q.back() == 42);
    assert(q.size() == 1);

    assert(q.pop() == 42);
    assert(q.empty());

    cout << "Correcta ejecución." << endl;
    return 0;
}