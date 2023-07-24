#include <iostream>
#include <map>
using namespace std;

int N, M;
map<int, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int data;
		cin >> data;
		m[data] = 1;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int data;
		cin >> data;

		if (m[data] == 1) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}

	return 0;
}