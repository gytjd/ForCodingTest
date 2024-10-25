#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    
    sort(v.begin(),v.end());
    
    int ret=0;
    for(int i=0;i<N;i++) {
        ret=max(ret,v[i]*(N-i));
    }
    
    cout << ret << "\n";
    
    return 0;
}
