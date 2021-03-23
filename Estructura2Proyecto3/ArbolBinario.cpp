#include "ArbolBinario.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>

using namespace std;

void ArbolBinario::cargarArbol() {
    fstream archivo("datab_jc.dat", ios::in|ios::binary);
    if (!archivo) {
        cout << "No se pudo abrir el archivo.";
            return;
    }
    registro aux;

    for (int i = 0; i < 3;i++) {
        archivo.read(reinterpret_cast<char*>(&aux), sizeof(registro));
        insert(aux.lastname, aux.name);
    }
    archivo.close();
}

void ArbolBinario::print2()
{
    raiz->print();
    std::cout << '\n';
}

ArbolBinario::Node* ArbolBinario::buscar(string data) {
    return buscarRec(data, raiz);
}

ArbolBinario::Node* ArbolBinario::buscarRec(string data, Node* raiz) {
    if (raiz) {
        if (data == raiz->data) {
            cout << "El elemento fue encontrado - " << data;
            return raiz;
        }
        else if (data < raiz->data) {
            return buscarRec(data, raiz->left);
        }
        else {
            return buscarRec(data, raiz->right);
        }
    }
    return nullptr;
}

ArbolBinario::Node* ArbolBinario::buscar2(string data, string name) {
    return buscar2Rec(data, name, raiz);
}

ArbolBinario::Node* ArbolBinario::buscar2Rec(string data, string name, Node* raiz) {
    if (raiz) {
        if (data == raiz->data) {
            cout << "El elemento fue encontrado - " << data;
            for (string i : raiz->names) {
                if (i == name) {
                    cout << "Elemento encontrado!";
                    break;
                }
            }
            return raiz;
        }
        else if (data < raiz->data) {
            return buscarRec(data, raiz->left);
        }
        else {
            return buscarRec(data, raiz->right);
        }
    }
}
void ArbolBinario::Node::print()
{
    std::cout << data << '\n';

    if (left != nullptr || right != nullptr)
    {
        std::cout << "{";
        if (left != nullptr)
        {
            left->print();
        }
        if (right != nullptr)
        {
            right->print();
        }

        std::cout << '}';
    }

    //std::cout<< data <<'\n';
}

void ArbolBinario::Node::print2()
{
    if (left != nullptr)
        left->print2();

    std::cout << data << ' ';

    if (right != nullptr)
        right->print2();

    //std::cout<< data <<'\n';
}


void ArbolBinario::insert(string data, string name)
{
    if (raiz == nullptr)
    {
        raiz = new Node(data);
        cout << "Nodo agregado\n";
        return;
    }

    insertRec(data, name, raiz);
    raiz->Altura = (raiz->AlturaD >= raiz->AlturaI ? raiz->AlturaD : raiz->AlturaI) + 1;
}


void ArbolBinario::insertRec(string data, string name, Node* root)
{

    if (strcmp(root->data.c_str() ,data.c_str()) == 0) {
        root->names.push_back(name);
        return;
    }

    if (strcmp(data.c_str() , root->data.c_str()) < 0)
    {
        if (root->left == nullptr)
        {
            cout << "Nodo agregado\n";
            root->names.push_back(name);
            root->left = new Node(data);
            root->left->parent = root;
            root->AlturaI++;
            root->Altura = root->AlturaD >= root->AlturaI ? root->AlturaD : root->AlturaI;
            return;
        }
        else
        {
            insertRec(data, name, root->left);
            root->AlturaI = root->left->Altura + 1;
            root->FactorEquilibrio = root->AlturaD - root->AlturaI;
            if (root->FactorEquilibrio < -1 || root->FactorEquilibrio>1)
            {
                Balancear(root, root->FactorEquilibrio);

            }
        }
    }
    
    else
    {
        if (root->right == nullptr)
        {
            cout << "nodo agregado\n" ;
            root->names.push_back(name);
            root->right = new Node(data);
            root->right->parent = root;
            root->AlturaD++;
            root->Altura = root->AlturaD >= root->AlturaI ? root->AlturaD : root->AlturaI;
            return;
        }
        else
        {
            insertRec(data,name, root->right);
            root->AlturaD = root->right->Altura + 1;
            root->FactorEquilibrio = root->AlturaD - root->AlturaI;
            if (root->FactorEquilibrio < -1 || root->FactorEquilibrio>1)
            {
                Balancear(root, root->FactorEquilibrio);
                
            }
        }
    }

    if (root->right != nullptr)
        root->AlturaD = root->right->Altura + 1;

    if (root->left != nullptr)
        root->AlturaI = root->left->Altura + 1;

    root->Altura = root->AlturaD >= root->AlturaI ? root->AlturaD : root->AlturaI;
}

