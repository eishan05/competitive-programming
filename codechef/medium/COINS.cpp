#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long ll;

vector<ll> dp;

ll doDp(ll n) {
  if (dp[n] != -1) {
    return dp[n];
  }
  if (n == 0) return 0;
  return dp[n] = max(doDp(n/2) + doDp(n/3) + doDp(n/4), n);
}

int main (void) {
  ll n;
  while(cin >> n) {
    ll one = n/2;
    ll two = n/3;
    ll three = n/4;
    dp.resize(one + 1, -1);
    cout << max(doDp(one) + doDp(two) + doDp(three), (ll)n) << endl;
    //cout << doDp(dp, n) << endl;
  }
  return 0;
}
