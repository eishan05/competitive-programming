#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int get_mid(int l, int r) {
    return ((r - l) >> 1) + l;
}

inline int left(int curr) {
    return curr << 1;
}

inline int right(int curr) {
    return (curr << 1) + 1;
}

void update(int curr, int treeL, int treeR, int l, int r, vector<ll>& tree, ll addend) {
    if (l > r) {
        return;
    }
    if (treeL == l && treeR == r) {
        tree[curr] += addend;
    } else {
        int mid = get_mid(treeL, treeR);
        update(left(curr), treeL, mid, l, min(r, mid), tree, addend);
        update(right(curr), mid + 1, treeR, max(mid + 1, l), r, tree, addend);
    }
}

ll query(int curr, int l, int r, int pos, vector<ll>& tree) {
    if (l == r) {
        return tree[curr];
    } else {
        int mid = get_mid(l, r);
        if (pos <= mid) {
            return tree[curr] + query(left(curr), l, mid, pos, tree);
        } else {
            return tree[curr] + query(right(curr), mid + 1, r, pos, tree);
        }
    }
}

struct cmp {
    // a.first == freq, a.second == index
    bool operator() (pair<ll, int> a, pair<ll, int> b) {
        return a.first < b.first;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    vector<pair<int, int>> queries(q);
    vector<ll> freq(4*n);
    vector<pair<ll, int>> pq;
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
        queries[i].first--, queries[i].second--;
        update(1, 0, n - 1, queries[i].first, queries[i].second, freq, 1);
    }

    for (int i = 0; i < n; ++i) {
        pq.push_back({query(1, 0, n - 1, i, freq), i});
    }

    sort(arr.begin(), arr.end());
    cmp c;
    sort(pq.begin(), pq.end(), c);
    vector<ll> vec(n);
    for (int i = n - 1; i >= 0; --i) {
        vec[pq[i].second] = arr[i];
    }
    for (int i = 1; i < n; ++i) {
        vec[i] += vec[i - 1];
    }
    ll ans = 0;
    for (pair<int, int> qu: queries) {
        if (qu.first == 0) {
            ans += vec[qu.second];
        } else {
            ans += vec[qu.second] - vec[qu.first - 1];
        }
    }
    cout << ans << endl;
}