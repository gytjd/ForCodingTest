#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, D, K, C, ret;
vector<int> v;
int cnt[3001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> D >> K >> C;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int kind = 0;


    for (int i = 0; i < K; i++) {
        if (cnt[v[i]]++ == 0) kind++;
    }

    ret = (cnt[C] == 0) ? kind + 1 : kind;


    for (int i = 1; i < N; i++) {
        
        if (--cnt[v[i - 1]] == 0) kind--;

    
        int next = v[(i + K - 1) % N];
        if (cnt[next]++ == 0) kind++;

        int temp = (cnt[C] == 0) ? kind + 1 : kind;
        ret = max(ret, temp);
    }

    cout << ret << "\n";
    return 0;
}

