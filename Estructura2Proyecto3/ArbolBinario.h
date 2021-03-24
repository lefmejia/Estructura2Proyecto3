#pragma once
#include <string>
#ifndef ARBOL_BINARIO_
#define ARBOL_BINARIO_
#include <vector>
using namespace std;

struct registro{
    int id;
    char name[30];
    char lastname[30];
    char credit_card[25];
    char date[12];
    short int day;
    short int month;
    short int year;
    char payment_type[10];
    double total;
    char business_type[20];
    char business_name[50];
};

struct repetidos {
    string name;
    vector<long> bytes;
};


class ArbolBinario
{
public:
        void cargarArbol();
        void busquedaSecuencial(string data, string name);
    class Node
    {
    public:
        Node(string data)
            : data(data), left(nullptr), right(nullptr),FactorEquilibrio(0),Altura(0),AlturaD(0),AlturaI(0),parent(nullptr)
        {}
        vector<repetidos> names;
        void print();
        void print2();
        string data;
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
    
    Node* buscar(string data);
    Node* buscarRec(string data, Node* raiz);
    Node* buscar2(string data, string name);
    Node* buscar2Rec(string data, string name, Node* raiz);
    void insert(long byte, string data, string nombre);
    void print();
    void printInOrder();
    void printInOrderRec(Node* raiz);
    void printPreOrder();
    void printPreOrderRec(Node* raiz);
    void printPostOrder();
    void printPostOrderRec(Node* raiz);
    void print2();
    void eliminar(string);
    int AlturaArbol() {return raiz != nullptr ? (raiz->AlturaD > raiz->AlturaI? raiz->AlturaD : raiz->AlturaI) : 0; }
        Node* raiz;


private:
    void insertRec(long byte, string data, string name, Node* root);
    bool eliminarRec(string, Node*);
    void reemplazarNodo(Node*, Node*);
    void printSubtree(Node* subtree, int depth, int level, bool first);
    int spacing(int level);
    void Balancear(Node*, int);
    void rotarD(Node*);
    void rotarI(Node*);
};
#endif // !ARBOL_BINARIO_
