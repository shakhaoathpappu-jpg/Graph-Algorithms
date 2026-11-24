#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t; cin >> t;
  for(int i = 0; i < t; i++){
    int n; cin >> n;
    vector<vector<char>> b(n, vector<char>(n));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        cin >> b[j][k];
      }
    }
    for (int j = 0; j < n; j++){
      b[j][j] = '1';
    }
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        for (int l = 0; l < n; l++){
          if (b[k][j] == '1' && b[j][l] == '1'){
            b[k][l] = '1';
          }
        }
      }
    }
    vector<vector<int>> A(n);
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        if (b[k][j] == '1'){
          A[j].push_back(k);
        }
      }
    }
    for (int j = 0; j < n; j++){
      int s = A[j].size();
      cout << s;
      for (int k = 0; k < s; k++){
        cout << ' ' << A[j][k] + 1;
      }
      cout << endl;
    }
  }
}