#include <bits/stdc++.h>

using namespace std;

int main(void){
    int t;
    cin>>t;
    int sticks[31];
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> vec(n);
        for(int i=0; i<n; i++){
            int k;
            cin>>k;
            vector<int> prizes(k+1);
            for(int j=0; j<k; j++){
                int a;
                cin>>a;
                prizes[j] = a;
            }
            int prize;
            cin>>prize;
            prizes[k] = prize;
            vec[i] = prizes;
        }
        for(int i=1; i<=m; i++){
            int a;
            cin>>a;
            sticks[i] = a;
        }
        int sum = 0;
        for(int i=0; i<n; i++){
            int min = INT_MAX;
            for(int j=0; j<vec[i].size()-1; j++){
                if(min > sticks[vec[i][j]]) min = sticks[vec[i][j]];
            }
            sum += vec[i][vec[i].size()-1]*min;
        }
        cout<<sum<<endl;
    }
}