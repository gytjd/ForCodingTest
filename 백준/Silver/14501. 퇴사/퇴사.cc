#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int ret;
vector<pair<int, int>> v;
int visited[20];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	v.push_back({ 0,0 });
	for (int i = 0; i < N; i++) {
		int T, P;
		cin >> T >> P;
		v.push_back({ T,P });
	}

	for (int i = 1; i <= N; i++) {

		if (v[i].first + i > N+1) {
			continue;
		}

		int temp = 0;
		for (int j = 0; j < i; j++) {
			if (v[j].first + j <= i) {
				temp = max(temp, visited[j]);
			}
		}
		visited[i] = temp + v[i].second;
		ret = max(ret, visited[i]);
	}

	cout << ret << "\n";

	return 0;
}