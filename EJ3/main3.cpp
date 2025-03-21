#include "lista.h"
#include <iostream>
using namespace std;

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

    erase(2, lista);
    print_list(lista);
    cout<<"\n"<<endl;    
    
    return 0;
}


