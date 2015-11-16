/**
  * Given a target sum, find out the number of possible ways to achieve 
  * that sum by adding up the digits of a n-digit number, given n as input
  * 
  * Prasanth Kalapatapu
  * Nov 15, 2015
 */

#include <iostream>
#include <cstring>
using namespace std;

// assuming max values of 101 and 50001 for n and sum respectively
int sums[101][50001];

int count_numbers(int n, int sum) {
  if (n==0) {
    return (sum==0);
  }

  // memoization to avoid repeated calculations
  if (sums[n][sum] != -1) {
    return sums[n][sum];
  }

  int ans = 0;
  for (int i=0;i<=min(sum,9);++i) {
    ans += count_numbers(n-1, sum-i);
  }

  return sums[n][sum] = ans;
}

// Wrapper method to enforce non-zero first digit
int ndigit_count(int n, int sum) {
  memset (sums, -1, sizeof(sums));

  int ans=0;
  int end=min(sum,9);
  for (int i=1;i<=end;++i) {
    ans += count_numbers(n-1, sum-i);
  }

  return ans;
}

int main() {
  int n, sum;
  cin >> n >> sum;
  cout << ndigit_count(n, sum) << endl;
  return 0;
}

