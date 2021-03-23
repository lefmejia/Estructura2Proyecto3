#include "ArbolBinario.h"
#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	ArbolBinario avl;
	int opcion=0;
	avl.cargarArbol();
	string data;
	string name;

	do 
	{
		std::cout << "\n\n1. Buscar por Apellido\n"
			"2. Busqueda por Nombre y Apellidol\n"
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
			avl.buscar2(data, name);
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

	/*avl.insert(10);
	avl.insert(4);
	avl.insert(14);
	avl.insert(2);
	avl.insert(5);
	avl.insert(12);
	avl.insert(15);
	avl.insert(30);*/
	/*avl.insert(45);
	avl.insert(70);
	avl.insert(35);
	avl.insert(3);
	avl.insert(74);
	avl.insert(25);
	avl.insert(81);
	avl.insert(60);*/
	/*std::vector<int> v{ 41,
		67,
		34,
		0,
		69,
		24,
		78,
		58,
		62,
		64,
		5,
		45,
		81,
		27,
		61,
		91,
		95,
		42,
		27,
		36,
		91,
		4,
		2,
		53,
		92,
		82,
		21,
		16,
		18,
		95,
		47,
		26,
		71,
		38,
		69,
		12,
		67,
		99,
		35,
		94,
		3,
		11,
		22,
		33,
		73,
		64,
		41,
		11,
		53,
		68
	};

	std::sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int n : v)
	{
		avl.insert(n);
	}*/
	/*avl.insert(14);
	avl.insert(10);
	avl.insert(8);
	avl.insert(25);
	avl.insert(15);
	avl.insert(30);
	avl.insert(8);
	avl.insert(12);
	avl.insert(9);
	avl.insert(13);
	avl.insert(26);
	avl.insert(31);
	avl.insert(7);
	avl.insert(11);
	avl.insert(18);
	avl.insert(19);
	avl.insert(21);
	avl.insert(1);
	avl.insert(2);
	avl.insert(3);
	avl.insert(44);
	avl.insert(33);
	avl.insert(54);
	avl.insert(38);
	avl.insert(55);
	avl.insert(56);
	avl.insert(57);*/

	//std::cout << avl.AlturaArbol()<<std::endl;
	//avl.print();
}