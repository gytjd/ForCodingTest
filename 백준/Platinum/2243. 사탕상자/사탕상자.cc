#include <iostream>

#define MAX_SIZE 1000004

using namespace std;

long long N;
long long A, B, C;
long long tree[4000004];

void update_(int node, int start, int end, long long idx, long long num) {

	if (idx<start or idx>end) {
		return;
	}

	if (start == idx and end == idx) {
		tree[node] += num;
		return;
	}

	update_(node * 2, start, (start + end) / 2, idx, num);
	update_(node * 2 + 1, (start + end) / 2 + 1, end, idx, num);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long sum_(int node, int start, int end, long long num) {

	if (start == end) {
		update_(1, 0, MAX_SIZE - 1, start, -1);
		return start + 1;
	}

	if (tree[node * 2] < num) {
		return sum_(node * 2 + 1, (start + end) / 2 + 1, end, num-tree[node*2]);
	}
	else {
		return sum_(node * 2, start, (start + end) / 2, num);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A;
		if (A & 1) {
			cin >> B;
			cout << sum_(1, 0, MAX_SIZE - 1, B) << "\n";
		}
		else {
			cin >> B >> C;
			update_(1, 0, MAX_SIZE - 1, B - 1, C);
		}
	}


	return 0;
}