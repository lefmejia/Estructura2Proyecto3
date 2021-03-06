#pragma once
#ifndef ARBOL_BINARIO_
#define ARBOL_BINARIO_

class ArbolBinario
{
public:

    class Node
    {
    public:
        Node(int data)
            : data(data), left(nullptr), right(nullptr),FactorEquilibrio(0),Altura(0),AlturaD(0),AlturaI(0),parent(nullptr)
        {}
        void print();
        void print2();
        int data;
        Node* left;
        Node* right;
        Node* parent;
        int Altura;
        int AlturaD;
        int AlturaI;
        int FactorEquilibrio;

    };
    ArbolBinario()
        :raiz(nullptr) {}

    void insert(int data);
    void print();
    void print2();
    void eliminar(int);
    int AlturaArbol() {return raiz != nullptr ? (raiz->AlturaD > raiz->AlturaI? raiz->AlturaD : raiz->AlturaI) : 0; }
    

private:
    Node* raiz;
    void insertRec(int data, Node* root);
    bool eliminarRec(int, Node*);
    void reemplazarNodo(Node*, Node*);
    void printSubtree(Node* subtree, int depth, int level, bool first);
    int spacing(int level);
    void Balancear(Node*, int);
    void rotarD(Node*);
    void rotarI(Node*);
};
#endif // !ARBOL_BINARIO_
