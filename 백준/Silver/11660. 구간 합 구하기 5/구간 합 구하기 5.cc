#include <iostream>

using namespace std;

int N, M;
int arr[1028][1028];

void init_() {

	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			arr[i][j] += arr[i][j - 1];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			arr[j][i] += arr[j - 1][i];
		}
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	init_();

	for (int i = 0; i < M; i++) {
		int startX, startY, endX, endY;
		cin >> startX >> startY >> endX >> endY;

		cout << arr[endX][endY] - arr[endX][startY - 1] - arr[startX - 1][endY] + arr[startX - 1][startY - 1] << "\n";
	}


	return 0;
}