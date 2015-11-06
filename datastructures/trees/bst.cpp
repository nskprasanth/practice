#include <cstddef>
#include <iostream>
#include "bst.h"

template <typename T>
bst<T>::bst() : root(NULL) {}

template <typename T>
void bst<T>::insert(const T& val) {
  binary_node<T>* node = new binary_node<T>(val);

  if(root == NULL) {
    root = node;
    return;
  }
  insert(root, node);

}

template <typename T>
void bst<T>::insert(binary_node<T>* root, binary_node<T>* node) {

  if (node->data < root->data) {
    if (root->left) {
      insert(root->left, node);
    } else {
      root->left = node;
    }
  } else {
    if (root->right) {
      insert(root->right, node);
    } else {
      root->right = node;
    }
  }

}

template <typename T>
bool bst<T>::find(const T& val) const {
  binary_node<T>* cur = root;
  bool found=false;
  while (cur) {
    if (val < cur->data) {
      cur = cur->left;
    } else if (val > cur->data) {
      cur = cur->right;
    } else {
      found = true;
      break;
    }
  }
  return found;
}

template <typename T>
void bst<T>::print_inorder() const {
  print_inorder(root);
  std::cout << std::endl;
}

template <typename T>
void bst<T>::print_inorder(const binary_node<T>* node) const {
  if (node == NULL) {
    return;
  }
  print_inorder(node->left);
  std::cout << node->data << " ";
  print_inorder(node->right);
}

template <typename T>
void bst<T>::print_preorder() const {
  print_preorder(root);
  std::cout << std::endl;
}

template <typename T>
void bst<T>::print_preorder(const binary_node<T>* node) const {
  if (node == NULL) {
    return;
  }
  std::cout << node->data << " ";
  print_preorder(node->left);
  print_preorder(node->right);
}

template <typename T>
void bst<T>::print_postorder() const {
  print_postorder(root);
  std::cout << std::endl;
}

template <typename T>
void bst<T>::print_postorder(const binary_node<T>* node) const {
  if (node == NULL) {
    return;
  }
  print_postorder(node->left);
  print_postorder(node->right);
  std::cout << node->data << " ";
}

template class bst<short>;
template class bst<int>;
template class bst<float>;
template class bst<double>;

