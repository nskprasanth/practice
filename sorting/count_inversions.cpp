/**
  * Given an array of integers, count the number of inversions found
  * Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j 
  *
  * Prasanth Kalapatapu
  * Nov 12, 2015
  */

#include <iostream>
using namespace std;

int merge (int a[], int b, int m, int e) {
  int count = 0;
  int i=b, k=0;
  int work[e-b];
  for (int j=m;i<m && j<e;++k) {
    if (a[i] > a[j]) {
      work[k] = a[j++];
      count += m-i;
    } else {
      work[k] = a[i++];
    }
  }

  for (;i<m;++i,++k) {
    work[k] = a[i];
  }

  for (int i=0;i<k;++i) {
    a[b+i] = work[i];
  }

  return count;
}

int count_inversions(int a[], int begin, int end) {
  if (begin+1 >= end) {
    return 0;
  }
  
  int mid = (begin+end)/2;
  int count = count_inversions(a, begin, mid);
  count += count_inversions(a, mid, end);
  count +=merge(a, begin, mid, end);
  
  return count;
}

int count_inversions(int a[], int n) {
  count_inversions(a, 0, n);
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i=0;i<n;++i) {
    cin >> a[i];
  }

  cout << count_inversions(a,n) << endl;
  return 0;
}
