#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int data, like, day;
};

struct cmp {
	bool operator()(Node &a, Node &b) {
		if (a.like == b.like) {
			return a.day > b.day;
		}
		return a.like>b.like;
	}
};

int N, M;
priority_queue <Node, vector<Node>, cmp> q;
vector<int> ret;
int visited[104];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int data;
		cin >> data;

		if (visited[data] == 0) {
			if (q.size() < N) {
				visited[data] += 1;
				q.push({ data,visited[data],i });
			}
			else {
				visited[q.top().data] = 0;
				q.pop();

				visited[data] += 1;
				q.push({ data,visited[data],i });
			}
		}
		else {
			visited[data] += 1;
			vector<Node> temp;
			while (!q.empty()) {
				if (q.top().data == data) {
					temp.push_back({ q.top().data,q.top().like + 1,q.top().day });
				}
				else {
					temp.push_back({ q.top().data,q.top().like,q.top().day });
				}
				q.pop();
			}

			for (Node a : temp) {
				q.push(a);
			}
		}
	}


	while (!q.empty()) {
		ret.push_back(q.top().data);
		q.pop();
	}
	sort(ret.begin(), ret.end());
	for (int a : ret) {
		cout << a << " ";
	}
	cout << "\n";

	return 0;
}