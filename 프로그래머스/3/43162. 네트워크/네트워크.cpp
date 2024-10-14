#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[204];
int visited[204];

void BFS_iter(int start) {
    queue<int> q;
    q.push(start);
    visited[start]=1;
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        
        for(int i=0;i<v[start].size();i++) {
            if(visited[v[start][i]]==0) {
                visited[v[start][i]]=1;
                q.push(v[start][i]);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(computers[i][j]) {
                v[i+1].push_back(j+1);
            }
        }
    }
    
    int ret=0;
    for(int i=1;i<=n;i++) {
        if(visited[i]==0) {
            BFS_iter(i);
            ret+=1;
        }
    }
    
    return ret;
}