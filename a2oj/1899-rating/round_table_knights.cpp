#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (n % i != 0 || n / i < 3) {
            continue;
        }
        for (int j = 0; j < i; ++j) {
            bool good = true;
            for (int k = j; k < n; k += i) {
                if (!arr[k]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}