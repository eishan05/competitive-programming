#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;
vector<bool> marked;
// first is max1 and second is max2. max1 >= max2
vector<int> down;
vector<int> up;
int n, p, d;

int calc_down(int curr, int p) {
    down[curr] = marked[curr] ? 0 : -1;
    for (int next: tree[curr]) {
        if (next != p) {
            int d = calc_down(next, curr);
            if (d >= 0) {
                down[curr] = max(down[curr], d + 1);
            }
        }
    }
    return down[curr];
}

void calc_up(int curr, int p) {
    int max1 = -1, max2 = -1;
    for (int next: tree[curr]) {
        if (next != p) {
            if (down[next] > max1) {
                max2 = max1;
                max1 = down[next];
            } else if (down[next] > max2) {
                max2 = down[next];
            }
        }
    }

    for (int next: tree[curr]) {
        if (next != p) {
            int siblingDist = down[next] == max1 ? max2 : max1;
            if (siblingDist != -1) {
                siblingDist += 2;
            }
            up[next] = siblingDist;
            if (up[curr] != -1) {
                up[next] = max(up[next], up[curr] + 1);
            }
            if (marked[next]) {
                up[next] = max(up[next], 0);
            }
            calc_up(next, curr);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> p >> d;
    marked.resize(n + 1);
    tree.resize(n + 1);
    down.resize(n + 1);
    up.resize(n + 1);

    for (int i = 0; i < p; ++i) {
        int a;
        cin >> a;
        marked[a] = true;
    }

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    up[1] = marked[1] - 1;

    calc_down(1, -1);
    calc_up(1, -1);

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        // cout << i << " " << down[i] << " " << up[i] << endl;
        if (down[i] <= d && up[i] <= d) {
            ++ans;
        }
    }
    cout << ans << endl;
}