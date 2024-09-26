#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int,int>> v;

int main() {
	
	cin >> N;
	for(int i=0;i<N;i++) {
		int data;
		cin >> data;
		v.push_back({data,i});
	}
	
	sort(v.begin(),v.end(),greater<>());
	
	for(int i=0;i<3;i++) {
		cout << v[i].second+1 << " ";
	}
	cout << "\n";
	return 0;
}