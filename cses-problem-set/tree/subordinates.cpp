#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> tree;
vector<int> ans;

int dfs(int curr) {
    int num = 0;
    for (int next: tree[curr]) {
        num += dfs(next);
    }
    ans[curr] = num;
    return num + 1;
}

int main() {
    cin >> n;
    tree.resize(n + 1);
    ans.resize(n + 1);
    for (int i = 2 ; i <= n; ++i) {
        int a;
        cin >> a;
        tree[a].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}