#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "tree.h"


/*!\struct node
 *  element is member of node struct and it is void pointer
 *  left is member of  struct node
 * right is member of  struct node
 * struct for  node holds void pointer as element and left and right nodes,
 * which provide a bulding block for larger database creation  
 *A tree is composed of a collection of nodes, where each node has some associated data and a set of children.
 */
struct node{
	void*key;   /*!< void pointer to */
	void *data;  
	struct node *left;
	struct node *right;
	
};

/*!\struct tree
 *  root is member of tree and  pointer to  structure node
 * struct tree is a building block for large database which hold pointer to the root of the tree 
 */

struct tree{
	struct node*root;	 
};

/*\fn node_t*node_new(void*element)
 *\param element is  void pointer
 * The function create new node 
*/

node_t* node_new(void *data, void*key){
	node_t * newNode = malloc(sizeof(node_t));
	newNode-> data = data;
	newNode -> data  = key;  
	newNode -> left = NULL;
	newNode -> right = NULL;
	return newNode; 
}; 

/*\fn tree_t*tree_new(void)
 *The function create a new tree, which is also basic nalock for building data structure
*/

tree_t *tree_new(){
	tree_t *result = malloc(sizeof(tree_t));
	result -> root = NULL;  
	return result; 
					  
}

/*\fn void*return_node_name(node_t*node)
 *\param node pointer to  node_t
 * The function return the name of the node, which is a key to node
*/
void *return_Node_name(node_t*node){
	return node -> key; 
}
/*\fn node_t*node_head(tree_t*tree)
 *\param tree is pointer to  tree_t
 * The function return the root of the tree
*/

node_t*return_node_head(tree_t *tree){
	return tree -> root; 
}
/*\fn void*return_ware(tree*tree)
 *\param  tree pointer to tree_t 
 * The function return  item from the root tree 
*/
void *return_ware(tree_t *tree){
	return tree -> root ->data; 
}
/*\fn returnNodeware(node_t*node)
 *\param  node pointer to  node_t
 * The function return item from a given node
*/

void *returnNodeware(node_t*node){
	return node -> data; 
}

/*\fn  tree_size(node_t*node)
 *\param node pointer to  node_t
 * The function calculate the number of nodes on the binary tree
*/

int tree_size(node_t* node){
	if(node == NULL){
		return 0;}
	else{
		return (tree_size(node-> left) + 1 + tree_size(node->right));
	}
}


/*\fn insertaux(node_t**node, void*element)
 *\param node pointer to  node_t
 *\param element void
 * insertaux is auxiliary function to insert node into tree. If the node is inserted, the function return true else it return false
*/

node_t**insertaux(node_t**node, void *data, void*key){ 
	char*name = get_name(data); 
	if(*node == NULL){
		(*node) =  node_new(data, key);
		//(*node) -> key  = key
		//(*node) -> data = data; 
		(*node) -> left = NULL;
		(*node) -> right = NULL;
		return node; 
	}
	
	if(compare((*node) ->key, get_name(data)) == 0){
		return node; 
	}
	else if(compare((*node)->key, get_name(data)) <0){

		insertaux(&((*node)->left), data, key);
	}
	
	else{
 
		insertaux(&((*node) ->right), data, key); 
	}
	return node; 
}
/*\fn inserNode(tree_t*tree, void*element)
 *\param tree pointer to  tree_t
 *\param element pointer to  void
 * The function insert node into tree
*/

node_t**insertNode(tree_t *tree, void*data, void*key){
   key = get_name(data); 
	if(tree -> root == NULL){
		tree -> root =  node_new(data, key);
		//tree -> root -> key = key 
		//tree -> root -> data = data; 
		tree -> root -> left = NULL;
		tree -> root -> right = NULL;
		return &(tree->root); 	
	}
	insertaux(&(tree -> root), data, key); 
}


/*\fn isShelftakenaux(node_t*node, shelf*shelfName)
 *\param node pointer to node_t
 *\param shelfName pointer to  shelf
 * The function is auxiliary functio to check if the shelf is taken or not. The function return false, if the shelf is taken  
*/

bool isShelftakenaux(node_t *node, shelf *shelfName){
	if(node ==NULL)
		return false;
	else {
		if(isexist(return_list(returnNodeware(node)) ,shelfName) == true){
				return true;
	
		}}
	return isShelftakenaux(node -> left, shelfName) || isShelftakenaux(node -> right, shelfName); 
}

