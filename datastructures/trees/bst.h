#ifndef BST_H
#define BST_H

/**
  * Class representing a binary search tree
  *
  * Prasanth Kalapatapu
  * Nov 6, 2015
  */

#include "binary_node.h"

template <typename T>
class bst {
  public:
    bst();

    // inserts a given element into the binary search tree
    virtual void insert(const T&);

    // Checks whether the given element exists in the tree
    virtual bool find(const T&) const;

    // prints the inorder traversal of the tree
    void print_inorder() const;
    
    // prints the preorder traversal of the tree
    void print_preorder() const;
    
    // prints the postorder traversal of the tree
    void print_postorder() const;
   
    // Returns the root node of the tree
    inline binary_node<T>* get_root() { return root; }

  protected:
    // helper function to do insertions into the tree
    virtual void insert(binary_node<T>*, binary_node<T>*);

  private:
    binary_node<T>* root;
    
    // helper functions for traversals
    void print_inorder(const binary_node<T>*) const;
    void print_preorder(const binary_node<T>*) const;
    void print_postorder(const binary_node<T>*) const;
};

#endif // BST_H
