#include "arbolBinarioBusqueda.hpp"

// ---- Metodos Clase Nodo ---- //

// Constructor nodo raiz

template<typename T>
Nodo<T>::Nodo(T valor){   // O(1)

	izq = NULL;
	der = NULL;
	padre = NULL;
	this -> valor = valor;
}


// Constructor Nodo no raiz
template<typename T>
Nodo<T>::Nodo(T valor, Nodo<T> *padre){   // O(1)

	izq = NULL;
	der = NULL;
	this -> padre = padre;
	this -> valor = valor;
}

// Destructor
template<typename T>
Nodo<T>::~Nodo(){      // O(1)

	delete izq;
	delete der;
}



// ---- Metodos Clase ArbolBinarioBusqueda ---- //

// Constructor
template<typename T>
ArbolBinarioBusqueda<T>::ArbolBinarioBusqueda(){   // O(1)
	raiz = NULL;
}

// Destructor
template<typename T>
ArbolBinarioBusqueda<T>::~ArbolBinarioBusqueda(){   // O(1)
	// Eliminar todos los nodos hacia abajo (implementar, soy flojo)
	delete raiz;
}

// Publico: Insertar un valor en el arbol
template<typename T>
bool ArbolBinarioBusqueda<T>::insertar(T valor){     // O(log(n))

	if(raiz == NULL){
		raiz = new Nodo<T>(valor);
		return true;
	}

	return insertar(valor, raiz);
}

// Privado: Insertar un nodo no raiz solo si n !=NULL
template<typename T>
bool ArbolBinarioBusqueda<T>::insertar(T valor, Nodo<T> *n){   // O(log(n))

	// ---- Caso base principal
	// Si el valor está repetido, no se inserta el nodo
	if(valor == n -> valor){
		return false;
	}

	// Si el valor a insertar es menor al del nodo, hacia la izquierda
	if(valor < n -> valor){

		// Si el hijo izquierdo esta vacio, insertar
		if(n -> izq == NULL){
			n -> izq = new Nodo<T>(valor, n);
			return true;
		}

		// Si no está vacio, bajar a la izquierda e intentar insertar
		return insertar(valor, n -> izq);
	}

	// Si el valor a insertar es mayor al del nodo, hacia la derecha
	if(n -> der == NULL){
		n -> der = new Nodo<T>(valor, n);
		return true;
	}

	return insertar(valor, n -> der);
}


// Public: busca el valor en el arbol, retorna NULL si no existe
template<typename T>
Nodo<T> *ArbolBinarioBusqueda<T>::buscar(T valor){       // O(log(n))
	
	return buscar(valor, raiz);
}


// Private: busca el valor en un nodo, si no es, baja hasta llegar a una hoja
template<typename T>
Nodo<T> *ArbolBinarioBusqueda<T>::buscar(T valor, Nodo<T> *n){    // O(log(n))

	// ---- Casos Base ---- //
	
	// Si es una hoja o raiz, el valor no existe
	if(n == NULL)
		return NULL; 
	
	// Si encontramos el valor, retornar direccion del nodo
	if(n -> valor == valor)
		return n;

	// ---- Casos Recursivos ---- //
	if(valor < n -> valor)
		return buscar(valor, n -> izq);

	return buscar(valor, n -> der);
} 

// Public: Imprimir arbol inOrder
template<typename T>
void ArbolBinarioBusqueda<T>::inOrder(){    // O(n)

	std::cout << "In Order:" << std::endl;
	inOrder(raiz);
	std::cout << std::endl;
}

// Private: Imprimir nodo inOrder
template<typename T>
void ArbolBinarioBusqueda<T>::inOrder(Nodo<T> *n){  // O(n)
	
	// ---- Caso Base
	// Si llegamos a una hoja, no seguir bajando
	if(n == NULL)
		return;
	inOrder(n -> izq);
	std::cout << n -> valor << " ";
	inOrder(n -> der);
}


// Public: Retorna el nodo mayor del arbol (analogo para el menor)
template<typename T>
Nodo<T> *ArbolBinarioBusqueda<T>::mayor(Nodo<T>* n){    // O(log(n))

	if(n == NULL)
		return NULL;

	Nodo<T> *iterador = n;
	while(iterador -> der != NULL)
		iterador = iterador -> der;

	return iterador;
}
