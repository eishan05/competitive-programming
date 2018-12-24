#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>>& tree, vector<int>& index, int curr, int& num){
    for(int i=0; i<tree[curr].size(); i++){
        index[curr] += dfs(tree, index, tree[curr][i], num);
    }
    index[curr]++;          //include itself
    if(index[curr]%2 == 0 && curr != 1){  //no incoming edges to the root (1), so exclude it!
        num++;
        index[curr] = 0;
    }
    return index[curr];
}

int main(void){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> tree(n+1);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        tree[b].push_back(a);
    }
    vector<int> index(n+1);
    int num = 0;
    dfs(tree, index, 1, num);
    cout<<num;
    return 0;
}

