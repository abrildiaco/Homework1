#pragma once

#include <memory>


/*
Definicion de la estructura Node para valores enteros.
Los nodos fueron definidos con shared pointers pues hay nodos que apunntan a los mismos valores.
Por ejemplo el puntero tail, apunta al mismo nodo que el previo al último. Esto no hubiese
sido posible si se utilizaban unique pointers
*/
struct  Node{
    std::shared_ptr<Node> next;
    int value = 0; //valor del nodo inicializado en 0-->luego se cambiará
};

/*
DEfinición de la estructura List con puntero a head y a tail
*/
struct List{
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    int size = 0; //size de la lista inicializada en cero por default
};

std::shared_ptr<Node> create_node(const int);
void push_front(const int, List&);
void push_back(const int, List&);
void insert(const int, int, List&);
void erase(int, List&);
void print_list(List&);