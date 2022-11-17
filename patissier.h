
#ifndef PROJET_PATISSIER_PATISSIER_H
#define PROJET_PATISSIER_PATISSIER_H

typedef struct Element_str{
    char texte[50];
    struct Element_str* next;
}Element_str;

typedef struct Gateau{
    struct Element_str* commande;
    struct Pile_Gouts* p_gouts;
}Gateau;

typedef struct File_Commandes{
    struct Element_str* commande;
}File_Commandes;

typedef struct Pile_Gouts{
    Element_str* gout;
}Pile_Gouts;

typedef struct Element_gtx{
    struct Gateau* gateau;
    int parts;
    struct Element_gtx* next;
}Element_gtx;

typedef struct File_Degustation{
    struct Element_gtx* gateau;
}File_Degustation;

Element_str* creer_gout(char* gout);

Element_str* initialiser_gouts();

File_Commandes* init_file_commande();

void passer_commande(char commande[50], struct File_Commandes* f_commandes);

Element_str* traiter_commande(File_Commandes* f_commandes);

Gateau* creer_gateau(Element_str* commande);

void construire_gateau(Gateau* gateau, Element_str* l_gouts);

Pile_Gouts* init_pile_gout();

void ajouter_gout(Pile_Gouts* p_gout, char* gout);

File_Degustation* init_file_degustation();

void livrer(Gateau* gateau, File_Degustation* f_degustation);

void degustation(File_Degustation* f_degustation, int nb_parts);

void menu(File_Commandes* f_commandes, Element_str* l_gouts, File_Degustation* f_degustation);

void commander_gateau(File_Commandes* f_commandes, Element_str* l_gouts, File_Degustation* f_degustation);

void manger_gateau(File_Degustation* f_desgustation);


#endif //PROJET_PATISSIER_PATISSIER_H
