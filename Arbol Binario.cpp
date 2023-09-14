#include <iostream>
#include <string>

struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int val) : valor(val), izquierdo(nullptr), derecho(nullptr) {}
};

Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == nullptr) {
        return new Nodo(valor);
    }

    if (valor < raiz->valor) {
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    }
    else if (valor > raiz->valor) {
        raiz->derecho = insertar(raiz->derecho, valor);
    }

    return raiz;
}

void imprimirEnOrden(Nodo* raiz) {
    if (raiz != nullptr) {
        imprimirEnOrden(raiz->derecho);
        std::cout << raiz->valor << " ";
        imprimirEnOrden(raiz->izquierdo);
    }
}

int main() {
    Nodo* raiz = nullptr;
    int valor;

    std::cout << "Ingrese números para construir el árbol binario (ingrese 'q' para salir):" << std::endl;

    while (true) {
        std::string entrada;
        std::cin >> entrada;

        if (entrada == "q") {
            break; // Salir del bucle si se ingresa "q"
        }
	
	        valor = std::stoi(entrada);
	
	        raiz = insertar(raiz, valor);
	    }
	
	    std::cout << "Árbol binario de mayor a menor: ";
	    imprimirEnOrden(raiz);
	    std::cout << std::endl;

    return 0;
}
