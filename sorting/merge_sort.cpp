/**
  * Merge sort a given array of integers
  *
  * Prasanth Kalapatapu
  * Nov 12, 2015
  */

#include <iostream>
using namespace std;

// Merges the two sorted halves into one
void merge (int a[], int b, int m, int e) {
  int work[e-b];
  int i=b, k=0;
  for (int j=m;i<m && j<e;++k) {
    if (a[i] <= a[j]) {
      work[k] = a[i++];
    } else {
      work[k] = a[j++];
    }
  }
  for (;i<m;++i,++k) {
    work[k] = a[i];
  }

  for (int i=0;i<k;++i) {
    a[b+i] = work[i];
  }
}

// Sorts the portion of array within the bounds specified by begin and end
void merge_sort (int a[], int begin, int end) {
  if (begin+1 >= end) {
    return;
  }
  
  int mid = (begin+end)/2;
  merge_sort(a, begin, mid);
  merge_sort(a, mid, end);

  merge(a, begin, mid, end);
}

void merge_sort(int a[], int n) {
  merge_sort(a, 0, n);
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i=0;i<n;++i) {
    cin >> a[i];
  }
  
  merge_sort(a, n);
  
  for (int i=0;i<n;++i) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
