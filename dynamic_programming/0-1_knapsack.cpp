/**
  * Given weights and values of n items, put these items in a knapsack of 
  * capacity W to get the maximum total value in the knapsack.
  * You can either pick or do not pick an item (0-1 property).
  * 
  * --- Example ---
  * val={60, 100, 120} wt={10, 20, 30} W=50
  * maximum value = 220
  * ---------------
  *
  * Prasanth Kalapatapu
  * Nov 5, 2015
  */

#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int val[n], wt[n];
  for (int i=0;i<n;++i) {
    cin >> val[i];
  }
  for (int i=0;i<n;++i) {
    cin >> wt[i];
  }
  int max_wt;
  cin >> max_wt;

  // ks[i][j] stores the max value for max_weight=i and first j input elements
  int ks[max_wt+1][n+1];
  for (int i=0;i<=n;++i) {
    ks[0][i]=0;
  }
  for (int i=0;i<=max_wt;++i) {
    ks[i][0]=0;
  }

  for (int i=1;i<=max_wt;++i) {
    for (int j=1;j<=n;++j) {
      int no_sel = ks[i][j-1];
      int sel = (i>=wt[j-1]) ? ks[i-wt[j-1]][j-1]+val[j-1] : 0;
      ks[i][j] = max(no_sel, sel);
    }
  }

  cout << ks[max_wt][n] << endl;
  return 0;
}

