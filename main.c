#include <stdio.h>
#include <malloc.h>
#include "patissier.h"


int main() {
    Element_str* l_gouts = initialiser_gouts();
    File_Commandes* f_commandes = init_file_commande();
    File_Degustation* f_degusation = init_file_degustation();
    menu(f_commandes,l_gouts,f_degusation);
    return 0;
}

void menu(File_Commandes* f_commandes, Element_str* l_gouts, File_Degustation* f_degustation){
    /*
     * fonction permettant à l'utilisateur de rentrer ses choix de commandes et de dégustations
     * argument : pointeur vers la file de commande, pointeur vers le goût, pointeur vers la file de dégustation
     */
    int menu = 1;
    while (menu) {
        int action;
        while (action != 1 && action != 2 && action != 3){
            printf(" \n"
                   "1 : Commander un gateau \n"
                   "2 : Manger un gateau \n"
                   "3 : Quitter\n");
            scanf("%d", &action);
        }

        switch (action) {

            case 1:
                commander_gateau(f_commandes,l_gouts,f_degustation);
                action = 0;
                break;

            case 2:
                manger_gateau(f_degustation);
                action = 0;
                break;
            case 3:
                menu = 0;
                action = 0;
                break;

        }
    }
}

void commander_gateau(File_Commandes* f_commandes, Element_str* l_gouts, File_Degustation* f_degustation){
    /*
     * fonction permettant à l'utilisateur de rentrer ses choix de goûts
     * argument : pointeur vers la file de commande, pointeur vers le goût, pointeur vers la file de dégustation
     */
    char gouts[50];

    printf("Quel(s) gout(s) aimeriez vous ? Saisissez les initiales correspondantes \n\n"
               " Chocolat : C \n Vanille : V \n Fraise : F \n Abricot : A \n Pomme : P \n Banane : B \n Myrtille : M\n");
    scanf("%s", gouts);
    passer_commande(gouts,f_commandes);
    Gateau* gateau = creer_gateau(traiter_commande(f_commandes));
    construire_gateau(gateau,l_gouts);
    livrer(gateau, f_degustation);
}

void manger_gateau(File_Degustation* f_desgustation){
    /*
     * fonction permettant à l'utilisateur de rentrer le nombre de parts souhaité
     * argument : pointeur vers la file de dégustation
     */
    int parts = -1;
    while (parts < 0 || parts > 20){
        printf("Entrez le nombre de parts que vous souhaiteriez manger \n");
        scanf("%d", &parts);
    }
    degustation(f_desgustation,parts);

}