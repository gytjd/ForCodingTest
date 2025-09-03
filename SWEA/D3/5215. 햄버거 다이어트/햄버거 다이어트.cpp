#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T,N,L;
int ret;
vector<pair<int,int>> v;

void DFS_recur(int curr,int taste,int cal) {
    
    if(cal>L) return;
    
    if(curr==N) {
        ret=max(ret,taste);
        return;
    }
    
    DFS_recur(curr+1,taste,cal);
    DFS_recur(curr+1,taste+v[curr].first,cal+v[curr].second);
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    for(int test_case=1;test_case<=T;test_case++) {
        
        cin >> N >> L;
        
        ret=0;
        v.clear();
        
        for(int i=0;i<N;i++) {
            
            int T,K;
            cin >> T >> K;
            v.push_back({T,K});
        }
        
        DFS_recur(0, 0, 0);
        cout << "#" << test_case << " " << ret << "\n";
    }
    
    return 0;
}
