#include <memory>
#include <iostream>
using namespace std;

//Deficnicion de estructuras

struct  Node{
    shared_ptr<Node> next;
    int value = 0;
};

struct List{
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
    int size=0;
};

shared_ptr<Node> create_node(const int);
void push_front(const int, List&);
void push_back(const int, List&);
void insert(const int, int, List&);
void erase(int, List&);
void print_list(List&);

//g++ -std=c++20 ejercicio3.cpp -o ej3
//valgrind ./ej3

int main() {
    
    List lista;
    
    push_back(10, lista);
    print_list(lista);
    cout<<"\n"<<endl;
    
    push_back(20, lista);
    print_list(lista);
    cout<<"\n"<<endl;
    
    push_front(30, lista);
    print_list(lista);
    cout<<"\n"<<endl;
    
    insert(35, 1, lista);
    print_list(lista);
    cout<<"\n"<<endl;
    
    insert(15, 10, lista);
    print_list(lista);
    cout<<"\n"<<endl;
    
    erase(3, lista);
    print_list(lista);
    cout<<"\n"<<endl;
    erase(11, lista);
    print_list(lista);
    cout<<"\n"<<endl;
    
    return 0;
}


//------------------------------------------------------------------------------------------------------------

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
    cout<<"El valor "<<value<<" se insertó al principio"<<endl;
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
    cout<<"El valor "<<value<<" se insertó al final"<<endl;
    return;
}

void insert(const int value, int i, List& lista){
    if (i>=lista.size) {
        cout<<"Posicion mayor al tamaño de la lista"<<endl;
        push_back(value, lista);
        return;
    }
    else if (i == 0) {
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

    cout<<"El valor "<<value<<" se insertó en la posición "<<i<<endl;

    return;
}

void erase(int i, List& lista){
    shared_ptr<Node> actual = lista.head;
    
    if (!lista.head) {
        cout<<"Posición mayor al tamaño de la lista"<<endl; 
        return;}
    
    else if (i>=lista.size) {
        cout<<"Posición mayor al tamaño de la lista"<<endl;
        
        while(actual->next->next){
            actual = actual->next;
        }

        actual->next = nullptr;
        lista.tail = actual;
        lista.size--;
        cout<<"El ultimo valor fue eliminado"<<endl;
        return;
    }
    else if (i == 0) {
        lista.head = lista.head->next;
        if (!lista.head) lista.tail = nullptr;
        lista.size--;
        cout<<"El valor en la posición "<<i<<" fue eliminado"<<endl;
        return;
    }
    
    int contador = 0;
    while(contador < i-1 && actual->next){
        actual = actual->next;
        contador++;
    }
    
    if (!actual->next) return;

    actual->next = actual->next->next;
    
    if(!actual->next) lista.tail = actual;
    
    lista.size--;

    cout<<"El valor en la posición "<<i<<" fue eliminado"<<endl;


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
