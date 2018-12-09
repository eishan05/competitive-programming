#include <bits/stdc++.h>

using namespace std;

int main(void){
	ofstream out;
	ifstream num;
	ifstream in;
	out.open("out.txt");
	num.open("number.txt");
	in.open("B-small-practice.in");
	string s;
	num>>s;
	int t;
	in>>t;
	int index=1;
	while(t--){
		int k;
		in>>k;
		out<<"Case #"<<index<<": "<<s[k-1]<<endl;
		index++;
	}
	return 0;
}