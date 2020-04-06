#include <stdio.h>
#include <stdalign.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "test.h"
#include <assert.h>
#include <errno.h>
#include <inttypes.h>

typedef enum{
	false,
	true
} Bool;
typedef struct Element Element;
struct Element {
	int val;
	struct Element *suivant;
};

typedef struct Pile Pile;
struct Pile{
	struct Element *premier;
};

Pile *initialiser(void){
   Pile *pile = malloc(sizeof(*pile));
   pile->premier = NULL;
   return pile;
}

Bool pile_estvide(Pile *pile){
	if (!(pile->premier) ) {
		return true;
	}

	return false;
}
void empiler(Pile *pile, int val){
	Element *noeud = malloc(sizeof(*noeud));

	if (pile == NULL || noeud == NULL){
		fprintf(stderr, "Erreur en mémoire !! \n");
		exit(0);
	}

	noeud->val = val;
	noeud->suivant = pile->premier;
	pile->premier = noeud;
}


int depiler(Pile *pile){
	if (pile == NULL) {
		printf(" La pile est déja vide !\n");
	}
	int nbrDepiler = 0;

	Element *noeud = pile->premier;

	if (pile != NULL && pile->premier != NULL) {
	   nbrDepiler = noeud->val;
	   pile->premier = noeud->suivant;
	   free(noeud);
	   noeud = NULL;
	}


    return nbrDepiler;
}


int afficher(Pile *pile){
	if (pile_estvide(pile)){
		printf("La pile est déjà vide \n");
		return 0;
	}

	Element *element = pile->premier;
	while(element){
		printf("%d \n", element->val);
		element = element->suivant;
	}
	return 0;
}

int taille_pile(Pile *pile){
	Element *element = pile->premier;
	static int length;
	if(!(pile_estvide(pile))){
        while(element) {
        	length+=1;
        	element = element->suivant;
        }
	} else {
		printf(" la pile est vide \n");
		return 0;
	}
	return length;
}
void reset(Pile *pile){
	if (pile_estvide(pile)){
		printf("La pile est déja vide \n");
	}

	while(pile && pile->premier){
		depiler(pile);

	}

	pile = NULL;
}
int main(void){

	  Pile *pa = initialiser();
      int taille = 0;
	  printf("La pile est vide \n");
	  empiler(pa, 4);
	  empiler(pa, 5);
	  empiler(pa, 6);


	  afficher(pa);
	  printf("La pile aprés dépilage \n");
	  depiler(pa);
	  depiler(pa);

	  afficher(pa);
      taille = taille_pile(pa);
      printf(" La taille de la puile est égale à %d \n", taille);
	  empiler(pa, 25);
	  empiler(pa, 40);
	  empiler(pa, 60);
	  afficher(pa);
	  printf("reset de la pile \n");
	  reset(pa);


	  afficher(pa);

	  return 0;

}




