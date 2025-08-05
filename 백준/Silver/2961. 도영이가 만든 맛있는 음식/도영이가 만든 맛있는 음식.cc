#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX_SIZE 1e9

using namespace std;

int N;
vector<pair<int,int>> v;
int visited[14];
int ret=MAX_SIZE;

void DFS_recur(int curr,int idx,int sho,int bit) {
    
    if(curr==N) {
        ret=min(ret,abs(sho-bit));
        return;
    }
    
    for(int i=idx;i<N;i++) {
        if(visited[i]==0) {
            visited[i]=1;
            DFS_recur(curr+1, i+1, sho*v[i].first, bit+v[i].second);
            visited[i]=0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int start,end;
        cin >> start >> end;
        v.push_back({start,end});
    }
    
    for(int i=0;i<N;i++) {
        DFS_recur(i, 0, 1, 0);
    }
    cout << ret << "\n";
    
    return 0;
}
