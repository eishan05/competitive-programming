#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAXM 200100

// Number of elements = n

// resize to 4*n 
vector<ll> segtree;
vector<ll> lazy;
// resize to n
vector<ll> arr;

inline int get_mid(int l, int r) {
   return ((r - l) >> 1) + l;
}

inline int left(int curr) {
   return curr << 1;
}

inline int right(int curr) {
   return (curr << 1) + 1;
}

// override the merge for different functionality
ll merge(ll l, ll r) {
  return l + r;
}

// usage: build(1, 0, n - 1)
void build(int curr, int l, int r) {
  if (l == r) {
    segtree[curr] = arr[l];
  } else {
    int mid = get_mid(l, r);
    build(left(curr), l, mid);
    build(right(curr), mid + 1, r);
    segtree[curr] = merge(segtree[left(curr)], segtree[right(curr)]);
  }
}

void push(int curr, int curr_l, int curr_r) {
   int l = left(curr);
   int r = right(curr);
   lazy[l] += lazy[curr];
   lazy[r] += lazy[curr];
   int mid = get_mid(curr_l, curr_r);
   segtree[l] += (mid - curr_l + 1)*lazy[curr];
   segtree[r] += (curr_r - mid)*lazy[curr];
   lazy[curr] = 0;
}

// range update
// usage: update(1, 0, n - 1, l, r, addend)
// all indices 0 based
void update(int curr, int treeL, int treeR, int l, int r, ll addend) {
   if (l > r) {
      return;
   }
   if (treeL == l && treeR == r) {
      segtree[curr] += (treeR - treeL + 1)*addend;
      lazy[curr] += addend;
   } else {
      push(curr, treeL, treeR);
      int mid = get_mid(treeL, treeR);
      update(left(curr), treeL, mid, l, min(r, mid), addend);
      update(right(curr), mid + 1, treeR, max(l, mid + 1), r, addend);
      segtree[curr] = merge(segtree[left(curr)], segtree[right(curr)]);
   }
}

// range query
// usage: query(1, 0, n - 1, l, r)
// all indices are 0 based
ll query(int curr, int treeL, int treeR, int l, int r) {
   if (l > r) return 0;
   if (treeL == l && treeR == r) {
      return segtree[curr];
   } else {
      push(curr, treeL, treeR);
      int mid = get_mid(treeL, treeR);
      return merge(query(left(curr), treeL, mid, l, min(mid, r)), query(right(curr), mid + 1, treeR, max(l, mid + 1), r));
   }
}

int main() { 
  arr = {1, 2, 3, 4, 5};
  int n = arr.size();
  segtree.resize(4*n);
  lazy.resize(4*n);
  build(1, 0, n - 1);
  // expected output: 1 2 3 4 5
  for (int i = 0; i < n; ++i) {
    cout << query(1, 0, n - 1, i, i) << " ";
  }
  cout << endl;

  // expected output: 1 3 6 10 15
  for (int i = 0; i < n; ++i) {
    cout << query(1, 0, n - 1, 0, i) << " ";
  }
  cout << endl;

  update(1, 0, n - 1, 1, 3, 2);
  // expected output: 1 4 5 6 5
  for (int i = 0; i < n; ++i) {
    cout << query(1, 0, n - 1, i, i) << " ";
  }
  cout << endl;

  // expected output: 21, 20, 16, 11, 5
  for (int i = 0; i < n; ++i) {
    cout << query(1, 0, n - 1, i, n - 1) << " ";
  }
  cout << endl;
}








