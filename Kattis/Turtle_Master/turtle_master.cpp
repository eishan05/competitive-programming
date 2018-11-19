#include <bits/stdc++.h>

using namespace std;

enum direction{
    l = 0,
    r = 1,
    u = 2,
    d = 3
};

direction next_dir(direction curr, char next){
    switch(curr){
        case l: return (next == 'L')?d:u;
        case r: return (next == 'L')?u:d;
        case u: return (next == 'L')?l:r;
        case d: return (next == 'L')?r:l;
    }
}

bool within_bounds(int x, int y){
    return (x>=0 && x<8) && (y>=0 && y<8);
}

int main(void){
    vector<string> grid(8);
    for(int i=0; i<8; i++){
        cin>>grid[i];
    }
    string s;
    cin>>s;
    
    direction dir = r;
    vector<pair<int, int>> next(4);
    next[0] = make_pair(0, -1);
    next[1] = make_pair(0, 1);
    next[2] = make_pair(-1, 0);
    next[3] = make_pair(1, 0);
    pair<int, int> curr = make_pair(7, 0);
    for(int i=0; i<s.length(); i++){
        int x = curr.first;
        int y = curr.second;
        if(!within_bounds(x,y) || grid[x][y] == 'I' || grid[x][y] == 'C'){
            cout<<"Bug!";
            return 0;
        }
        switch(s[i]){
            case 'F': curr.first += next[dir].first;
                      curr.second += next[dir].second;
                      break;
            case 'R': dir = next_dir(dir, 'R'); 
                      break;
            case 'L': dir = next_dir(dir, 'L');
                      break;
            case 'X': int next_x = x + next[dir].first;
                      int next_y = y + next[dir].second;
                      if(!within_bounds(next_x, next_y) || grid[next_x][next_y] != 'I'){
                          cout<<"Bug!";
                          return 0;
                      }
                      else grid[next_x][next_y] = '.';
                      break;
        }
    }
    int x = curr.first;
    int y = curr.second;
    if(!within_bounds(x, y) || grid[x][y] != 'D'){
        cout<<"Bug!";
    }
    else cout<<"Diamond!";
    return 0;
}