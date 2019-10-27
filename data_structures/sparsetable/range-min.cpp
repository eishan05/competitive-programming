#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // Log table
  vector<int>log(n + 1);
  log[1] = 0;
  for (int i = 2; i <= n; i++) {
    log[i] = log[i / 2] + 1;
  }

  vector<vector<int>> sparse (n, vector<int>(log[n] + 1));

  for (int i = 0; i < n; i++) {
    sparse[i][0] = arr[i]; 
  }

  for (int row = 1; row <= log[n]; row++) {
    for (int i = 0; i + (1 << row) <= n; i++) {
      sparse[i][row] = min(sparse[i][row - 1], sparse[i + (1 << (row - 1))][row - 1]);
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    int index = log[r - l + 1];
    cout << min(sparse[l][index], sparse[r - (1 << index) + 1][index]) << endl;
  }

}
