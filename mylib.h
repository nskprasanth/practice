/**
  * Collection of utility functions that can be reused in multiple programs
  *
  * Prasanth Kalapatapu
  * Nov 13, 2015
  */

#ifndef MY_LIB_H
#define MY_LIB_H

#include <algorithm>

int max(int a, int b, int c) {
  return (a>b) ? std::max(a,c) : std::max(b,c);
}

int min(int a, int b, int c) {
  return (a<b) ? std::min(a,c) : std::min(b,c);
}

// binary search function that looks up the given 'val' in the given array 'a'
// in the range defined by 'begin' and 'end' (end not inclusive)
int binary_search(int a[], int begin, int end, int val) {
  if(begin >= end) {
    return -1; // val not found in the given range
  }

  int mid = (begin+end)/2;
  if (val < a[mid]) {
    return binary_search(a, begin, mid, val);
  } else if (val > a[mid]) {
    return binary_search(a, mid+1, end, val);
  } else {
    return mid;
  }
}

#endif // MY_LIB_H
