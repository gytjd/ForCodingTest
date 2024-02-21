#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N,M;
vector<int> v[2004];
int visited[2004];

void DFS_recur(int start,int cnt) {
    if(cnt==4) {
        cout << 1 << "\n";
        exit(0);
    }
    visited[start]=1;
    
    for(int i=0;i<v[start].size();i++) {
        if(visited[v[start][i]]==0) {
            visited[v[start][i]]=1;
            DFS_recur(v[start][i], cnt+1);
            visited[v[start][i]]=0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        int start,end;
        cin >> start >> end;
        v[start].push_back(end);
        v[end].push_back(start);
    }
    
    for(int i=0;i<N;i++) {
        memset(visited, 0, sizeof(visited));
        DFS_recur(i, 0);
    }
    
    cout << 0 << "\n";
    
    
    return 0;
}
