/**
  * Given an array of n integers, find the sum of maximum sum subsequence of 
  * the given array such that the intgers in the subsequence are sorted in 
  * increasing order. 
  *
  * If input is {1, 101, 2, 3, 100, 4, 5}, output should be 106 (1+2+3+100)
  * If input is {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10) 
  *
  * Prasanth Kalapatapu
  * Nov 13, 2015
  */

#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  
  // stores the maximum sum for an increasing subsequence ending at index i
  int max_sum_is[n];
  
  for (int i=0;i<n;++i) {
    cin >> a[i];
    max_sum_is[i] = a[i];
  }

  int overall_max = a[0];
  for (int i=1;i<n;++i) {
    for (int j=0;j<i;++j) {
      int cur_sum = max_sum_is[j] + a[i];
      if (a[j] < a[i] && cur_sum > max_sum_is[i]) {
	max_sum_is[i] = cur_sum;
      }
    }
    if (max_sum_is[i] > overall_max) {
      overall_max = max_sum_is[i];
    }
  }

  cout << overall_max << endl;
  return 0;
}
