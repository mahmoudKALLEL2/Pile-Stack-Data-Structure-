/*
 * main.c
 *
 *  Created on: 7 avr. 2020
 *      Author: Mahmoud KALLEL
 */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
#include "test.h"

int main(void){

	  Pile *pa = initialiser();
      int taille = 0;

	  printf("*********** The Stack is empty ******************\n");
	  printf(" Push new elements in the stack \n");
	  empiler(pa, 41);
	  empiler(pa, 59);
	  empiler(pa, 66);
      taille_pile(pa, &taille);
      printf(" The number of the element is: %d \n", taille);

	  afficher(pa);
	  printf(" The Stack after unstacking the Stack \n");
	  depiler(pa);
	  depiler(pa);

	  afficher(pa);
	  taille_pile(pa, &taille);
	  printf(" The number of the element is: %d \n", taille);
	  empiler(pa, 25);
	  empiler(pa, 40);
	  empiler(pa, 60);
	  afficher(pa);
	  printf(" Reset of the Stack \n");
	  reset(pa);
	  afficher(pa);

	  printf("*********** The Stack is empty ******************\n");
	  return 0;

}

