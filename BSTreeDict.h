#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include<ostream>
#include<stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"
using namespace std;
template<typename V>

class BSTreeDict: public Dict<V>{
    private: 
        BSTree<TableEntry<V>> * tree;
    public: 
        BSTreeDict(){
            tree = new BSTree<TableEntry<V>>();
        }
        
        ~BSTreeDict(){
            delete tree;
        }
        
        friend ostream& operator<<(ostream &out, const BSTreeDict<V> &bs){
            return out << *(bs.tree);
        }
        
        V operator [] (string key){
            TableEntry<V> entry(key);
            return tree->search(entry).value;
        }
        
        void insert(string key, V value)override{
            TableEntry<V> newEntry(key, value);
            tree->insert(newEntry);
        }

        V search(string key)override{
            TableEntry<V> entry(key);
            return tree->search(entry).value;
        }

        V remove(string key)override{
            TableEntry<V> entry(key);
            TableEntry<V> found = tree->search(entry);
            V aux = found.value;
            tree->remove(found);
            return aux;
        }

        int entries()override{
            return tree->size();
        }


};

#endif
