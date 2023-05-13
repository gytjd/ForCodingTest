#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a > 10) {
			a = (a + 5) / 10 * 10;
		}
		if (a > 100) {
			a = (a + 50) / 100 * 100;
		}
		if (a > 1000) {
			a = (a + 500) / 1000 * 1000;
		}
		if (a > 10000) {
			a = (a + 5000) / 10000 * 10000;
		}
		if (a > 100000) {
			a = (a + 50000) / 100000 * 100000;
		}

		if (a > 1000000) {
			a = (a + 500000) / 1000000 * 1000000;
		}
		if (a > 10000000) {
			a = (a + 5000000) / 10000000 * 10000000;
		}
		cout << a << '\n';
	}
	return 0;
}