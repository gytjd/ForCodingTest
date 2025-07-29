#include <iostream>
#include <string>

using namespace std;

int ret;
int N, M;
int arrA[54][54];
int arrB[54][54];

void change_(int x, int y) {

	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			arrA[i][j] = !arrA[i][j];
		}
	}
}

void go_() {

	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (arrA[i][j] != arrB[i][j]) {
				change_(i, j);
				ret += 1;
			}
		}
	}
}

bool check_() {

	bool check_Flag = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arrA[i][j] != arrB[i][j]) {
				check_Flag = true;
			}
		}
	}
	return check_Flag;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string data;
		cin >> data;
		for (int j = 0; j < M; j++) {
			arrA[i][j] = data[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		string data;
		cin >> data;
		for (int j = 0; j < M; j++) {
			arrB[i][j] = data[j] - '0';
		}
	}

	go_();
	if (check_()) {
		cout << -1 << "\n";
	}
	else {
		cout << ret << "\n";
	}

	return 0;
}