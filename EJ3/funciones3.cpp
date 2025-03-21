#include "lista.h"
#include <iostream>
using namespace std;

//Definicion de funciones

shared_ptr<Node> create_node(const int value){
    
    shared_ptr<Node> new_node = make_shared<Node>(); //se crea el nodo
    
    new_node->value = value;//le asigno el valor
    new_node->next = nullptr;  //le pido que su puntero a siguiente sea nulo como valor predeterminado
    
    return new_node;
}

void push_front(const int value, List& lista){
    
    shared_ptr<Node> new_node = create_node(value);
    
    new_node->next = lista.head;//como inserto al principio, el nodo que era el head de lista, para a ser el siguiente de new_node
    lista.head = new_node; //la head de mi lista ahora apunta a new_node
    
    if (!lista.tail) lista.tail = new_node; //si no habia tail, significa que new_node es el único en la lista, 
                                            //por ende, la cola de lista tambien apunta a él
    lista.size++;
    
    cout<<"El valor "<<value<<" se insertó al principio"<<endl;
    
    return;
}

void push_back(const int value, List& lista){
    
    shared_ptr<Node> new_node = create_node(value);
    new_node->next = nullptr; //como se inserta al final, no tiene siguinte-->le asigno un puntero nulo
    
    if (!lista.head) { // si no hay una cabeza de lista, new_node es el primero.--> head y tail apuntan a él
        
        lista.head =  new_node;
        lista.tail = new_node;
    
    } else {
        
        lista.tail->next = new_node;
        lista.tail = new_node;
    }
    
    lista.size++;
    
    cout<<"El valor "<<value<<" se insertó al final"<<endl;
    
    return;
}

void insert(const int value, int i, List& lista){
    
    if (i>=lista.size) { //si el índice es mayor al tamaño de mi lista, inserto el nodo al final
        
        cout<<"Posicion mayor al tamaño de la lista"<<endl;
        push_back(value, lista); //reutilizo función push_back
        return;
    
    }else if (i == 0) { //si el índice es 0, lo inicio al principio
        
        push_front(value, lista); //reutilizo función push_front
        return;
    }
    
    shared_ptr<Node> new_node = create_node(value);
    shared_ptr<Node> actual = lista.head;
    
    int contador = 0;
    
    //avanzo hasta el nodo anterior a la posición en la que queremso insertar new_node
    //si avanzo hasta la posición, no podría encadenar a new_node a la lista
    while(contador < i-1 && actual->next){
        actual = actual->next;
        contador++;
    }

    new_node->next = actual->next;
    actual->next = new_node;
    
    if (!new_node->next) lista.tail = new_node; //si new_node no tiene siguiente--> se insetó al final
    
    lista.size++;

    cout<<"El valor "<<value<<" se insertó en la posición "<<i<<endl;

    return;
}

void erase(int i, List& lista){
    
    shared_ptr<Node> actual = lista.head;
    
    if (!lista.head) {
        
        cout<<"Posición mayor al tamaño de la lista"<<endl; 
        return;
    
    }else if (i>=lista.size) { //si el índice al nodo a eliminar es mayor al tamaño de la lista-->borro el último
        
        cout<<"Posición mayor al tamaño de la lista"<<endl;
        
        //avanzo hasta el nodo en la posición anteriro a eliminar
        while(actual->next->next){
            actual = actual->next;
        }

        actual->next = nullptr; //el siguiente a mi actual ya no va a ser el nodo en la posición final, será nulo
                                // estoy "salteandome" el nodo final --> cuando sale de scope se liberará solo
        lista.tail = actual;
        lista.size--;
        
        cout<<"El ultimo valor fue eliminado"<<endl;
        
        return;
    
    }else if (i == 0) { //si mi posición es cero, elimino el head de lista
        
        lista.head = lista.head->next; //mi nuevo head será el siguiente a eliminar. Asi, me "salteo" el primer nodo
        
        //si mi head es nulo --> no hay mas elementos en la lista --> mi tail tambien es nulo
        if (!lista.head) lista.tail = nullptr; 
        
        lista.size--;
        
        cout<<"El valor en la posición "<<i<<" fue eliminado"<<endl;
        
        return;
    }
    
    int contador = 0;
    
    //avanzo hasta la posición anteriror al nodo a eliminar
    while(contador < i-1 && actual->next){
        
        actual = actual->next;
        contador++;
    }
    
    actual->next = actual->next->next; //me "salteo" el nodo a eliminar --> como es un smart pointer se liberará al salir de scope
    
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
