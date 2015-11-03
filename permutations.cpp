/**
 * Given a string, compute all possible permutations of that string (allowing duplicates)
 * Nov 2, 2015
 * Author: Prasanth Kalapatapu
 */

#include <iostream>
#include <cstring>
using namespace std;

void swap(char* a, int i, int j) {
  char ch = *(a+i);
  *(a+i) = *(a+j);
  *(a+j) = ch;
}

void permute(char* a, int l, int r) {
  if (l==r) {
    cout << a << endl;
    return;
  }

  for (int i=l;i<=r;++i) {
    swap(a,l,i);
    permute(a,l+1,r);
    swap(a,i,l);
  }
}

void permute(const string& str) {
  char* a = new char[str.size()];
  strcpy(a, str.c_str());
  permute(a, 0, str.size()-1);
}

int main() {
  string in;
  cin >> in;
  permute(in);
  return 0;
}
