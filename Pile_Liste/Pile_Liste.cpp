#include <iostream>
#include"Stack_List.h"
int main()
{
    Stack_List<int>maPile;
    maPile.Ajouter(4);
    maPile.Ajouter(3);
    maPile.Ajouter(2);
    maPile.Ajouter(1);
    cout << "Les elements de la pile sont:\n";
    maPile.Afficher();
    maPile.Supprimer();
    cout << "Les elements de la pile apres la suppression sont:\n";
    maPile.Afficher();
    cout <<"le sommet de la pile est:" << maPile.Sommet() << endl;
    
}

