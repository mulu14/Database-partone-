#include<CUnit/Console.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <CUnit/TestDB.h>
#include <CUnit/Automated.h>
#include "shelf.h"
#include "ware.h"
#include "list.h"
#include "tree.h"




void test_tree_creation(){
  tree_t*tree = tree_new();
  CU_ASSERT_FALSE(tree==NULL);
  CU_ASSERT_TRUE(tree !=NULL); 
}

void test_tree_insert_node(void){

  tree_t*root = tree_new(); 
  ware *w1 = createNewWare("car","car des", 21,list_new());
  ware *w2 = createNewWare("beer", "beer des", 7,  list_new());
  ware *w3 = createNewWare("orange", "orange des", 4,  list_new());
  ware *w4 = createNewWare("book", "book des", 20,  list_new());


  CU_ASSERT_TRUE(insertNode(root,"car", w1, comparevoid ));
  CU_ASSERT_TRUE(insertNode(root,"beer", w2, comparevoid ));
  CU_ASSERT_TRUE(insertNode(root,"orange",w3, comparevoid));
  CU_ASSERT_TRUE(insertNode(root,"book", w4, comparevoid));
 
}; 

	
void test_tree_remove_node(void){
  tree_t *root = tree_new(); 

  ware *w1 = createNewWare("car","car des", 21,list_new());
  ware *w2 = createNewWare("beer", "beer des", 7,  list_new());
  ware *w3 = createNewWare("orange", "orange des", 4,  list_new());
  ware *w4 = createNewWare("book", "book des", 20,  list_new());


  insertNode(root,"car", w1, comparevoid );
  insertNode(root,"beer", w2, comparevoid );
  insertNode(root,"orange",w3, comparevoid);
  insertNode(root,"book", w4, comparevoid);

  CU_ASSERT_EQUAL(tree_size(return_node_head(root)), 4);
  CU_ASSERT_TRUE(remove_Node(root,"car", comparevoid ));
  CU_ASSERT_TRUE(remove_Node(root,"beer", comparevoid ));
  CU_ASSERT_TRUE(remove_Node(root, "orange", comparevoid));
  CU_ASSERT_TRUE(remove_Node(root, "book", comparevoid));
  CU_ASSERT_EQUAL(tree_size(return_node_head(root)), 0);
  // test invalid arguments
  // 
}

void test_tree_size(void){

  tree_t*root = tree_new(); 
  ware *w1 = createNewWare("car","car des", 21,list_new());
  ware *w2 = createNewWare("beer", "beer des", 7,  list_new());
  ware *w3 = createNewWare("orange", "orange des", 4,  list_new());
  ware *w4 = createNewWare("book", "book des", 20,  list_new());


  insertNode(root,"car", w1, comparevoid );
  insertNode(root,"beer", w2, comparevoid );
  insertNode(root,"orange",w3, comparevoid);
  insertNode(root,"book", w4, comparevoid);
  CU_ASSERT_EQUAL(tree_size(return_node_head(root)), 4);
  // empty tree

}; 


void test_tree_find_node(void){

  tree_t*root = tree_new();
  ware *w1 = createNewWare("aa", "drink", 4,  list_new());
  ware *w2 = createNewWare("xx", "For house", 20,  list_new());
  ware *w3 = createNewWare("cc", "car des", 21,list_new());
  ware *w4 = createNewWare("dd", "alchol", 7,  list_new());


  insertNode(root,"aa", w1, comparevoid );
  insertNode(root,"xx", w2, comparevoid );
  insertNode(root,"cc",w3, comparevoid);
  insertNode(root,"dd", w4, comparevoid);
 
  CU_ASSERT_TRUE(find_node(root, "aa", comparevoid) !=NULL);
  CU_ASSERT_TRUE(find_node(root, "xx", comparevoid) !=NULL);
  CU_ASSERT_TRUE(find_node(root, "cc", comparevoid) !=NULL);
  CU_ASSERT_TRUE(find_node(root, "dd", comparevoid) !=NULL);
  CU_ASSERT_TRUE(find_node(root, "mobile", comparevoid)==NULL);
  CU_ASSERT_TRUE(find_node(root, "tape", comparevoid)== NULL);
  //empty
  // not existed 

};

void test_list_prepend(){
  list_t *list = list_new();
  shelf *add1 = makeShelf("A", 4);
  shelf *add2 = makeShelf("B", 23);
  shelf *add3 = makeShelf("I", 10);
  shelf *add4 = makeShelf("X", 7);

  CU_ASSERT_TRUE(list_prepend(list,"A", add1));
  CU_ASSERT_TRUE(list_prepend(list,"B", add2));
  CU_ASSERT_TRUE(list_prepend(list,"I", add3));
  CU_ASSERT_TRUE(list_prepend(list, "X",add4));
		
}

