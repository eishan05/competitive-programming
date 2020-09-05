#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    ll sum = 0;
    sort(arr.begin(), arr.end());
    for (int t: arr) {
        sum += abs(t - arr[n / 2]);
    }
    cout << sum << endl;
}