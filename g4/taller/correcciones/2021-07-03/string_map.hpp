
#include "string_map.h"

template <typename T>
string_map<T>::string_map() : _size(0), raiz(nullptr) {
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    vector<string> clavesABorrar = _claves;
    for (auto key : clavesABorrar) {
        erase(key);
    }
    for (auto key : d._claves) {
        insert(make_pair(key, d.at(key)));
    }
}

template <typename T>
string_map<T>::~string_map(){
    vector<string> clavesABorrar = _claves;
    for (auto key : clavesABorrar) {
        erase(key);
    }
}

template <typename T>
T& string_map<T>::operator[](const string& clave) {
    if (count(clave)) {
        return at(clave);
    } else {
        insert(make_pair(clave, T()));
        return at(clave);
    }
}

template <typename T>
int string_map<T>::count(const string& clave) const{
    int res = 0;
    Nodo* actual = raiz;
    if (!raiz) {
        return res;
    } else {
        int i = 0;
        int n = clave.size();
        while (actual) {                                    // mientras haya nodos siguientes, recorro el trie
            if (i == n && actual->definicion) {             // si estoy en la ultima letra y tiene definicion:
                res = 1;                                        // devuelvo 1
            }
            actual = actual->siguientes[int(clave[i])];     // accedo al nodo en la posicion asociada al codigo ASCII del char actual
            ++i;
        }
    }
    return res;                                             // si no encontre la definicion, devuelvo 0 por defecto
}


template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo* actual = raiz;
    int i = 0;
    int n = clave.size()-1;
    while (actual) {
        actual = actual->siguientes[int(clave[i])];
        if (i == n) {
            return *(actual->definicion);
        }
        ++i;
    }
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* actual = raiz;
    int i = 0;
    int n = clave.size()-1;
    while (actual) {
        actual = actual->siguientes[int(clave[i])];
        if (i == n) {
            return *(actual->definicion);
        }
        ++i;
    }
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    int n = clave.size();
    Nodo* actual = raiz;
    vector<Nodo*> nodos_clave;
    nodos_clave.push_back(raiz);
    for (int i = 0; i < n; ++i) {
        actual = actual->siguientes[int(clave[i])];
        nodos_clave.push_back(actual);
    }
    delete(actual->definicion);
    actual->definicion = nullptr;
    int i = n;
    while(!actual->definicion && actual->sinSiguientes() && nodos_clave.size() > 1) {
        Nodo* aBorrar = actual;
        nodos_clave.pop_back();
        actual = nodos_clave.back();
        delete(aBorrar);
        --i;
        actual->siguientes[int(clave[i])] = nullptr;
    }
    if (raiz->sinSiguientes()){
        delete(raiz);
        raiz = nullptr;
    }
    --_size;
    int a_borrar;
    for (int j = 0; j < _claves.size(); ++j) {
        if (_claves[j] == clave) a_borrar = j;
    }
    _claves.erase(_claves.begin()+a_borrar);
}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    if (!raiz) {
        return true;
    } else {
        return false;
    }
}

template<typename T>
void string_map<T>::insert(const pair<string, T>& value_type) {                       // todo acordate de updatear _size y _claves
    string clave = value_type.first;
    T def = value_type.second;
    if (!raiz) {
        raiz = new Nodo();
    }
    Nodo* actual = raiz;
    int i = 0;
    while (actual->siguientes[int(clave[i])]) {
        actual = actual->siguientes[int(clave[i])];
        i++;
    }
    while (i < clave.size()) {
        actual->siguientes[int(clave[i])] = new Nodo();
        actual = actual->siguientes[int(clave[i])];
        i++;
    }
    if (!count(clave)) {
        _size++;
        _claves.push_back(clave);
    }
    if (actual->definicion) delete(actual->definicion);
    actual->definicion = new T(def); // esto es raro
}

template<typename T>
const vector<string> string_map<T>::claves() const {
    return _claves;
}

// Nodo

template <typename T>
string_map<T>::Nodo::Nodo() : siguientes(127, nullptr), definicion(nullptr){}

template<typename T>
bool string_map<T>::Nodo::sinSiguientes() {
    bool res = true;
    for (auto hijo : siguientes) {
        if (hijo) res = false;
    }
    return res;
}
