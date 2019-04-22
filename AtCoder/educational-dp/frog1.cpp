#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> bit;
vector<ll> arr;
int n, m;

//A problem with range updates and point queries

void update (int p, ll val) {
    while (p<=n) {
        bit[p] += val;
        p += p & (-p);
    }
}

void update_range (int l, int r, ll val) {
    update (l, val);
    update (r+1, -val);
}

ll query (int p) {
    ll sum = 0;
    while (p > 0) {
        sum += bit[p];
        p -= p & (-p);
    }
    return sum + bit[p];
}

int main(){
    cin >> n >> m;
    arr.resize(n);
    bit.resize(n+1);

    while (m--) {
        int l, r;
        ll val;
        cin >> l >> r >> val;
        update_range (l, r, val);
    }
    ll maxm = 0;
    for (int i=1; i<=n; i++) {
        maxm = max (maxm, query(i));
    }
    cout << maxm << endl;
    return 0;
}