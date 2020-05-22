#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int lo = 0, hi = n / 2, ans;
    while (lo <= hi) {
        int mid = ((hi - lo) >> 1) + lo;
        bool good = true;
        for (int i = mid - 1; i >= 0; --i) {
            if (2*arr[i] > arr[n + i - mid]) {
                good = false;
                break;
            }
        }
        if (good) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << n - ans << endl;
}