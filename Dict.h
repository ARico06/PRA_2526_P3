#ifndef DICT_H
#define DICT_H
#include <string>
using namespace std;

template <typename V>
class Dict{
    public:
    virtual void insert(string key, V value)=0; //inserta el par key-> value. Runtime error. 
    virtual V search(string key)=0; //busca el valor asociado a key. Devuelve runtime error.                                                                   
    virtual V remove(string key)=0; // elimina el par key value si está incluido. Lanza runtime error.                                                         
    virtual int entries()=0; // devuelve num. elementos en el diccionario.      
};

#endif

