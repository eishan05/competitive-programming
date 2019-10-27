#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> bit1;
vector<int> bit2;
vector<int> arr;

void add (vector<int>& bit, int i, int val) {
  i++;
  while (i <= n) {
    bit[i] += val;
    i += (i & -i);
  }
}

int sum (vector<int>& bit, int i) {
  int num = 0;
  i++;
  while (i > 0) {
    num += bit[i];
    i -= (i & -i);
  }
  return num;
}

void update_range (int l, int r, int val) {
  add (bit1, l, val);
  add (bit1, r+1, -val);
  add (bit2, l, val*(l-1));
  add (bit2, r+1, -val*r);
}

int get_sum (int i) {
  return sum(bit1, i)*i - sum(bit2, i);
}

int range_sum (int l, int r) {
  return get_sum(r) - get_sum(l-1);
}

int main (void) {
  cin >> n >> m;
  arr.resize(n);
  bit1.resize(n+1);
  bit2.resize(n+1);
  for (int i=0; i<m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      int d;
      cin >> d;
      update_range(--b, --c, d);
    } else {
      cout << range_sum (--b, --c) << endl;
    }
  }
  return 0;
}
