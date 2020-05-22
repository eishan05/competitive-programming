#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> arr;
vector<vector<ll>> dp;
int n, m, k;

ll get_sum(int l, int r) {
    if (l == 1) {
        return arr[r];
    } else {
        return arr[r] - arr[l - 1];
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    arr.resize(n + 1);
    dp.resize(k + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i * m > j) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + get_sum(j - m + 1, j));
            }
        }
    }

    cout << dp[k][n] << endl;

}