#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
int ret,retIdx;
vector<pair<int, int>> v[100004];
int visited[100004];

void DFS_recur(int curr,int data) {

	if (ret < data) {
		ret = data;
		retIdx = curr;
	}

	for (pair<int, int> temp : v[curr]) {
		if (visited[temp.first] == 0) {
			visited[temp.first] = 1;
			DFS_recur(temp.first, data + temp.second);
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 1; i <= N; i++) {

		int data,end,weight;
		cin >> data;

		while (true) {
			cin >> end;

			if (end == -1) break;
			cin >> weight;
			v[data].push_back({ end,weight });
			v[end].push_back({ data,weight });
		}
	}

	visited[1]=1;
	DFS_recur(1, 0);

	memset(visited, 0, sizeof(visited));
	ret = 0;

	visited[retIdx] = 1;
	DFS_recur(retIdx, 0);

	cout << ret << "\n";

	return 0;
}