/*\fn isShelftaken(tree_t*tree, shelf*shelfName)
 *\param tree pointer to tree_t
 *\param shelfName pointer to  shelf
 * The function check if the shelf is taken or not. The function return false, if the shelf is taken.
*/

bool isShelftaken(tree_t *tree, shelf *shelfName){
	if(tree ==NULL)
		return false;
	return isShelftakenaux(tree -> root, shelfName); 
}



/*\fn node_t*findaux(node_t*node, void*element)
 *\brief crate a node with element
 *\param node pointer to node_t
 *\param element pointer to void
 * The function is auxiliary function to search the node on the tree, if the node existed, it will return the node. 
   Otherwise it will return NULL; 
*/


node_t*findaux(node_t *node, void*Itemname){
	if (node == NULL)
		return NULL;
  
	else 
		
		if(compare(node->key, Itemname)== 0){
			return node;
		}
		else if(compare(node-> key, Itemname) > 0){
			
			return findaux(node -> left, Itemname);
		}
		else {
			return findaux(node -> right, Itemname);
		}
	}
   

/*\fn node_t*find_node(tree_t*tree, char*element)
 *\brief crate a node with element
 *\param node pointer to  node_t 
 *\param element pointer to char
 * The function search the node on the tree, if the node existed, it will return the node. Otherwise it will return NULL. 
*/


node_t*find_node(tree_t*tree, char*name){
	if(tree -> root == NULL){
		return NULL; }
	return findaux(tree -> root, name); 
}
/*\fn bool findnode(node_t *node, char*Itemname)
 *\param node pointer to node_t
 *\param Itemname pointer to  char
 * The function  search the node and return true, if the node is existed on tree otherwise false. 
*/

bool findnode(node_t *node, char*Itemname){
	if (node== NULL)
		return false;
  
	else {
		
		if(compare(node->key, Itemname)== 0){
			return true;
		}
		else if(compare(node->key, Itemname) > 0){
			
			
			return findnode(node -> left, Itemname);
		}
		else {
			return findnode(node -> right, Itemname);
		}
	}
   
}
/*\fn bool find_Node(tree_t *tree, char*Itemname)
 *\param node pointer to node_t
 *\param Itemname pointer to  char
 * The function  search the node and return true, if the node is existed on tree otherwise false. 
*/

bool find_Node(tree_t*tree, char*Itemname){
	if(tree-> root == NULL){
		return false; }
	return findnode(tree -> root, Itemname); 
}


/*\fn node_t*min_Value(node_t*node)
 *\param node pointer to node_t
 * The function search and find the minimum value from tree, which is auxiliary function for delete node
*/

node_t * min_Value(node_t* node){
	if(node == NULL){
		return NULL; 
	}
	else {
		node_t *current =node ; 
	
		while (current -> left!=NULL){
		   current= current ->left;}
		return current;
	}
}

/*\fn bool removeaux (node_t**root, void*element)
 *\param node pointer to  node_t 
 *\param element pointer to  void
 * The function is auxiliary functio which remove the item if it exist on the tree and return true if succesfull, otherwise return false; 
*/

bool removeaux(node_t **node, void*element){
	char *Itemname = get_name(element);
	bool exist = findnode(*node, Itemname); 
	if(exist == false) {
		return true;
	}
	else if(compare((*node) -> key, Itemname) > 0){
		return removeaux(&((*node)-> left), element);
	}
	else if(compare((*node) ->key, Itemname) < 0){
		return removeaux(&(*node)-> right, element);}

	else{
		/* delete root and the root has no left or right child*/
		
		if( (*node)-> left == NULL && (*node) -> right == NULL){
			free(node);
			node = NULL;
			return true; 
		}
		/* delete root when the root has only right child*/
		else if( (*node) -> left == NULL && (*node) -> right != NULL){
			node_t*var  = (*node)->right;
			*node = var;   
			return true;
	}
		/* delete root when the root has  only left child*/
		else if((*node) -> left != NULL && (*node) ->right == NULL){
			node_t *var = (*node)-> left;
			*node = var; 
			return true; 
		}
		/* delete root when the root has two child*/
		else{
			node_t *min = min_Value(*node);
			*node = min; 
			return removeaux(node, returnNodeware(min));
		}
	
		}
	return true; 
	}

/*\fn bool remove_Node(tree_t*tree, void*element)
 *\param tree  pointer to  tree_t 
 *\param  element pointer to  void
 * The function remove the element if it exist on the tree and return true if succesfull, otherwise return false; 
*/
bool remove_Node(tree_t*tree, void*element){
	if(tree -> root == NULL)
		return true;
	removeaux(&(tree -> root), element);
	return true; 
}

