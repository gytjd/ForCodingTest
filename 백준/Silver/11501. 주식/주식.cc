#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long T,N;
vector<long long> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	for (long long test = 0; test < T; test++) {

		v.clear();

		cin >> N;
		for (long long i = 0; i < N; i++) {
			long long data;
			cin >> data;
			v.push_back(data);
		}

		long long ret = 0;
		long long temp_Max = 0;
		for (long long i = N - 1; i >= 0; i--) {
			temp_Max = max(temp_Max, v[i]);
			ret += temp_Max - v[i];
		}

		cout << ret << "\n";
	}

	return 0;
}