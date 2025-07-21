#include <iostream>

using namespace std;

int N;
char arr[8004][8004];

void init_() {
	for (int i = 0; i < N * 2 - 1; i++) {
		for (int j = 0; j < N * 2 - 1; j++) {
			arr[i][j] = ' ';
		}
	}
}
void display_() {

	for (int i = 0; i < N * 2 - 1; i++) {
		for (int j = 0; j < N * 2 - 1; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

void draw_(int x,int y) {

	arr[x][y] = '*';
	arr[x + 1][y - 1] = '*';
	arr[x + 1][y + 1] = '*';

	for (int i = y - 2; i < y + 3; i++) {
		arr[x + 2][i] = '*';
	}
}

void go_(int x,int y,int temp) {

	if (temp == 3) {
		draw_(x, y);
		return;
	}

	go_(x, y, temp / 2);
	go_(x+temp / 2, y - temp/2, temp / 2);
	go_(x+temp / 2, y + temp/2, temp / 2);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	init_();
	go_(0, (N * 2 - 1) / 2, N);
	display_();

	return 0;
}