#include<bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> sz;
int n;

int root(int x) {
    if (parent[x] == -1) {
        return x;
    }
    return parent[x] = root(parent[x]);
}

void join(int x, int y) {
    int px = root(x);
    int py = root(y);
    if (px != py) {
        if (sz[px] > sz[py]) {
            parent[py] = px;
            sz[px] += sz[py];
        }
        if (sz[px] <= sz[py]) {
            parent[px] = py;
            sz[py] += sz[px];
        }
    }
}

int get_size(int x) {
    int px = root(x);
    return sz[px];
}

bool is_lucky(int n) {
    while (n > 0) {
        int t = n % 10;
        if (t != 4 && t != 7) {
            return false;
        }
        n = n / 10;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long ans = 0;
    cin >> n;
    parent.resize(n + 1, -1);
    sz.resize(n + 1, 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (!is_lucky(c)) {
            join(a, b);
        }
    }

    for (int i = 1; i <= n; ++i) {
        long long rest = n - get_size(i);
        ans += rest * (rest - 1);
    }

    cout << ans << endl;
}

