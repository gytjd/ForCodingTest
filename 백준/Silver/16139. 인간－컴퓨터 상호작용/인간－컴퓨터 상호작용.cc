#include <iostream>
using namespace std;

int subsum[2001][26];
char str[2001];
int N, l, r;
char a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> str >> N;
	for (int i = 0; str[i] != 0; i++)
		subsum[i + 1][str[i] - 'a'] = 1;
	for (int i = 0; str[i + 1] != 0; i++)
		for (int j = 0; j < 26; j++)
			subsum[i + 2][j] += subsum[i + 1][j];
	
	for (int i = 0; i < N; i++) {
		cin >> a >> l >> r;
		cout << subsum[r + 1][a - 'a'] - subsum[l][a - 'a'] << '\n';
	}
	return 0;
}