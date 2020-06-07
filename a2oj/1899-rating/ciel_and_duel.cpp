#include<bits/stdc++.h>

using namespace std;

vector<int> arr;
vector<int> attack;
vector<int> defense;
vector<bool> used;
int n, m;

int get_upper(int x) {
    for (int i = 0; i < m; ++i) {
        if (arr[i] >= x && !used[i]) {
            used[i] = true;
            return i;
        }
    }
    return -1;
}

int destroy_attacks() {
    int ret = 0;
    for (int i = arr.size() - 1, j = 0; i >= 0 && j < attack.size(); --i, ++j) {
        ret += max(arr[i] - attack[j], 0);
    }
    return ret;
}

int destroy_defense_too() {
    int def = 0;
    int att = 0;
    int tot = 0;

    for (int i: defense) {
        int x = get_upper(i + 1);
        if (x == -1) {
            return 0;
        }
        def += arr[x];
    }

    for (int i: attack) {
        int x = get_upper(i);
        if (x == -1) {
            return 0;
        }
        att += i;
    }

    for (int i: arr) {
        tot += i;
    }
    return tot - def - att;
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int a;
        cin >> a;
        if (s == "ATK") {
            attack.push_back(a);
        } else {
            defense.push_back(a);
        }
    }
    arr.resize(m);
    used.resize(m);

    for (int i = 0; i < m; ++i) {
        cin >> arr[i];
    }

    sort(attack.begin(), attack.end());
    sort(defense.begin(), defense.end());
    sort(arr.begin(), arr.end());

    cout << max(destroy_attacks(), destroy_defense_too()) << endl;

    return 0;
}