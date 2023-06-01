#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> v;
unordered_map<int, int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    for(int i=0;i<3;i++) {
        int data;
        cin >> data;
        v.push_back(data);
        q[data]=1;
    }
    sort(v.begin(), v.end());
    int ret=987654321;
    for(int i=1;i<3;i++) {
        ret=min(ret,abs(v[i]-v[i-1]));
    }
    
    for(int i=0;i<3;i++) {
        if(!q[v[i]+ret]) {
            cout << v[i]+ret << "\n";
            break;
        }
        
    }
    
    
    return 0;
    
}
