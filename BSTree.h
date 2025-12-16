#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <stdexcept>
#include "BSNode.h"
#include "TableEntry.h"
using namespace std;

template<typename T>
class BSTree {
    private:
        int nelem; 
        BSNode<T>* root;
        
        BSNode<T>* search(BSNode<T>* n, T e){
            if(n == nullptr){
                throw runtime_error("No se encuentra el elemento");
            }else if(n->elem < e){
                return search(n->right, e);
            }else if(n->elem > e){
                return search(n->left, e);
            }else{
                return n;
            }
        }

        BSNode<T>* insert(BSNode<T>* n, T e){
            if(n == nullptr){
                nelem++;
                return new BSNode<T>(e);
            }else if(n->elem == e){
                throw runtime_error("Ya existe el elemento que se desea insertar");
            }else if(n->elem < e){
                n->right = insert(n->right, e);
            }else{
                n->left = insert(n->left, e);
            }
            return n;
        }

        void print_inorder(ostream &out, BSNode<T>* n)const{
            if(n != nullptr){
                print_inorder(out, n->left);
                out<<n->elem<<" ";
                print_inorder(out, n->right);
            }
        }

        T max(BSNode<T>* n)const{
            if(n == nullptr){
                throw runtime_error("El arbol esta vacio");
            }
            else if(n->right != nullptr){
                return max(n->right);
            }else{
                return n->elem;
            }
        }

        BSNode<T>* remove_max(BSNode<T>* n){
            if(n->right == nullptr){
                BSNode<T>* aux = n->left;
                delete n;
                nelem--;
                return aux;
            }else{
                n->right = remove_max(n->right);
                return n;
            }
        }

        BSNode<T>* remove(BSNode<T>* n, T e){
            if(n == nullptr){
                throw runtime_error("El arbol esta vacio");
            }else if(n->elem < e){
                n->right = remove(n->right, e);
            }else if(n->elem > e){
                n->left = remove(n->left, e);
            }else{
                if(n->left != nullptr && n->right != nullptr){
                    n->elem = max(n->left);
                    n->left = remove_max(n->left);
                }else{
                   BSNode<T>* toDelete = n;
                    n = (n->left != nullptr) ? n->left : n->right;
                    delete toDelete;
                    nelem--; 
                }
            }
            return n;
        }
        
        void delete_cascade(BSNode<T>* n){
            if(n != nullptr){
                delete_cascade(n->left);
                delete_cascade(n->right);
                delete n;
            }
        }
    
    public: 
        BSTree(){
            nelem = 0; 
            root = nullptr;
        }
        
        ~BSTree(){
            nelem = 0; 
            delete_cascade(root);
            root = nullptr;
        }

        int size()const{
            return nelem;
        }

        T search(T e){
            if(root == nullptr){
                throw runtime_error("El arbol esta vacio");
            }
            return search(root, e)->elem; 
        }

        T operator[](T e){
            return search(e);
        }

        void insert(T e){
            root = insert(root, e);
        }

        friend ostream& operator<<(ostream &out, const BSTree<T> &bst){
            bst.print_inorder(out, bst.root);
            return out;
        }

        void remove(T e){
            root = remove(root, e);
        }
};


#endif
