#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> s[26]; //해당 알파뱃이 나타나는 인덱스를 저장
char str[2001];
int N, l, r;
char a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> str;
	for (int i = 0; str[i] != 0; i++)
		s[str[i] - 'a'].push_back(i);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> l >> r;
		int alpha = a - 'a';
		auto it1 = lower_bound(s[alpha].begin(), s[alpha].end(), l);
		auto it2 = upper_bound(s[alpha].begin(), s[alpha].end(), r);
		cout << it2 - it1 << '\n';
	}
	return 0;
}