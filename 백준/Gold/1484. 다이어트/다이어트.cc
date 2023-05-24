#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;
vector<int> ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=1;i<=N;i++) {
        if(N%i==0) {
            v.push_back(i);
        }
    }
    
    long long vSize=v.size();
    for(int i=0;i<vSize/2;i++) {
        if((v[i]+v[vSize-i-1])%2==0 and v[i]!=v[vSize-i-1]) {
            ret.push_back((v[i]+v[vSize-i-1])/2);
        }
    }
    
    if(vSize%2) {
        if((v[vSize/2]+v[vSize/2])%2==0 and v[vSize/2]!=v[vSize/2]) {
            ret.push_back((v[vSize/2]+v[vSize/2])/2);
        }
    }
    
    sort(ret.begin(), ret.end());
    
    if(ret.size()==0) {
        cout << -1 << "\n";
    }
    else {
        for(int a:ret) {
            cout << a << "\n";
        }
    }
    
    return 0;
}
