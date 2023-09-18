#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    
    for(int i=0;i<N+M;i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    
    sort(v.begin(), v.end());
    
    for(int temp:v) {
        cout << temp << " ";
    }
    cout << "\n";
    
    return 0;
}
