/**
  * Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert str1 into str2.
  * Insert
  * Remove
  * Replace
  * All of the above operations are of equal cost. Can be easily customized for different costs.
  * -- Example --
  * str1 = "sunday", str2 = "saturday"
  * edit distance -> 3 : insert at and replace n with r
  *
  * Prasanth Kalapatapu
  * Nov 5, 2015
  */

#include<iostream>
using namespace std;

int min (int a, int b, int c) {
  return (a<b) ? min(a,c):min(b,c);
}

int main () {
  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.size(), m = s2.size();
  
  // 1-indexed array containing edit distances for combinations of indices
  int a[n+1][m+1];
  for (int i=0;i<=m;++i) {
    // to convert an empty string to a i-char string, insert i characters
    a[0][i] = i;
  }
  for (int i=0;i<=n;++i) {
    // to convert an i-char string to an empty string, delete i characters
    a[i][0] = i;
  }
  
  for (int i=0;i<n;++i) {
    for (int j=0;j<m;++j) {
      if (s1[i] == s2[j]) {
	a[i+1][j+1] = a[i][j];
      } else {
	// min of replace, delete and insert operations (respectively)
	a[i+1][j+1] = 1+min(a[i][j], a[i][j+1], a[i+1][j]);
      }
    }
  }

  // a[n][m] holds the edit distance to convert s1(of size n) to s2(of size m)
  cout << a[n][m] << endl;
  
  return 0;
}
