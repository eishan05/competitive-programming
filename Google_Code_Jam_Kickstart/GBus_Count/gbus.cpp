#include <bits/stdc++.h>

using namespace std;


int check(vector<pair<int, int>>& ranges, int city){
	int num=0;
	for(int i=0; i<ranges.size(); i++){
		if(city<= ranges[i].second && city >= ranges[i].first) num++;
	}
	return num;
}

int main(void){
	ifstream in;
	ofstream out;
	in.open("A-large-practice.in");
	out.open("output.txt");
	if(!in.is_open()) {
		cout<<"Error, can't open file\n";
		return 0;
	}
	int t;
	in>>t;
	int index = 1;
	while(t--){
		int n;
		in>>n;
		vector<pair<int, int>> ranges(n);
		for(int i=0; i<n; i++){
			int a, b;
			in>>a>>b;
			ranges[i] = make_pair(a, b);
		}
		out<<"Case #"<<index<<": ";
		int p;
		in>>p;
		for(int i=0; i<p; i++){
			int city;
			in>>city;
			out<<check(ranges, city)<<" ";
		}
		out<<endl;
		index++;
	}
	return 0;
}