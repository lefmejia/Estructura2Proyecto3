#include "ArbolBinario.h"
#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	ArbolBinario avl;
	int opcion = 0;
	avl.cargarArbol();
	string data;
	string name;

	do 
	{
		std::cout << "\n\n1. Buscar por Apellido\n"
			"2. Busqueda por Nombre y Apellido\n"
			"3. Imprimir Arbol InOrder\n"
			"4. Imprimir Arbol PreOrder\n"
			"5. Imprimir Arbol PostOrder\n"
			"6. Eliminar\n"
			"7. Altura del Arbol\n"
			"8. salir\n";
		std::cin >> opcion;

		switch (opcion)
		{
		case 1:
			std::cout << "Ingrese Apellido: ";
			std::cin >> data;
			avl.buscar(data);
			break;

		case 2:
			std::cout << "Ingrese nombre: ";
			std::cin >> name;
			std::cout << "Ingrese apellido: ";
			std::cin >> data;
			avl.busquedaSecuencial(data, name);
			break;

		case 3:
			std::cout << "...Imprimiendo...\n\n ";
			std::cout << '\n';
			avl.printInOrder();
			std::cout << '\n';
			std::cout << "\n\n...Fin de impresion...\n ";
			break;

		case 4:
			std::cout << "Imprimiendo...\n\n ";
			std::cout << '\n';
			avl.printPreOrder();
			std::cout << '\n';
			std::cout << "\n\n...Fin de impresion...\n ";
			break;

		case 5:
			std::cout << "Imprimiendo...\n\n ";
			std::cout << '\n';
			avl.printPostOrder();
			std::cout << '\n';
			std::cout << "\n\n...Fin de impresion...\n ";
			break;

		case 6: 
			std::cout << "Ingrese apellido: ";
			std::cin >> data;
			avl.eliminar(data);
			break;

		case 7:
			std::cout << "Altura del arbol: " << avl.AlturaArbol();
			break;

		default:
			break;
		}
	} while (opcion != 8);	
}