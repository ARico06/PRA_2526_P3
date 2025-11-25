#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <string>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"
#include "/home/alumno.upv.es/aricala/W/PRA/Lab/PRA_2526_P1/ListLinked.h"
using namespace std;

template<typename V>
class HashTable: public Dict<V>{
    private:
        int n;
        int max;
        ListLinked<TableEntry<V>>* table;
        int h(string key){
            int suma = 0;
            for(int i=0; i<key.length(); i++){
              suma += int(key[i]);
            }
            return suma % max;
        }

    public:
        HashTable(int size){ //Constructor. Crea una ListLinked de "size" elementos tipo TableEntry<V>                                                                                        
            table = new ListLinked<TableEntry<V>>[size];
            n = 0;
            max = size;
        }

        ~HashTable(){ // Destructor de la tabla hash                                                                                                                                          
            delete[]table;
        }

        int entries() override{
            return n;
        }



        int capacity(){
            return max;
        }

        friend ostream& operator <<(ostream &out, const HashTable<V> &th){
            out<<"Tabla: \n";
            for(int i=0; i<th.max; i++){
                if(th.table[i].size()>0){
                    out<<"Cubeta "<<i<<": ";
                    out<<th.table[i]<<endl;
		}
            }
            out<<" \n";
            return out;
	}

        void insert(string key, V value)override{
            int indice = h(key);
            TableEntry<V> nuevaEntrada(key, value);
            ListLinked<TableEntry<V>>& lista = table[indice];

            int pos = -1;
            for(int i = 0; i<lista.size(); i++){
		if(lista[i].key == key){
                    pos = i;
                    break;
                }
            }

            if(pos!=-1){
                throw runtime_error ("La clave ya existe en la tabla\n");
            }else{
                lista.append(nuevaEntrada);
                n++;
		}
        }

        V search(string key) override{
            int indice = h(key);
	    ListLinked<TableEntry<V>>& lista = table[indice];
            for(int i=0; i<lista.size(); i++){
                if(lista[i].key == key){
                    return lista[i].value;
                }
            }
            throw runtime_error ("No se ha encontrado la clave en la tabla\n");
        }


        V operator[](string key){
            return search(key);
        }


        V remove(string key) override{
            int indice = h(key);
            ListLinked<TableEntry<V>>& lista = table[indice];
            for(int i=0; i<lista.size(); i++){
                if(lista[i].key == key){
                    V deleted = lista[i].value;
                    lista.remove(i);
                    n--;
                    return deleted;
                }
	    }
            throw runtime_error ("No se puede eliminar una clave inexistente\n");
        }


};


#endif



