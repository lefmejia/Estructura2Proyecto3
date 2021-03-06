#include "ArbolBinario.h"
#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	ArbolBinario avl;
	int opcion=0;
	int numero;
	do 
	{
		std::cout << "1. Insertar\n2. Altura del arbol\n3. Imprimir Arbol\n4. Eliminar\n5. Salir\n";
		std::cin >> opcion;

		switch (opcion)
		{
		case 1:
			std::cout << "Numero: ";
			std::cin >> numero;
			avl.insert(numero);
			break;
		case 2:
			std::cout<<"Altura del arbol: " << avl.AlturaArbol();
			break;
		case 3:
			std::cout << '\n';
			avl.print();
			std::cout << '\n';
			break;
		case 4:
			std::cout << "Numero: ";
			std::cin >> numero;
			avl.eliminar(numero);
			break;
		default:
			break;
		}
	} while (opcion != 5);

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