/**
  * Given the inorder and preorder traversals of a binary tree, 
  * construct the original tree from this information
  *
  * --- Sample input ---
  * 6
  * 7 10 12 15 18 20
  * 15 10 7 12 20 18
  * --------------------
  *
  * Prasanth Kalapatapu
  * Nov 11, 2015
  */

#include <iostream>
#include "binary_node.h"
#include "bst.h"

using namespace std;

// binary search function that looks up the given 'val' in the given array 'a'
// in the range defined by 'begin' and 'end' (end not inclusive)
int find(int a[], int begin, int end, int val) {
  if(begin >= end) {
    return -1; // val not found in the given range
  }

  int mid = (begin+end)/2;
  if (val < a[mid]) {
    return find(a, begin, mid, val);
  } else if (val > a[mid]) {
    return find(a, mid+1, end, val);
  } else {
    return mid;
  }
}

// constructs a binary tree from the begin and end indices given for both
// inorder and preorder travesals represented by arrays in and pre respectively
binary_node<int>* construct_tree(int in[], int ib, int ie, 
    int pre[], int pb, int pe) {

  if (ib == ie) { // both ie and pe are not inclusive
    return NULL;
  }

  int root_val = pre[pb];
  // local root node
  binary_node<int>* cur = new binary_node<int>(root_val);

  if (pb+1 == pe) {
    return cur;
  }

  int idx = find(in, ib, ie, root_val);
  if (idx == -1) { // one of the preorder element not found in inorder 
    cerr << "error in the input .. exiting" << endl;
    return NULL;
  }

  binary_node<int>* l = construct_tree(in, ib, idx, pre, pb+1, pb+idx-ib+1);
  binary_node<int>* r = construct_tree(in, idx+1, ie, pre, pb+idx-ib+1, pe);
  cur -> left =  l;
  cur -> right = r;
}

binary_node<int>* construct(int in[], int pre[], int n) {
  return construct_tree(in, 0, n, pre, 0, n);
}

int main() {
  int n;
  cin >> n;
  int in[n], pre[n];
  for (int i=0;i<n;++i) {
    cin >> in[i];
  }

  for (int i=0;i<n;++i) {
    cin >> pre[i];
  }

  binary_node<int>* root = construct(in, pre, n);
  bst<int> mytree(root);

  mytree.print_inorder();
  mytree.print_preorder();
  mytree.print_postorder();

  return 0;
}
