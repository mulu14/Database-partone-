#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<stdint.h>
#include "ware.h"
#include "list.h"
#include "shelf.h"
#include "tree.h"

ware * createNewWare(char* name, char* description, int price, list_t* shelf_list){
	ware*newWare =(struct ware_t*)malloc(sizeof(struct ware_t));
	newWare -> name = (char*)malloc(strlen(name)*sizeof(char) +1);
	newWare -> description = (char*)malloc(strlen(description)*sizeof(char) +1);

	strcpy(newWare ->name, name);
	strcpy(newWare ->description, description);
	newWare -> price = price;
	newWare -> shelf_list = shelf_list;
	return newWare;  
}


char*get_name(ware*item){
	return item -> name;
   
};


void destroy_ware(ware*item){
	free(item -> name);
	free( item -> description);
	freeList(item ->shelf_list); 
	}

char *get_des(ware*item){
	return item ->description;  
}

int get_price(ware*item){
	return item -> price; 
}

list_t* return_list(ware *item){
	return item -> shelf_list; 
}


