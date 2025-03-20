#pragma once

#include <memory>

struct  Node{
    std::shared_ptr<Node> next;
    int value = 0;
};

struct List{
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    int size=0;
};

std::shared_ptr<Node> create_node(const int);
void push_front(const int, List&);
void push_back(const int, List&);
void insert(const int, int, List&);
void erase(int, List&);
void print_list(List&);