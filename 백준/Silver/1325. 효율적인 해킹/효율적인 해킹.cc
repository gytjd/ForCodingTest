#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N,M;
vector<int> v[10004];
int visited[10004];
vector<pair<int,int>> ret;

int BFS_iter(int start) {
    int temp_Ret=0;
    queue<int> q;
    q.push(start);
    visited[start]=1;
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        temp_Ret+=1;
        
        for(int temp:v[start]) {
            if(visited[temp]==0) {
                visited[temp]=1;
                q.push(temp);
            }
        }
    }
    
    return temp_Ret;
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        int end,start;
        cin >> end >> start;
        v[start].push_back(end);
    }
    
    int temp_Num=0;
    for(int i=1;i<=N;i++) {
        memset(visited, 0, sizeof(visited));
        int temp_Ret=BFS_iter(i);
        ret.push_back({temp_Ret,i});
        temp_Num=max(temp_Num,temp_Ret);
    }
    
    for(int i=0;i<N;i++) {
        if(ret[i].first==temp_Num) {
            cout << ret[i].second << " ";
        }
    }
    cout << "\n";
    
    return 0;
}
