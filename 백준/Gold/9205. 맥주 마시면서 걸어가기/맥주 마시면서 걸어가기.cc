#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

int T;
int N;
vector<pair<int,int>> v;
int visited[104];

int cal_Dist(int startX,int startY,int endX,int endY) {
    return abs(startX-endX)+abs(startY-endY);
}

void BFS_iter(int start,int end) {
    queue<pair<int,int>> q;
    q.push({start,end});
    visited[0]=1;
    
    while(!q.empty()) {
        start=q.front().first;
        end=q.front().second;
        q.pop();
        
        for(int i=0;i<N+2;i++) {
            if(visited[i]==0 and cal_Dist(start, end, v[i].first, v[i].second)<=1000) {
                visited[i]=1;
                q.push({v[i].first,v[i].second});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    for(int test=0;test<T;test++) {
        cin >> N;
        v.clear();
        
        for(int i=0;i<N+2;i++) {
            int start,end;
            cin >> start >> end;
            v.push_back({start,end});
        }
        memset(visited,0,sizeof(visited));
        BFS_iter(v[0].first, v[0].second);
        
        cout << (visited[N+1]==1?"happy":"sad") << "\n";
    }
    
    return 0;
}
