#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "annuaire.h"

t_pers *ajouterEnTete(t_pers *liste, char nom[], char prenom[], char* tel)
{
    /* On cr�e un nouvel �l�ment */
    t_pers* nouvelElement = malloc(sizeof(t_pers));

    /* On assigne la valeur au nouvel �l�ment */
    nouvelElement->nom = strdup(nom);
    nouvelElement->prenom = strdup(prenom);
    nouvelElement->tel = strdup(tel);

    /* On assigne l'adresse de l'�l�ment suivant au nouvel �l�ment */
    nouvelElement->nxt = liste;

    /* On retourne la nouvelle liste, i.e. le pointeur sur le premier �l�ment */
    return nouvelElement;
}

t_pers *ajouterEnFin(t_pers *liste, char *nom, char *prenom, char* tel)
{
    /* On cr�e un nouvel �l�ment */
    t_pers* temp=liste;
    t_pers* nouvelElement = malloc(sizeof(t_pers));

    /* On assigne la valeur au nouvel �l�ment */
    nouvelElement->nom = strdup(nom);
    nouvelElement->prenom = strdup(prenom);
    nouvelElement->tel = strdup(tel);
    /* On ajoute en fin, donc aucun �l�ment ne va suivre */
    nouvelElement->nxt = NULL;

    if(liste == NULL)
    {
        /* Si la liste est vide� il suffit de renvoyer l'�l�ment cr�� */
        return nouvelElement;
    }
    else
    {
        /* Sinon, on parcourt la liste � l'aide d'un pointeur temporaire et on
        indique que le dernier �l�ment de la liste est reli� au nouvel �l�ment */
        while(temp->nxt != NULL)
        {
            temp = temp->nxt;
        }
        temp->nxt = nouvelElement;
        return liste;
    }
}

t_pers *ajout_element(t_pers *liste, char *nom, char *prenom, char* tel)

{
    int i = 0;
    t_pers* temp = liste;
    t_pers* nouvelElement = malloc(sizeof(t_pers));
    t_pers* tmp = liste;

    nouvelElement->nom = strdup(nom);
    nouvelElement->prenom = strdup(prenom);
    nouvelElement->tel = strdup(tel);
    nouvelElement->nxt = NULL;
    if(liste == NULL)
        return nouvelElement;
    else
    {
        while(temp->nxt != NULL && nouvelElement->nom[i] >= temp->nxt->nom[i])
        {
            while (nouvelElement->nom[i] == temp->nom[i] && nouvelElement->nom[i] != 0 && temp->nom[i] != 0)
                i++;
            if (nouvelElement->nom[i] > temp->nom[i])
            {
                temp = temp->nxt;
                tmp = tmp->nxt;
            }
        }
        temp = temp->nxt;
        nouvelElement->nxt = temp;
        tmp->nxt = nouvelElement;
    }
    return liste;
}
