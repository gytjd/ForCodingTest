#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int N;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    
    for(int test=0;test<T;test++) {
        
        cin >> N;
        v.clear();
        
        for(int i=0;i<N;i++) {
            int data;
            cin >> data;
            v.push_back(data);
        }
        
        sort(v.begin(),v.end());
        
        int ret=0;
        for(int i=0;i<N-2;i++) {
            ret=max(ret,v[i+2]-v[i]);
        }
        
        cout << ret << "\n";
    }
    
    return 0;
}