void test_list_append(){
  list_t *list = list_new();
  shelf *add1 = makeShelf("A", 4);
  shelf *add2 = makeShelf("B", 23);
  shelf *add3 = makeShelf("I", 10);
  shelf *add4 = makeShelf("X", 7);

  CU_ASSERT_TRUE(list_append(list, "A", add1));
  CU_ASSERT_TRUE(list_append(list,"B", add2));
  CU_ASSERT_TRUE(list_append(list,"I", add3));
  CU_ASSERT_TRUE(list_append(list,"X", add4));
		
}

void test_list_length(){
  list_t *list = list_new();
  shelf *add1 = makeShelf("A", 4);
  shelf *add2 = makeShelf("B", 23);
  shelf *add3 = makeShelf("I", 10);
  shelf *add4 = makeShelf("X", 7);

  list_append(list, "A", add1);
  list_append(list,"B", add2);
  list_append(list,"I", add3);
  list_append(list,"X", add4);
		
	
  CU_ASSERT_EQUAL(list_length(list), 4); 
		
}

void test_list_insert_at_index(){
  list_t *list = list_new();
  shelf *add1 = makeShelf("A", 4);
  shelf *add2 = makeShelf("B", 23);
  shelf *add3 = makeShelf("I", 10);
  shelf *add4 = makeShelf("X", 7);
  shelf *add5 = makeShelf("H", 7);

  list_append(list, "A", add1);
  list_append(list, "B", add2);
  list_append(list, "I", add3);
  list_append(list, "H", add4);

  CU_ASSERT_TRUE(list_insert(list, 0, "A", add5));
  CU_ASSERT_TRUE(list_insert(list, 4, "A", add5)); 
  CU_ASSERT_FALSE(list_insert(list, 5, "A",add5));
  CU_ASSERT_FALSE(list_insert(list, 10, "A", add5)); 
		
}


void test_list_remove_at(){

  list_t *list = list_new();
  shelf *add1 = makeShelf("A", 4);
  shelf *add2 = makeShelf("B", 23);
  shelf *add3 = makeShelf("I", 10);
  shelf *add4 = makeShelf("X", 7);
  shelf *add5 = makeShelf("H", 7);

  list_append(list,"A", add1);
  list_append(list,"B", add2);
  list_append(list,"I", add3);
  list_append(list, "X", add4);

  CU_ASSERT_TRUE(list_remove(list, 0, add1));
  CU_ASSERT_TRUE(list_remove(list, 1, add2));
  CU_ASSERT_FALSE(list_remove(list, 5, add5));
  CU_ASSERT_FALSE(list_remove(list, 10, add5)); 
}

void test_list_get_at_index(){
  list_t *list = list_new();
	
  shelf *add1 = makeShelf("A", 4);
  shelf *add2 = makeShelf("B", 23);
  shelf *add3 = makeShelf("I", 10);

  list_append(list, "A",add1);
  list_append(list, "B", add2);
  list_append(list, "I",add3);

  CU_ASSERT_TRUE(list_get_shelf(list,0) !=NULL);
  CU_ASSERT_TRUE(list_get_shelf(list,1) !=NULL);
  CU_ASSERT_TRUE(list_get_shelf(list,2) !=NULL);


}





int main (int argc, char*argv[]){
  CU_initialize_registry();
  /*
    tree test
  */

  CU_pSuite testTree = CU_add_suite("Test tree part", NULL, NULL);
  CU_add_test(testTree, "insertion", test_tree_insert_node);
  CU_add_test(testTree, "Delete", test_tree_remove_node);
  CU_add_test(testTree, "size", test_tree_size);
  CU_add_test(testTree, "findnode", test_tree_find_node);
  /*
    list test 
  */
  CU_pSuite testList = CU_add_suite("Test list part", NULL, NULL);
  CU_add_test(testList, "list prepend", test_list_prepend);
  CU_add_test(testList, "list append", test_list_append);
  CU_add_test(testList, "list insert at index", test_list_insert_at_index);
  CU_add_test(testList, "list remove", test_list_remove_at);
  CU_add_test(testList, "return list element at index",test_list_get_at_index);


  CU_automated_run_tests();
  CU_basic_run_tests(); 
  CU_cleanup_registry(); 
	
  return 0; 
}
