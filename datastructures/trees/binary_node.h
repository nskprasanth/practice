#ifndef BINARY_NODE_H
#define BINARY_NODE_H

/**
  * Class representing a binary node with a data element and two 
  * child nodes (left and right)
  * 
  * Prasanth Kalapatapu
  * Nov 6, 2015
  */

template <typename T>
class binary_node {
  public:
    binary_node(const T& in) : data(in) {}
    
    binary_node* left;
    binary_node* right;
    T data;
};

#endif // BINARY_NODE_H