void ArbolBinario::Balancear(Node* root, int FE)
{
    if (FE < -1)
    {
        if (root->left->right != nullptr)
        {
            root->AlturaI = 0;
            root->AlturaD = 0;
            root->Altura = 0;
            //root->left->AlturaI = 1;
            root->left->AlturaD = 0;
            //root->left->Altura = 1;
            root->left->right->AlturaD = 1;
            root->left->right->AlturaI = 1;
            root->left->right->Altura = 1;
            rotarI(root->left);
            rotarD(root);
            root->parent->left->Altura = root->parent->left->AlturaD > root->parent->left->AlturaI ? root->parent->left->AlturaD : root->parent->left->AlturaI;
            root->parent->left->FactorEquilibrio = root->parent->left->AlturaD - root->parent->left->AlturaI;
            if (root->parent->left->FactorEquilibrio < -1)
            {
                Balancear(root->parent->left, root->parent->left->FactorEquilibrio);
            }
        }
        else if (root->left->left != nullptr)
        {
            root->AlturaI = 0;
            root->AlturaD = 0;
            root->Altura = 0;
            //root->left->AlturaI += 0;
            root->left->AlturaD = 1;
            root->left->Altura = root->left->AlturaD > root->left->AlturaI ? root->left->AlturaD : root->left->AlturaI;
            rotarD(root);
        }
    }
    else if (FE > 1)
    {
        if (root->right->left != nullptr)
        {
            root->AlturaI = 0;
            root->AlturaD = 0;
            root->Altura = 0;
            root->right->AlturaI = 0;
            //root->right->AlturaD = 1;
            //root->right->Altura = 1;
            root->right->left->Altura = 1;
            root->right->left->AlturaD = 1;
            root->right->left->AlturaI = 1;
            rotarD(root->right);
            rotarI(root);
            root->parent->right->Altura = root->parent->right->AlturaD > root->parent->right->AlturaI ? root->parent->right->AlturaD : root->parent->right->AlturaI;
            root->parent->right->FactorEquilibrio = root->parent->right->AlturaD - root->parent->right->AlturaI;
            if (root->parent->right->FactorEquilibrio > 1)
            {
                Balancear(root->parent->right, root->parent->right->FactorEquilibrio);
            }
        }
        else if (root->right->right != nullptr)
        {
            root->AlturaI = 0;
            root->AlturaD = 0;
            root->Altura = 0;
            root->right->AlturaI = 1;
            //root->right->AlturaD = 0;
            root->right->Altura = root->right->AlturaD > root->right->AlturaI ? root->right->AlturaD : root->right->AlturaI;
            rotarI(root);
        }
    }
}

void ArbolBinario::rotarD(Node* root)
{
    if (root == raiz)
    {
        Node* nuevo = root->left;
        root->left = nuevo->right;
        root->parent = nuevo;
        if (nuevo->right != nullptr)
            nuevo->right->parent = root;
        nuevo->right = root;
        nuevo->parent = nullptr;
        raiz = nuevo;
    }
    else
    {
        Node* nuevo = root->left;
        nuevo->parent = root->parent;
        root->left = nuevo->right;
        if (nuevo->right != nullptr)
            nuevo->right->parent = root;
        nuevo->right = root;

        if (root->parent->data < nuevo->data)
            root->parent->right = nuevo;
        else
            root->parent->left = nuevo;


        root->parent = nuevo;

    }
    
}

void ArbolBinario::rotarI(Node* root)
{
    if (root == raiz)
    {
        Node* nuevo = root->right;
        root->right = nuevo->left;
        root->parent = nuevo;
        if (nuevo->left != nullptr)
            nuevo->left->parent = root;
        nuevo->left = root;
        nuevo->parent = nullptr;
        raiz = nuevo;
    }
    else
    {
        Node* nuevo = root->right;
        nuevo->parent = root->parent;
        root->right = nuevo->left;
        if (nuevo->left != nullptr)
            nuevo->left->parent = root;
        nuevo->left = root;
        
        if (root->parent->data < nuevo->data)
            root->parent->right = nuevo;
        else
            root->parent->left = nuevo;
        
        root->parent = nuevo;
    }
}

void ArbolBinario::eliminar(string data)
{
    if (!raiz) {
        cout << "El arbol esta vacio!";
        return;
    }
    eliminarRec(data, raiz);
}

bool ArbolBinario::eliminarRec(string data, Node* root)
{
    if (strcmp(data.c_str(), root->data.c_str())== 0)
    {
        
        
        if (root->left == nullptr && root->right == nullptr)
        {
            reemplazarNodo(root, nullptr);

        }
        else if (root->left != nullptr)
        {
            Node* temp = root->left;
            while (temp->right != nullptr)
                temp = temp->right;

            reemplazarNodo(root, temp);
        }
        else if(root->right != nullptr)
        {
            reemplazarNodo(root, root->right);
        }

        return true;
    }
    else if (data < root->data)
    {
        if(root->left!=nullptr)
            if (eliminarRec(data, root->left))
            {
                root->AlturaI--;
                root->Altura = root->AlturaD >= root->AlturaI ? root->AlturaD : root->AlturaI;
                root->FactorEquilibrio = root->AlturaD - root->AlturaI;
                if (root->FactorEquilibrio < -1 || root->FactorEquilibrio>1)
                {
                    Balancear(root, root->FactorEquilibrio);

                }
            }
        else
        {
            std::cout << "Numero no existe\n";
            return false;
        }
    }
    else
    {
        if(root->right!=nullptr)
            if (eliminarRec(data, root->right))
            {
                root->AlturaD--;
                root->Altura = root->AlturaD >= root->AlturaI ? root->AlturaD : root->AlturaI;
                root->FactorEquilibrio = root->AlturaD - root->AlturaI;
                if (root->FactorEquilibrio < -1 || root->FactorEquilibrio>1)
                {
                    Balancear(root, root->FactorEquilibrio);

                }
            }
        else
        {
            std::cout << "Numero no existe\n";
            return false;
        }
    }
}

