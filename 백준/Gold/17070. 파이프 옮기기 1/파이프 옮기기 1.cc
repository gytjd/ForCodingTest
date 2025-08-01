#include <iostream>
#include <cstring>

using namespace std;

int N;
int ret;
int arr[20][20];
int visited[3][20][20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memset(arr, 1, sizeof(arr));

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	visited[0][1][2] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			if (i == 1 and (j == 1 or j==2)) continue;
			if (arr[i][j]==0) {
				visited[0][i][j] = visited[0][i][j - 1] + visited[2][i][j - 1];
				visited[1][i][j] = visited[1][i - 1][j] + visited[2][i - 1][j];
			}

			if (arr[i][j] == 0 and arr[i][j - 1] == 0 and arr[i - 1][j] == 0) {
				visited[2][i][j] = visited[0][i - 1][j - 1] + visited[1][i - 1][j - 1] + visited[2][i - 1][j - 1];
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		ret += visited[i][N][N];
	}

	cout << ret << "\n";

	return 0;
}