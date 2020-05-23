#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 100000000

ll dp[110][110][2][11];
ll maxConsecPawn, maxConsecKnight;

// last == 1 if pawn, else 2
ll recurse(int pawn, int knight, int last, int consec) {
    if (dp[pawn][knight][last][consec] != -1) {
        return dp[pawn][knight][last][consec];
    }
    ll ans = 0;
    if (last == 1) {
        if (pawn > 0 && consec < maxConsecPawn) {
            ans = (ans + recurse(pawn - 1, knight, 1, consec + 1)) % MOD;
        }
        if (knight > 0) {
            ans = (ans + recurse(pawn, knight - 1, 2, 1)) % MOD;
        }
    } else {
        if (knight > 0 && consec < maxConsecKnight) {
            ans = (ans + recurse(pawn, knight - 1, 2, consec + 1)) % MOD;
        }
        if (pawn > 0) {
            ans = (ans + recurse(pawn - 1, knight, 1, 1)) % MOD;
        }
    }
    if (pawn == 0 && knight == 0) {
        return dp[pawn][knight][last][consec] = 1;
    }
    return dp[pawn][knight][last][consec] = ans;
}

int main() {
    for (int i = 0; i < 110; ++i) {
        for (int j = 0; j < 110; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 11; ++l) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
    int pawn, knight;
    cin >> pawn >> knight >> maxConsecPawn >> maxConsecKnight;
    cout << recurse(pawn, knight, 1, 0) << endl;
}