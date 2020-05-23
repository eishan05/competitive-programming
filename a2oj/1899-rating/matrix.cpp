#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int count_zeroes(string s) {
    int num = 0;
    for (char c: s) {
        if (c == '0') {
            ++num;
        }
    }
    return num;
}

int main() {
    int a;
    cin >> a;
    string s;
    cin >> s;
    unordered_map<int, ll> m;
    ll ans = 0;
    if (a == 0) {
        ll num_zero = 0;
        for (int i = 0; i < s.length(); ++i) {
            int sum = 0;
            for (int j = i; j < s.length(); ++j) {
                sum += s[j] - '0';
                if (sum == 0) {
                    ++num_zero;
                }
            }
        }
        ll n = s.length();
        ans = n * (n + 1) * num_zero - num_zero * num_zero;
        cout << ans << endl;
        return 0;
    }
    for (int i = 0; i < s.length(); ++i) {
        int sum = 0;
        for (int j = i; j < s.length(); ++j) {
            sum += s[j] - '0';
            m[sum]++;
        }
    }
    for (int i = 0; i < s.length(); ++i) {
        int sum = 0;
        for (int j = i; j < s.length(); ++j) {
            sum += s[j] - '0';
            if (sum != 0 && a % sum == 0) {
                ans += m[a / sum];
            }
        }
    }
    cout << ans << endl;
}