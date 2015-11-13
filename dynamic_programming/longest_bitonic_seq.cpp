/**
  * Given an array of integers, find the longest bitonic sequence in the array.
  * A subsequence is called bitonic if it is first increasing, then decreasing.
  * 
  * Input arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
  * Output: 6 (A Longest Bitonic Subsequence of length 6 is 1, 2, 10, 4, 2, 1)
  *
  * Prasanth Kalapatapu
  * Nov 13, 2015
  */

#include <iostream>
#include <climits>
#include "../mylib.h"
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i=0;i<n;++i) {
    cin >> a[i];
  }

  // inc[i]: stores the longest increasing subsequence ending at index i
  // dec[i]: stores the longest decreasing or first-increasing-then-decreasing
  //         subsequence ending at index i
  int inc[n], dec[n];
  int longest_bitonic_seq = 0; // length of longest bitonic sequence 
  inc[0] = dec[0] = 1; // a single element subsequence

  for (int i=1;i<n;++i) {
    int inc_max = INT_MIN, dec_max = INT_MIN;
    
    for (int j=0;j<i;++j) {
      if (a[j] <= a[i] && inc[j]>inc_max) {
	inc_max = inc[j]; // similar to LIS (longest increasing subsequence)
      }

      if (a[j] >= a[i]) {
	// pick the longest of decreasing or first-increasing-then-decreasing
	dec_max = max(dec_max, inc[j], dec[j]);
      }
    }

    inc[i] = 1+inc_max;
    dec[i] = 1+dec_max;

    // ending at index i, longest bitonic sequence is either the longest
    // increasing subseq ending at i, or longest decreasing subseq ending
    // at i, or longest first-increasing-then-decreasing subseq ending at i
    longest_bitonic_seq = max(longest_bitonic_seq, inc[i], dec[i]);
  }

  cout << longest_bitonic_seq << endl;
  return 0;
}
