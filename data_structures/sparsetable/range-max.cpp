#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<int> log(n + 1);

  for (int i = 2; i <= n; i++) {
    log[i] = log[i / 2] + 1;
  }

  vector<vector<int>> sparse(n, vector<int>(log[n] + 1));

  for (int i = 0; i < sparse.size(); i++) {
    sparse[i][0] = arr[i];
  }

  for (int row = 1; row <= log[n]; row++) {
    for (int i = 0; i + (1 << row) <= n; i++) {
      sparse[i][row] = max(sparse[i][row-1], sparse[i + (1 << (row -1))][row - 1]);
    }
  }

  int ans = 0;

  while(q--) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    if (abs(a - b) <= 1) {
      ans++;
      continue;
    }
    int big = max(a, b) - 1;
    int less = min(a,b) + 1;
    int index = log[big - less + 1];
    int query = max(sparse[less][index], sparse[big - (1 << index) + 1][index]); 
    if (query < arr[a]) {
      ans++;
    }
  }
  cout << ans << endl;
}
