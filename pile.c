#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
#include "test.h"

/* Initialize the stack                          */
/* in : void                                     */
/* out: pile                                     */
Pile *initialiser(void){
   Pile *pile = malloc(sizeof(*pile));
   pile->premier = NULL;
   return pile;
}

/* Check whether the stack is void or Not         */
/* in : pile                                      */
/* out: value with boolean type: true or false    */
Bool pile_estvide(Pile *pile){
	if (!(pile->premier) ) {
		return true;
	}

	return false;
}

/* Push the stack                                            */
/* in : pile
 * in :  val which is the new element to push in the stack
 * out: void                                                 */
void empiler(Pile *pile, int val){
	Element *noeud = malloc(sizeof(*noeud));

	if (pile == NULL || noeud == NULL){
		fprintf(stderr, " Memory Error !! \n");
		exit(0);
	}

	noeud->val = val;
	noeud->suivant = pile->premier;
	pile->premier = noeud;
}

/* Unstack an element
 * in : pile
 * out: int which is the return of the function , it is considered as the value
 *      of the element has bee moved
 */
int depiler(Pile *pile){
	if (pile_estvide(pile)){
		printf(" The Stack is already empty \n");
		return 0;
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

/* Display all the elements of the stack
 * in : pile
 * out: void */
void afficher(Pile *pile){
	if (pile_estvide(pile)){
		printf(" The Stack is already empty \n");
		return;
	}

	Element *element = pile->premier;
	while(element){
		printf(" %d \n", element->val);
		element = element->suivant;
	}
	return;
}

/* Calculate the number of the element in the stack
 * in : pile
 * out: int which represent the number of the elements within the stack
 * */
void taille_pile(Pile *pile, int *nbrElt){

	int length = 0;
	Element *element = pile->premier;
	/* check if the stack is not empty */
	if(!(pile_estvide(pile))){
        while(element) {
        	length+=1;
        	element = element->suivant;
        }
	} else {
		printf(" la pile est vide \n");
		length = 0;
		return;
	}
	*nbrElt = length;
	return;
}

/* Allowing to erase all the elements of the stack.
 * in : pile
 * out: void
 * */
void reset(Pile *pile){
	/* check if the stack is not empty */
	if (pile_estvide(pile)){
		printf(" The Stack is already empty \n");
		return;
	}

	while(pile && pile->premier){
		depiler(pile);
	}

	pile->premier = NULL;
	pile = NULL;
	free(pile);
}





