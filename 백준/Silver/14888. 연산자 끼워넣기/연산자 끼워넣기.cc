#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long N;
long long maxRet = -10999999999;
long long minRet = 10999999999;

vector<long long> v;
vector<long long> com;

void go_(long long curr,long long Num) {

	if (curr == N) {
		maxRet = max(maxRet, Num);
		minRet = min(minRet, Num);
		return;
	}

	if (com[0]) {
		com[0] -= 1;
		go_(curr + 1, Num + v[curr]);
		com[0] += 1;
	}

	if (com[1]) {
		com[1] -= 1;
		go_(curr + 1, Num - v[curr]);
		com[1] += 1;
	}

	if (com[2]) {
		com[2] -= 1;
		go_(curr + 1, Num * v[curr]);
		com[2] += 1;
	}

	if (com[3]) {
		com[3] -= 1;
		go_(curr + 1, Num / v[curr]);
		com[3] += 1;
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (long long i = 0; i < N; i++) {
		long long data;
		cin >> data;
		v.push_back(data);
	}

	for (long long i = 0; i < 4; i++) {
		long long data;
		cin >> data;
		com.push_back(data);
	}

	go_(1, v[0]);
	cout << maxRet << "\n";
	cout << minRet << "\n";

	return 0;
}