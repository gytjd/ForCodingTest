#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int ret;
vector<pair<int,int>> v;

void DFS_recur(int curr,int num) {
    
    ret=max(ret,num);
    if(curr>N) {
        return;
    }
    
    for(int i=curr;i<N;i++) {
        if(i+v[i].first<=N) {
            DFS_recur(i+v[i].first, num+v[i].second);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int tim,data;
        cin >> tim >> data;
        v.push_back({tim,data});
    }
    
    DFS_recur(0, 0);
    cout << ret << "\n";
    
    return 0;
}
