#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(vector<string>& grid){
    for(int i=0; i<grid.size(); i++){
        cout<<grid[i]<<endl;
    }
}

void input(vector<string>& grid){
    for(int i=0; i<grid.size(); i++){
        cin>>grid[i];
    }
}

void work(vector<string>& grid){
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
            if(grid[i][j] == '*') continue;
            int num = 0;
            //vertical and horizontal
            if(i>0 && grid[i-1][j] == '*') num++;
            if(i<grid.size()-1 && grid[i+1][j] == '*') num++;
            if(j>0 && grid[i][j-1] == '*') num++;
            if(j<grid[i].length()-1 && grid[i][j+1] == '*') num++;
            //diagonal
            if(i>0 && j>0 && grid[i-1][j-1] == '*') num++;
            if(i>0 && j<grid[i].length()-1 && grid[i-1][j+1] == '*') num++;
            if(i<grid.size()-1 && j>0 && grid[i+1][j-1] == '*') num++;
            if(i<grid.size()-1 && j<grid[i].length()-1 && grid[i+1][j+1] == '*') num++;
            
            grid[i][j] = (char)(num + '0');
        }
    }
}

int main(void){
	int n, m;
	cin>>n>>m;
	int index = 1;
	while(n!=0 || m!=0){
	    vector<string> grid(n);
	    input(grid);
	    work(grid);
	    cout<<"Field #"<<index<<":\n";
	    print(grid);
	    cin>>n>>m;
	    if(n==0 && m==0) break;
	    cout<<"\n";
	    index++;
	}
	return 0;
}