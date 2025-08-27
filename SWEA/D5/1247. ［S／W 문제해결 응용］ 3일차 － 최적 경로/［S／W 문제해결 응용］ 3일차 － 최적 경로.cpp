#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int T,N;
int ret;
int startX,startY;
int endX,endY;
vector<pair<int,int>> v;
int visited[14];

void DFS_recur(int curr,int currX,int currY,int num) {
    
    if(curr==N) {
        num+=abs(currX-endX)+abs(currY-endY);
        ret=min(ret,num);
        return;
    }
    
    for(int i=0;i<N;i++) {
        if(visited[i]==0) {
            visited[i]=1;
            DFS_recur(curr+1, v[i].first, v[i].second, num+abs(currX-v[i].first)+abs(currY-v[i].second));
            visited[i]=0;
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    for(int test_case=1;test_case<=T;test_case++) {
        
        v.clear();
        memset(visited,0,sizeof(visited));
        ret=987654321;
        
        cin >> N;
        cin >> startX >> startY;
        cin >> endX >> endY;
        for(int i=0;i<N;i++) {
            int start,end;
            cin >> start >> end;
            v.push_back({start,end});
        }
        
        DFS_recur(0, startX, startY, 0);
        cout << "#" << test_case << " " << ret << "\n";
    }
    
    return 0;
}