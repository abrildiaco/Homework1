//Implemente una lista enlazada que utilice nodos que simplemente contengan un 
//valor y una dirección de memoria de un nodo. Adicionalmente, agregue las siguientes 
//funciones para manejar la lista: 
//create_node(): devuelve un nodo. 
//push_front(): inserta un nodo al frente de la lista. 
//push_back(): inserta un nodo al final de la lista. 
//insert(): inserta un nodo en la posición que se le pase a la función. Si se le pasa 
//una posición mayor al largo de la lista, se debe indicar lo ocurrido y se debe de 
//agregar el nodo al final de la lista. 
//erase(): borra un nodo en la posición que se le pase a la función. Similar a la 
//función insert(), si la posición es mayor que el largo de la lista, se debe de borrar 
//el último nodo. 
//print_list(): imprime la lista completa, separando el valor en cada nodo con “->”. 


#include <memory>
#include <iostream>
using namespace std;

//Definicion de estructuras
struct Node{
    shared_ptr<Node> next;
    int value = 0;
};

struct List{
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
    int size=0;
};

//Definicion de funciones

shared_ptr<Node> create_node(const int value){
    shared_ptr<Node> new_node = make_shared<Node>();
    new_node->next = nullptr;
    new_node->value = value;
    return new_node;
}

void push_front(const int value, List& lista){
    shared_ptr<Node> new_node = create_node(value);
    new_node->next = lista.head;
    lista.head = new_node;
    if (!lista.tail) lista.tail = new_node;
    lista.size++;
    return;
}

void push_back(const int value, List& lista){
    shared_ptr<Node> new_node = create_node(value);
    new_node->next = nullptr;
    if (!lista.head) {
        lista.head = lista.tail = new_node;
    } else {
        lista.tail->next = new_node;
        lista.tail = new_node;
    }
    lista.size++;
    return;
}

void insert(const int value, int i, List& lista){
    if (i>=lista.size) {
        cout<<"Posicion mayor al tamaño de la lista"<<endl;
        push_back(value, lista);
        return;
    }
    if (i == 0) {
        push_front(value, lista);
        return;
    }
    shared_ptr<Node> new_node = create_node(value);
    shared_ptr<Node> actual = lista.head;
    int contador = 0;
    while(contador < i-1 && actual->next){
        actual = actual->next;
        contador++;
    }

    new_node->next = actual->next;
    actual->next = new_node;
    if (!new_node->next) lista.tail = new_node;
    lista.size++;
    return;

}

void erase(int i, List& lista){
    shared_ptr<Node> actual = lista.head;
    
    if (!lista.head) {cout<<"Posicion mayor al tamaño de la lista"<<endl; return;}
    
    if (i>=lista.size) {
        cout<<"Posicion mayor al tamaño de la lista"<<endl;
        
        while(actual->next->next){
            actual = actual->next;
        }

        actual->next = nullptr;
        lista.tail = actual;
        lista.size--;
        return;
    }
    if (i == 0) {
        lista.head = lista.head->next;
        if (!lista.head) lista.tail = nullptr;
        lista.size--;
        return;
    }
    
    int contador = 0;
    while(contador <= i-1 && actual->next){
        actual = actual->next;
        contador++;
    }
    if (!actual->next) return;

    actual->next = actual->next->next;
    if(!actual->next) lista.tail = actual;
    lista.size--;
    return;
}

void print_list(List& lista){
    shared_ptr<Node> actual = lista.head;
    while(actual){
        cout<<"-->"<<actual->value;
        actual = actual->next;
    }
    
    return;
}

int main() {
    List lista;
    int a = 10, b = 20, c = 30;
    push_back(a, lista);
    push_back(b, lista);
    push_front(c, lista);
    print_list(lista);
    cout<<"\n"<<endl;
    
    insert(b, 10, lista);
    print_list(lista);
    cout<<"\n"<<endl;
    
    erase(10, lista);
    print_list(lista);
    cout<<"\n"<<endl;

    return 0;
}