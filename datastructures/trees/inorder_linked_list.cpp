/**
  * Given a  binary search tree, converts the inorder traversal of 
  * the tree into a linked list
  *
  * Prasanth Kalapatapu
  * Nov 6, 2015
  */

#include <iostream>
#include "bst.h"

using namespace std;

// struct representing a node in a linked list of integers
struct list_node {
  list_node(int val) : data(val), next(NULL) {}
  int data;
  list_node* next;
};

// Reverses the given linked list and returns the head of the reversed list
list_node* reverse(list_node* node) {
  if (!node || !node->next) {
    return node;
  }

  list_node* nn = node->next;
  node->next = NULL;
  while(nn) {
    list_node* temp = nn->next;
    nn->next = node;
    node = nn;
    nn = temp;
  }
  return node;
}

// Prints the linked list with the head as node
void print(list_node* node) {
  while(node) {
    cout << node->data << " ";
    node = node->next;
  }
  cout << endl;
}

// Prepend a new node with value 'val' to the given linked list 'node'
list_node* prepend_to_list(list_node* node, int val) {
  list_node* new_node = new list_node(val);
  if (node == NULL) {
    return new_node;
  }
  new_node->next = node;
  return new_node;
}

// Populates the inorder traversal of given tree_node into the given list_node
list_node* populate_inorder_to_list(binary_node<int>* tree_node, list_node* node) {
  if (tree_node == NULL) {
    return node;
  }
  node = populate_inorder_to_list(tree_node->left, node);
  node = prepend_to_list(node, tree_node->data);
  return populate_inorder_to_list(tree_node->right, node);
}

// Returns a linked list that represents the inorder traversal of given tree
list_node* get_inorder_as_list(bst<int> tree) {
  // pass an empty list to populate_inorder_to_list 
  list_node* node = populate_inorder_to_list(tree.get_root(), NULL);
  
  // the populated list is in reverse inorder traversal, so reverse the list
  list_node* reversed = reverse(node);

  return reversed;
}

int main() {
  int n;
  bst<int> tree;
  cin >> n;
  for (int i=0;i<n;++i) {
    int cur;cin >> cur;
    tree.insert(cur);
  }

  // print the inorder traversal of the tree
  tree.print_inorder();
 
  list_node* head = get_inorder_as_list(tree);
  print(head);

  return 0;
}
