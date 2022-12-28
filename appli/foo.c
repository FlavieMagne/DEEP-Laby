/*
 * foo.c - ce fichier contient des choses absolument inutiles... sauf � des fins purement p�dagogiques.
 *
 *  Created on: 26 ao�t 2015
 *      Author: S. Poiraud
 */
#include "macro_types.h"
#include "stdint.h"

void Fonction_montrant_l_utilisation_de_la_memoire (void)
{
	typedef struct
	{
		char * prenom;				//4 Un pointeur vers une chaine plac�e ailleurs
		char nom[10];				//10 Un tableau de caract�re pour une chaine stock�e ici
		uint8_t age;				//1 Un �ge de 0 � 255
		int32_t compte_en_banque;	//4 Un nombre allant d'un tr�s gros d�couvert � une tr�s grande richesse
	}bank_user_t;

	static bank_user_t user1 = {"marcel", {'P','R','O','U','S','T','\0'}, 144, 1000000};
	static bank_user_t user2 = {"bill", {'G','4','T','3','$','\0'}, 144, 792000000};
	static bank_user_t user3 = {"�trange", {'0',0,0x00,1,'\0',3.14}, -10, -3000000000};		//vous remarquerez que cette ligne provoque un warning � la compilation, c'est pas pour du beurre !
	volatile bank_user_t * puser1, * puser2, * puser3;
	puser1 = &user1;
	puser2 = &user2;
	puser3 = &user3;

	//Observez ces structures en m�moires :
		//1- via l'onglet "expression"
		//2- via l'onglet "variables"
		//3- via l'onglet Memory
}