void ArbolBinario::reemplazarNodo(Node* root, Node* reemplazo)
{
    if (root == raiz)
    {
        raiz = reemplazo;
    }
    else if (root->parent->data > root->data)
        root->parent->left = reemplazo;
    else
        root->parent->right = reemplazo;

    if (reemplazo == nullptr)
        return;
    else
        reemplazo->parent = root->parent;

    if (reemplazo->left != nullptr)
    {
        Node* nuevo = reemplazo->left;
        while (nuevo->right != nullptr)
            nuevo = nuevo->right;

        reemplazo->right = root->right;
        reemplazo->left = root->left;
        /*reemplazo->AlturaD = reemplazo->right->Altura;
        reemplazo->AlturaI = reemplazo->left->Altura;
        reemplazo->Altura = reemplazo->AlturaD > reemplazo->AlturaI ? reemplazo->AlturaD : reemplazo->AlturaI;
        reemplazo->FactorEquilibrio = reemplazo->AlturaD - reemplazo->AlturaI;
        Balancear(reemplazo, reemplazo->FactorEquilibrio);*/
        reemplazarNodo(reemplazo, nuevo);
    }
    else if (reemplazo->right != nullptr)
    {
        Node* nuevo = reemplazo->right;
        reemplazo->right = root->right;
        reemplazo->left = root->left;
        /*reemplazo->AlturaD = reemplazo->right->Altura;
        reemplazo->AlturaI = reemplazo->left->Altura;
        reemplazo->Altura = reemplazo->AlturaD > reemplazo->AlturaI ? reemplazo->AlturaD : reemplazo->AlturaI;
        reemplazo->FactorEquilibrio = reemplazo->AlturaD - reemplazo->AlturaI;
        Balancear(reemplazo, reemplazo->FactorEquilibrio);*/
        reemplazarNodo(reemplazo, nuevo);
    }

}

void ArbolBinario::print()
{
    // raiz->print();
    // std::cout << '\n';
    if (raiz == nullptr)
    {
        std::cout << "Arbol vacio!" <<
            std::endl;
    }
    /* else if (raiz->Altura > 4)
         std::cout << "Not currently supported!" <<
         std::endl;*/

    else {
        int max = raiz->Altura;
        for (int depth = 0; depth <= max; depth++) {
            printSubtree(raiz, depth, max - depth + 1, true);
            std::cout << std::endl;
        }
    }
}

void ArbolBinario::printInOrder() {
    if (!raiz) {
        cout << "El arbol esta vacio!";
        return;
    }
    printInOrderRec(raiz);
    cout << "\n";
}

void ArbolBinario::printInOrderRec(Node* raiz) {
    if (!raiz) {
        return;
    }
    else {
        printInOrderRec(raiz->left);
        cout << raiz->data <<" ";
        printInOrderRec(raiz->right);
    }
}

void ArbolBinario::printPreOrder() {
    if (!raiz) {
        cout << "El arbol esta vacio!";
        return;
    }
        printPreOrderRec(raiz);
        cout << "\n";
}

void ArbolBinario::printPreOrderRec(Node* raiz) {
    if (!raiz) {
        return;
    }
    else {
        cout << raiz->data << " ";
        printPreOrderRec(raiz->left);
        printPreOrderRec(raiz->right);
    }
}

void ArbolBinario::printPostOrder() {
    if (!raiz) {
        cout << "El arbol esta vacio!";
        return;
    }
    printPostOrderRec(raiz);
    cout << "\n";
}

void ArbolBinario::printPostOrderRec(Node* raiz) {
    if (!raiz) {
        return;
    }
    else {
        printPostOrderRec(raiz->left);
        printPostOrderRec(raiz->right);
        cout << raiz->data << " ";
    }
}

void ArbolBinario::printSubtree(Node* subtree, int depth, int level, bool first) {

    if (depth > 0) {
        if (subtree == nullptr) {
            printSubtree(subtree, depth - 1, level, first);
            printSubtree(subtree, depth - 1, level, false);
        }
        else {
            printSubtree(subtree->left, depth - 1,
                level, first);
            printSubtree(subtree->right, depth - 1,
                level, false);
        }
    }
    else if (subtree == nullptr)
        std::cout << std::setw((first) ?
            spacing(level) / 2 : spacing(level)) << "-";

    else
        std::cout << std::setw((first) ?
            spacing(level) / 2 : spacing(level)) <<
        subtree->data;

}

int ArbolBinario::spacing(int level) {
    int result = 3;
    for (int i = 0; i < level; i++)
        result += result;
    return result/2;
}