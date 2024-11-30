#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Node {
private:
    T data;            // Donn�e du n�ud
    Node<T>* next;     // Pointeur vers le n�ud suivant

public:
    Node(T value);

    // M�thode pour acc�der � la donn�e
    T& getdata() {
        return data;
    }

    // M�thode pour acc�der au prochain n�ud
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
    nouveau->suivant() = sommet; // Acc�s au prochain n�ud
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
    sommet = sommet->suivant(); // Acc�s au prochain n�ud
    delete temp;
    taille--;
}

template <typename T>
T Stack_List<T>::Sommet() const {
    if (EstVide()) {
        throw runtime_error("Erreur : La pile est vide.");
    }
    return sommet->getdata(); // Acc�s � la donn�e
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
        cout << courant->getdata() << " "; // Acc�s � la donn�e
        courant = courant->suivant(); // Passer au prochain n�ud
    }
    cout << endl;
}

template <typename T>
Stack_List<T>::~Stack_List() {
    while (!EstVide()) {
        Supprimer();
    }
}