/*\fn void print(node_t*node)
 *\param node pointer to  node_t
 * The function print all the element at tree
*/
  
void print (node_t*node){
	if(node == NULL)
		return; 
	{
		print(node -> left); 
		printf("%s\n", get_name(return_Node_name(node)));
		print(node -> right);
	}
}

/*\fn int cmpstringp(const void*p1, const void*p2)
 *\brief crate a node with element
 *\param p1 const void pointer
 \*param p2  const void pointer
 * The function takes two void pointer argument and compare two of them and return the computed result 
*/

 int compareString(const void *a, const void *b) 
{ 
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);

} 
 
/*\fn void dumpTree(node_t*node, node_t*arry[], int *p_t)
 *\param node is pointer to node_t
 *\param arry  is  ponter to char array
 *\param p_t  is pointer to int 
 * The function turn binary tree into node array
*/
void dumpTree(node_t *node, node_t *array[], int *p_t){
    if(node){
      dumpTree(node-> left, array, p_t);
      array[*p_t] = node;
     * p_t += 1; 
      dumpTree(node -> right, array, p_t);
    }
    else {
	} 
}
/*\fn void free_tree(node_t*node)
 *\param node node_t
 * The function recursively free all the node pointer from tree; 
*/

void free_tree(node_t*node){
	if(node != NULL){
		free_tree(node -> left);
		free(node->data); 
		free_tree(node -> right);
		free(node);
	}
		
}

/*\fn void sortNode(node_t*nodeArray[], int size, node_t*node)
 *\param  nodeArray is pointer  to array of node 
 *\param  size is int that specify the size of array
 *\param  node is pointer to node_t 
 *The  function sort a node array in ascending order
*/

void sortNode(node_t*nodeArray[], int size, node_t*node){
	int i, j= 0;
	dumpTree(node, nodeArray, &j); 
	qsort(get_name(returnNodeware(node)), size -1, sizeof(char*), compareString); 	
}

/*\fn node_t** balance_node(node_t*array[], int first, int last)
 *\param  array is pointer  to array of node 
 *\param  first is int that point to the fist element of the array
 *\param  last is int that point the last element of the array
 * The function is  auxiliary function for createing balanced binary node from a given sorted array node
*/
/*
node_t**balance_node(node_t**node, node_t*Nodearray[], int first, int last){
	int middel = (first + last)/2;
	
    if (first < last){
		*node = node_new(node); 
		(*node) = Nodearray[middel];
		(*node)-> left = NULL;
		(*node)-> right = NULL;
		insertaux(node, Nodearray[middel], get_name(returnNodeware(array[i]))); 
		balance_node(&((*node)->left),Nodearray, first, middel -1);
		balance_node(&((*node)->  right), Nodearray, middel +1, last);
	}
	else {
		return NULL; 
	}
	return node; 
	}*/
/*\fn void blanced_tree(node_t*node)
 *\param tree is pointer to tree_t
 * The function build balanced tree from balanced nodes
*/
/*
void blanced_tree(tree_t*tree){
	int i , j = 1;
	tree_t*t = tree_new();
	t -> root = NULL;
	int size = tree_size(tree->root);
	node_t*Nodearray[size];
	sortNode(Nodearray, size, tree->root);
	balance_node(&(t ->root) , Nodearray, 0, size); 
    
	for(i = 0, j= 1; i < size; i++, ++j){
		printf("%d. %s\n", j, get_name(returnNodeware(array[i])));
	}
	}*/
/*\fn printTree(tree_t*tree)
 *\param tree is pointer to tree_t 
 * The function print the node elemet with option. The user print the first every 20 element at a time. 
*/

void printTree(tree_t*tree){
	int i = 0 , j = 1, c =0; 
	int size = tree_size(tree-> root); 
    node_t* Nodearray[size];
	dumpTree(tree -> root, Nodearray, &i);
	for(i = c, j = 1; i < size; i++, ++j){
		++c; 
		printf("%d. %s\n", j, get_name(returnNodeware(Nodearray[i])));
	}
	
/*

LOOP:
		for(i = c, j = 1; i < size; i++, ++j){
			++c; 
			printf("%d. %s\n", j, nodeArray[i]);
			if(i ==20) {
				goto NEXT;
			}
			
		}
NEXT:
			goto LOOP; 
*/
}







		



