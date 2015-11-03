/**
 * Given the index number of a column in Microsoft Excel, compute the alphabet code for that column
 * Example: AA for 27, BD for 56, ZZ for 702 and AAA for 703
 * Nov 2, 2015
 * Author: Prasanth Kalapatapu
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n;
  cin >> n;
  while(n>0) {
    string output;
    int rem, factor1, factor2;
    int exp=1;
    while(n) {
      factor1=pow(26,exp);
      factor2=pow(26,exp-1);
      rem = (n%factor1)/factor2;
      if (rem==0) {
	rem=26;
      }
      output.insert(0, 1, static_cast<char>('A'+rem-1));
      n-=rem*factor2;
      ++exp;
    }
    cout << output << endl;
    cin >> n;
  }
  cout << "exiting ..." << endl;
  return 0;
}
