/**
  * The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path
  * problem. The problem is to find shortest distances between every pair of 
  * vertices in a given edge weighted directed Graph. Works for both positive
  * and negative weights, but not for negative cycles.
  * -- Sample input --
  * 4
  * 0 5 INF 10
  * INF 0 3 INF
  * INF INF 0 1
  * INF INF INF 0
  *
  * Prasanth Kalapatapu
  * Nov 5, 2015
  */

#define INF 999999

#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {

  // Input
  int n; // number of vertices
  cin >> n;
  int adj[n][n]; // weighted adjacency matrix 
  for (int i=0;i<n;++i) {
    for (int j=0;j<n;++j) {
      string cur;
      cin >> cur;
      if (cur.compare("INF") == 0) {
	adj[i][j] = INF;
      } else if (!(stringstream(cur) >> adj[i][j])) {
	cerr << "error reading input ... exiting" << endl;
	return 1;
      }
    }
  }

  // Algorithm
  // Consider each vertex as an intermediary
  for (int k=0;k<n;++k) {
    // Check the intermediary vertex for all vertex pairs
    for (int i=0;i<n;++i) {
      for (int j=0;j<n;++j) {
	int with_interm; // weight using the intermediate vertex
	if (adj[i][k] == INF || adj[k][j] == INF) {
	  with_interm = INF;
	} else {
	  with_interm = adj[i][k] + adj[k][j];
	}
	
	if(with_interm < adj[i][j]) {
	  adj[i][j] = with_interm;
	}
      }
    }
  }

  // Output
  for (int i=0;i<n;++i) {
    for (int j=0;j<n;++j) {
      if (adj[i][j] == INF) {
	cout << setw(8) << "INF";
      } else {
	cout << setw(8) << adj[i][j];
      }
    }
    cout << endl;
  }

  return 0;
}
