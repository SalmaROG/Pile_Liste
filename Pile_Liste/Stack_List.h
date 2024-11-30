#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Node {
private:
    T data;            // Donnée du nœud
    Node<T>* next;     // Pointeur vers le nœud suivant

public:
    Node(T value);

    // Méthode pour accéder à la donnée
    T& getdata() {
        return data;
    }

    // Méthode pour accéder au prochain nœud
    Node<T>*& suivant() {
        return next;
    }
};

template <typename T>
Node<T>::Node(T value) : data(value), next(nullptr) {}

template <typename T>
class Stack_List {
private:
    Node<T>* sommet; // Pointeur vers le sommet de la pile
    int taille;      // Taille de la pile

public:
    Stack_List();
    bool EstVide() const;
    void Ajouter(T elem);
    void Supprimer();
    T Sommet() const;
    int Size() const;
    void Afficher() const;
    ~Stack_List();
};

template <typename T>
Stack_List<T>::Stack_List() : sommet(nullptr), taille(0) {}

template <typename T>
bool Stack_List<T>::EstVide() const {
    return (sommet == nullptr);
}

template <typename T>
void Stack_List<T>::Ajouter(T elem) {
    Node<T>* nouveau = new Node<T>(elem);
    nouveau->suivant() = sommet; // Accès au prochain nœud
    sommet = nouveau;
    taille++;  
}

template <typename T>
void Stack_List<T>::Supprimer() {
    if (EstVide()) {
        cout << "Erreur : Underflow ! La pile est vide." << endl;
        return;
    }
    Node<T>* temp = sommet;
    sommet = sommet->suivant(); // Accès au prochain nœud
    delete temp;
    taille--;
}

template <typename T>
T Stack_List<T>::Sommet() const {
    if (EstVide()) {
        throw runtime_error("Erreur : La pile est vide.");
    }
    return sommet->getdata(); // Accès à la donnée
}

template <typename T>
int Stack_List<T>::Size() const {
    return taille;
}

template <typename T>
void Stack_List<T>::Afficher() const {
    if (EstVide()) {
        cout << "La pile est vide." << endl;
        return;
    }
    cout << "Contenu de la pile : ";
    Node<T>* courant = sommet;
    while (courant != nullptr) {
        cout << courant->getdata() << " "; // Accès à la donnée
        courant = courant->suivant(); // Passer au prochain nœud
    }
    cout << endl;
}

template <typename T>
Stack_List<T>::~Stack_List() {
    while (!EstVide()) {
        Supprimer();
    }
}
