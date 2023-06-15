#ifndef ARBOLBINARIOBUSQUEDA_H
#define ARBOLBINARIOBUSQUEDA_H

#include <iostream>

template<typename T>
class Nodo{

	public:
		T valor;
		Nodo<T> *izq;
		Nodo<T> *der;
		Nodo<T> *padre;
		Nodo<T>(T valor);              // Constructor valor raiz
		Nodo<T>(T valor, Nodo<T> *padre); // Constructor nodo no raiz
		~Nodo();                      // Destructor
};

template<typename T>
class ArbolBinarioBusqueda{
	public:
		ArbolBinarioBusqueda();       // Constructor
		~ArbolBinarioBusqueda();      // Destructor
		bool insertar(T valor);     // No acepta valores repetidos
		Nodo<T> *buscar(T valor);      // Si no existe, return null
		void inOrder();

	private:
		Nodo<T> *raiz;                            // ptr a primer nodo
		bool insertar(T valor, Nodo<T> *n);      // Insertar un nodo en el nodo *n
		Nodo<T> *buscar(T valor, Nodo<T> *n);       // Buscar valor en el nodo *n
		void inOrder(Nodo<T> *n);                  // Recorrido inOrder desde el nodo *n
		Nodo<T> *mayor(Nodo<T> *n);                   // Retorna el nodo de mayor valor
};

#endif