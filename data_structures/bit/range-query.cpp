#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;

vector<ll> bit;
vector<ll> arr;

int sum (int);
int add (int);

int query (int l, int r) {
  if (l == 0) return sum(r);
  return sum(r) - sum(l-1);
}

int sum (int index) {
  int num = 0;
  index++;
  while (index > 0) {
    num += bit[index];
    index -= (index & -index);
  }
  return num;
}

void add (int i, int v) {
  i++;
  while (i <= n) {
    bit[i] += v;
    i += (i & -i);
  }
}

int main (void) {
  cin >> n >> m;
  arr.resize(n);
  bit.resize(n+1);
  for (int i=0; i<m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) add (--b, c);
    else cout << query(--b, --c) << endl;
  }
  return 0;
}
