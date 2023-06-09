
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <math.h>
#include <memory.h>
#include <set>
using namespace std;

void solve() {
    vector<pair<int,int> > v[2001];
    bool candi[2001] = { 0, };
    int n, m, t;
    cin >> n >> m >> t;
    int s, g, h;
    cin >> s >> g >> h;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
    }
    for (int i = 0; i < t; i++) {
        int num;
        cin >> num;
        candi[num] = 1;
    }

    priority_queue<pair<int, int>, vector<pair<int, int> > > pq;
    int dist[2001];
    fill(dist, dist + 2001, 2e9);
    dist[s] = 0;
    pq.push({ 0, s });
    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();
        for (auto nxt : v[node]) {
            if (dist[nxt.first] > dist[node] + nxt.second) {
                dist[nxt.first] = dist[node] + nxt.second;
                pq.push({ -dist[nxt.first], nxt.first });
            }
        }
    }
    int disth[2001];
    fill(disth, disth + 2001, 2e9);
    disth[h] = 0;
    pq.push({ 0, h });
    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();
        for (auto nxt : v[node]) {
            if (disth[nxt.first] > disth[node] + nxt.second) {
                disth[nxt.first] = disth[node] + nxt.second;
                pq.push({ -disth[nxt.first], nxt.first });
            }
        }
    }

    int distg[2001];
    fill(distg, distg + 2001, 2e9);
    distg[g] = 0;
    pq.push({ 0, g });
    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();
        for (auto nxt : v[node]) {
            if (distg[nxt.first] > distg[node] + nxt.second) {
                distg[nxt.first] = distg[node] + nxt.second;
                pq.push({ -distg[nxt.first], nxt.first });
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (candi[i]) {
            if (dist[i] == min(disth[i] + dist[g] + distg[h], distg[i] + dist[h] + disth[g])) {
                cout << i << " ";
            }
        }
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (; t--;) {
        solve();
    }
}
