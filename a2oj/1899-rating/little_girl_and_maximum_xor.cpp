#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    ll num = 1;
    ll i = 0;
    while (num <= r - l) {
        ans += num;
        num *= 2;
        ++i;
    }

    while (num <= r) {
        if ((((r >> i) ^ (l >> i)) & 1LL) == 1LL) {
            ans += num;
        }
        ++i;
        num *= 2;
    }
    cout << ans << endl;
}