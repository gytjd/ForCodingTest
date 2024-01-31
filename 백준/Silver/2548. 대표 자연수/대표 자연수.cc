#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> v;

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
    sort(v.begin(),v.end());
    if (N % 2 == 0) {
        cout << v[N / 2 - 1] << "\n";
    }
    else {
        cout << v[N / 2] << "\n";
    }

    return 0;
}
