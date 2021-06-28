
#include "Conjunto.h"

template <class T>
Conjunto<T>::Conjunto(): _raiz(nullptr), _size(0){
    //lista de inicializacion
}

template <class T>
Conjunto<T>::~Conjunto() { 
    while (_raiz) {
        remover(_raiz->valor);
    }
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    if (_raiz != nullptr){
        return _raiz->pertenece(clave);
    } else {
        return false;
    }
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if (!pertenece(clave)) {
        if (!_raiz) {
            _raiz = new Nodo(clave);
        } else {
            _raiz->insertar(clave);
        }
        _size++;
    }
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    if (!_raiz) return;
    Nodo* actual = _raiz;
    string dir;                                         // que hijo es
    while (actual->valor != clave){                     // recorro el arbol
        if (clave < actual->valor) {
            if (actual->izq) {
                actual = actual->izq;
                dir = "izq";
            } else {
                return;
            }
        } else {
            if (actual->der){
                actual = actual->der;
                dir = "der";
            } else {
                return;
            }
        }
    }
    // Caso 0: borrar una hoja
    if (!(actual->izq || actual->der)) {
        if (actual->padre) {
            if (dir == "izq") {
                actual->padre->izq = nullptr;
            } else {
                actual->padre->der = nullptr;
            }
        } else {
            _raiz = nullptr;
        }
        delete(actual);
    }
    // Caso 1a: borrar un nodo con 1 hijo (derecho)
    else if (!actual->izq && actual->der) {
        if (actual->padre) {
            if (dir == "izq"){
                actual->padre->izq = actual->der;
                actual->der->padre = actual->padre;
            } else {
                actual->padre->der = actual->der;
                actual->der->padre = actual->padre;
            }
        } else {
            actual->der->padre = nullptr;
            _raiz = actual->der;
        }
        delete(actual);
    }
    // Caso 1b: borrar un nodo con 1 hijo (izquierdo)
    else if (actual->izq && !actual->der) {
        if (actual->padre) {
            if (dir == "izq"){
                actual->padre->izq = actual->izq;
                actual->izq->padre = actual->padre;
            } else {
                actual->padre->der = actual->izq;
                actual->izq->padre = actual->padre;
            }
        } else {
            actual->izq->padre = nullptr;
            _raiz = actual->izq;
        }
        delete(actual);
    }
    // Caso 2: borrar un nodo con 2 hijos
    else if (actual->izq && actual->der) {
        T temp = siguiente(clave);
        remover(temp);
        ++_size;
        actual->valor = temp;
    }
    --_size;
    /* caso raiz lo salvo aca por fiaca
     * Nodo* padre
     * algoritmo de busqueda -> nodo actual, padre
     * borrar (logica de los casos, delete)
     */
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    Nodo* actual = _raiz;
    while (actual->valor != clave) {
        if (clave < actual->valor) {
            if (actual->izq) actual = actual->izq;
        } else if (clave > actual->valor) {
            if (actual->der) actual = actual->der;
        }
    }
    if (actual->der) {
        Nodo *siguiente = actual->der;
        while (siguiente->izq) {
            siguiente = siguiente->izq;
        }
        return siguiente->valor;
    } else {
        return actual->padre->valor;
    }
}

template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo* actual = _raiz;
    while (actual->izq){
        actual = actual->izq;
    }
    return actual->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo* actual = _raiz;
    while (actual->der){
        actual = actual->der;
    }
    return actual->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return _size;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    cout << "[";
    if (_raiz) {
        T elem = minimo();
        while (elem < maximo()) {
            cout << elem << ", ";
            elem = siguiente(elem);
        }
        cout << elem;
    }
    cout << "]";
}

template<class T>
Conjunto<T>::Nodo::Nodo(const T &v): valor(v), izq(nullptr), der(nullptr), padre(nullptr) {
}

template <class T>
bool Conjunto<T>::Nodo::Nodo::pertenece(T v){
    if (valor == v) {
        return true;
    } else {
        if (v < valor){
            if (izq != nullptr){
                return izq->pertenece(v);
            } else {
                return false;
            }
        } else {
            if (der != nullptr){
                return der->pertenece(v);
            } else {
                return false;
            }
        }
    }
}

template<class T>
void Conjunto<T>::Nodo::insertar(const T &clave) {
    if (clave < valor) {
        if (!izq) {
            izq = new Nodo(clave);
            izq->padre = this;
        } else {
            izq->insertar(clave);
        }
    } else if (clave > valor) {
        if (!der){
            der = new Nodo(clave);
            der->padre = this;
        } else {
            der->insertar(clave);
        }
    }
}