/**
  * Given a string, a partitioning of the string is a palindrome partitioning 
  * if every substring of the partition is a palindrome. Find the fewest cuts
  * needed for such palindrome partitioning. 
  * 
  * -- Example --
  * For “ababbbabbababa” three cuts are needed -> “a|babbbab|b|ababa”.
  * -------------
  *
  * Prasanth Kalapatapu
  * Nov 6, 2015
  */

#include <iostream>
#include <climits>
using namespace std;

int main() {
  string str;
  cin >> str;

  int n = str.size();
  int count[n][n]; // min cuts for palindrome partioning str[i..j]
  bool pal[n][n]; // true if str[i..j] is a palindrome, false otherwise
  
  for (int i=0;i<n;++i) {
    // all single character strings are palindrome
    count[i][i] = 0;
    pal[i][i] = true; 
  }

  for (int len=2;len<=n;++len) {
    for (int i=0;i<=n-len;++i) { // i: begin index
      int j = i+len-1; // j: end index
      if (len == 2) {
	pal[i][j] = (str[i] == str[j]);
      } else {
	pal[i][j] = (str[i]==str[j] && pal[i+1][j-1]);
      }

      if (pal[i][j]) {
	count[i][j] = 0;
      } else {
	count[i][j] = INT_MAX;
	for (int k=i;k<j;++k) {
	  count[i][j] = min(count[i][j], 1+count[i][k]+count[k+1][j]);
	}
      }
    }
  }
  cout << count[0][n-1] << endl;
  
  return 0;
}
