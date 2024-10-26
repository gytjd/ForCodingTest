#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ret;
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
    
    sort(v.begin(),v.end(),greater<>());
    
    for(int i=0;i<N;i++) {
        ret=max(ret,i+v[i]);
    }
    cout << ret+2 << "\n";
    
    return 0;
}
