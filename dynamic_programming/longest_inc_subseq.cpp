/**
  * Find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible
  * 
  * --Example--
  * Input: 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15
  * Output: 0, 2, 6, 9, 11, 15
  * -----------
  *
  * Prasanth Kalapatapu
  * Nov 5, 2015
  */

#include <iostream>
#include <list>
using namespace std;

/** Returns the length of lis ending at index i
  * a: input array of numbers
  * b: contains the indices from a for any given lis length
  * n: size of input array
  * i: current index
  * len: length of lis ending at index i-1
  */
int find_len(int *a, int *b, int n, int i, int len) {
  int lo=1, hi=len;
  int mid;
  while(lo<=hi) {
    mid = (lo+hi)/2;
    if (a[b[mid]] <= a[i]) {
      lo=mid+1;
    } else {
      hi=mid-1;
    }
  }
  return lo;
}

int main() {
  // Input
  int n;
  cin >> n;
  int a[n];
  for (int i=0;i<n;++i) {
    cin >> a[i];
  }

  // b[i] stores the index of smallest number from a[] at which there is a LIS of length i
  int b[n+1];
  for (int i=0;i<=n;++i) {
    b[i] =-1;
  }
  b[1] = 0;

  // pred[i] stores the index of the preceding element in LIS ending at index i
  int pred[n];
  for (int i=0;i<n;++i) {
    pred[i] =-1;
  }

  // Algorithm
  int len=1;
  for (int i=1;i<n;++i) {
    int cur_len = find_len(a, b, n, i, len);
    if(b[cur_len] == -1 || a[i] < a[b[cur_len]]) {
      b[cur_len] = i;
    }
    pred[i] = b[cur_len-1];

    if (cur_len > len) {
      len = cur_len;
    }
  }

  // store in a list to print in reverse order
  list<int> lis;
  for(int i=b[len];i>=0;) {
    lis.push_back(a[i]);
    i=pred[i];
  }
  for (list<int>::reverse_iterator rit = lis.rbegin(), end = lis.rend(); rit!=end;++rit) {
    cout << *rit << " ";
  }
  cout << endl;

  return 0;
}
