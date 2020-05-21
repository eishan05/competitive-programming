#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}

int main() {
    ll n;
    cin >> n;
    ll maxm = 0;
    for (int i = 0; i < min(50ll, n); ++i) {
        for (int j = i; j < min(50ll, n); ++j) {
            for (int k = j; k < min(50ll, n); ++k) {
                maxm = max(maxm, lcm(n - i, lcm(n - j, n - k)));
            }
        }
    }
    cout << maxm << endl;
}