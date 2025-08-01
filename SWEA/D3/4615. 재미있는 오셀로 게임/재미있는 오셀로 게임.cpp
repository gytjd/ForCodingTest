#include <iostream>
#include <cstring>

using namespace std;

int T;
int black_Cnt, white_Cnt;
int N, M;
int arr[10][10];
int dir[8][2] = { {0,1},{1,0},{0,-1},{-1,0},{-1,1},{1,1},{1,-1},{-1,-1} };


void init_() {

	black_Cnt = 0;
	white_Cnt = 0;

	memset(arr, 0, sizeof(arr));
	int x = N / 2;
	int y = N / 2;

	arr[x][y] = 2;
	arr[x + 1][y] = 1;
	arr[x][y + 1] = 1;
	arr[x + 1][y + 1] = 2;
}
void display_() {

	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 1) {
				black_Cnt += 1;
			}
			if (arr[i][j] == 2) {
				white_Cnt += 1;
			}
		}
	}
}

void BFS_iter(int x, int y, int curr) {

	int dx, dy;
	int check_Flag = 0;

	if (arr[x][y] == 0) {
		for (int i = 0; i < 8; i++) {

			dx = x;
			dy = y;
			check_Flag = 0;

			while (dx>0 and dx<=N and dy>0 and dy<=N) {
				dx = dx + dir[i][0];
				dy = dy + dir[i][1];

				if (arr[dx][dy] == 0) { // 빈곳이 있다
					check_Flag = 1;
					break;
				}

				if (arr[dx][dy] == curr) {
					check_Flag = 2;
					break;
				}
			}


			if (check_Flag==2) {
				while (true) {
					if (dx == x and dy == y) {
						arr[dx][dy] = curr;
						break;
					}

					arr[dx][dy] = curr;
					dx = dx - dir[i][0];
					dy = dy - dir[i][1];

				}
			}


		}

	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	for (int test = 1; test <= T; test++) {

		cin >> N >> M;

		init_();
		for (int i = 0; i < M; i++) {
			int x, y, curr;
			cin >> x >> y >> curr;
			BFS_iter(x, y, curr);
		}

		display_();
		cout << "#" << test << " " << black_Cnt << " " << white_Cnt << "\n";
	}

	return 0;
}