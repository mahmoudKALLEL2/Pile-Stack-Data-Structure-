/*
 * test.h
 *
 *  Created on: 5 avr. 2020
 *      Author: USER
 */

#ifndef PILE_H_
#define PILE_H_


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

Pile *initialiser(void);
Bool pile_estvide(Pile *pile);
void empiler(Pile *pile, int val);
int depiler(Pile *pile);
void afficher(Pile *pile);
void taille_pile(Pile *pile, int *nbrElt);
void reset(Pile *pile);

#endif /* TEST_H_ */
