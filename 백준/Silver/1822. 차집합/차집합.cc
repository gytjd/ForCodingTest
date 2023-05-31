#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int N,M;

vector<int> a;
vector<int> ret;
unordered_map<int, int> b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        a.push_back(data);
    }
    
    for(int i=0;i<M;i++) {
        int data;
        cin >> data;
        b[data]=1;
    }
    
    for(int i=0;i<N;i++) {
        if(b[a[i]]==0) {
            ret.push_back(a[i]);
        }
    }
    
    sort(ret.begin(), ret.end());
    int retS=ret.size();
    
    if(retS) {
        cout << ret.size() << "\n";
        
        for(int temp:ret) {
            cout << temp << " ";
        }
        cout << "\n";
    }
    else {
        cout << 0 << "\n";
    }
    
    return 0;
}
