#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "shelf.h"

struct _shelf{
	char*shelf_address;
	int quantity; 
} ;

shelf * makeShelf(char *shelfname, int quantity){
	shelf *node = malloc(sizeof(struct _shelf));
	node -> shelf_address = malloc(strlen(shelfname)*sizeof(char)+1);
	strcpy(node -> shelf_address, shelfname);
	node -> quantity = quantity;
	return node; 
}


char *get_shelf(shelf*address){
	return address -> shelf_address;
}

int get_quantity(shelf*address){
	return address -> quantity; 
}

void add_amount(shelf *s, int *sum)
{
  *sum += s->quantity;
}
