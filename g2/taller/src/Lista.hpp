#include "Lista.h"

Lista::Lista() : _first(nullptr), _longitud(0) {}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    Nodo* current = _first;
    while(current != nullptr){
        current = current->_next;
        delete(_first);
        _first = current;
    }
}

Lista& Lista::operator=(const Lista& aCopiar) {
    while (this->_longitud > 0){
        this->eliminar(0);
    }

    Nodo* current = aCopiar._first;

    while (current != nullptr){
        this->agregarAtras(current->_valor);
        current = current->_next;
    }

    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    Nodo* nuevo = new Nodo;
    nuevo->_valor = elem;
    nuevo->_next = _first;
    nuevo->_prev = nullptr;

    if (_first != nullptr) {_first->_prev = nuevo;}
    _first = nuevo;
    ++_longitud;
}

void Lista::agregarAtras(const int& elem) {
    Nodo* nuevo = new Nodo;
    nuevo->_valor = elem;
    nuevo->_next = nullptr;
    nuevo->_prev = nullptr;

    if (_first == nullptr) {
        _first = nuevo;
    } else {
        Nodo* current = _first;
        while(current->_next != nullptr){
            current = current->_next;
        }
        current->_next = nuevo;
        nuevo->_prev = current;
    }

    ++_longitud;
}

void Lista::eliminar(Nat i) {
    if (i < _longitud) {
        Nodo* current;
        current = _first;

        int j = 0;

        while(j < i){                                                               //recorre la lista
            current = current->_next;
            ++j;
        }

        if (current->_prev != nullptr) {
            current->_prev->_next = current->_next;
        } else {
            _first = current->_next;
        }
        if (current->_next != nullptr) {
            current->_next->_prev = current->_prev;
        }

        delete(current);

        --_longitud;
    }
}

int Lista::longitud() const {
    return _longitud;
}

const int& Lista::iesimo(Nat i) const {
    if (i < _longitud) {
        int j = 0;
        Nodo* current = _first;
        while (j < i){
            current = current->_next;
            j++;
        }
        return current->_valor;
    };
}

int& Lista::iesimo(Nat i) {
    if (i < _longitud) {
        int j = 0;
        Nodo* current = _first;
        while (j < i){
            current = current->_next;
            j++;
        }
        return current->_valor;
    }
}

void Lista::mostrar(ostream& o) {
    o << "Lista de enteros:" << endl;
    for (int i = 0; i < _longitud; ++i) {
        o << this->iesimo(i) << endl;
    }
    o << "======" << endl;
}
