#include<bits/stdc++.h>

using namespace std;

vector<string> grid;
vector<vector<bool>> seen;
vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;

bool inside(pair<int, int> p) {
    return p.first >= 0 && p.first < n && p.second >= 0 && p.second < m;
}

void dfs(pair<int, int> curr) {
    seen[curr.first][curr.second] = true;
    for (pair<int, int> d: dir) {
        pair<int, int> next = {curr.first + d.first, curr.second + d.second};
        if (inside(next) && grid[next.first][next.second] == '.' && !seen[next.first][next.second]) {
            dfs(next);
        }
    }
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    seen.resize(n, vector<bool>(m));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!seen[i][j] && grid[i][j] == '.') {
                dfs({i, j});
                ++ans;
            }
        }
    }

    cout << ans << endl;

}