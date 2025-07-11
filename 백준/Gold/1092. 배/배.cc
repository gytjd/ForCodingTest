#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v; // 크레인 무게
vector<int> w; // 박스 무게

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int data;
        cin >> data;
        w.push_back(data);
    }

    sort(v.rbegin(), v.rend()); // 크레인 무거운 순
    sort(w.rbegin(), w.rend()); // 박스 무거운 순

    if (v[0] < w[0]) {
        cout << -1 << "\n";
        return 0;
    }

    int ret = 0; // 걸린 시간 (분)
    vector<bool> moved(M, false); // 박스 옮겼는지 여부
    int movedCount = 0;

    while (movedCount < M) {
        int idx = 0;
        for (int i = 0; i < N; i++) {
            while (idx < M) {
                if (!moved[idx] && v[i] >= w[idx]) {
                    moved[idx] = true;
                    movedCount++;
                    idx++;
                    break;
                }
                idx++;
            }
        }
        ret++;
    }

    cout << ret << "\n";
    return 0;
}
