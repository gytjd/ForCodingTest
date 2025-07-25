#include <iostream>
#include <string>

using namespace std;

int ret;
int R, C, K;

int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
char arr[10][10];
int visited[10][10];

void display_() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void DFS_recur(int x, int y, int curr) {

	if (curr == K) {
		if (x == 0 and y == C - 1) {
			ret += 1;
		}
		return;
	}

	int dx, dy;
	for (int i = 0; i < 4; i++) {
		dx = x + dir[i][0];
		dy = y + dir[i][1];

		if (dx < 0 or dx >= R or dy < 0 or dy >= C or arr[dx][dy]=='T') {
			continue;
		}

		if (visited[dx][dy] == 0) {
			visited[dx][dy] = 1;
			DFS_recur(dx, dy, curr + 1);
			visited[dx][dy] = 0;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> R >> C >> K;

	for (int i = 0; i < R; i++) {

		string data;
		cin >> data;
		for (int j = 0; j < C; j++) {
			arr[i][j] = data[j];
		}
	}

	visited[R - 1][0] = 1;
	DFS_recur(R - 1, 0, 1);

	cout << ret << "\n";

	return 0;
}