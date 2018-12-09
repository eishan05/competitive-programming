#include <bits/stdc++.h>

using namespace std;

int main(void){
	ifstream in;
	ofstream out;
	in.open("C-large-practice.in");
	out.open("large-practice-out.txt");

	int t;
	in>>t;
	int index = 1;
	while(t--){
		int n;
		in>>n;
		unordered_map<string, string> flights;
		unordered_set<string> to_flights;
		vector<string> from_flights(n);
		for(int i=0; i<n; i++){
			string to;
			in>>from_flights[i]>>to;
			to_flights.insert(to);
			flights.insert(make_pair(from_flights[i], to));
		}
		string first_flight;
		for(int i=0; i<n; i++){
			if(to_flights.find(from_flights[i]) == to_flights.end()){
				first_flight = from_flights[i];
				break;
			}
		}
		out<<"Case #"<<index<<": ";
		auto instance = flights.find(first_flight);
		while(instance != flights.end()){
			out<<instance->first<<"-"<<instance->second<<" ";
			instance = flights.find(instance->second);
		}
		out<<endl;
		index++;
	}
}