#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int visited[20004];
vector<int> v[20004];

void BFS_iter(int start) {
    queue<int> q;
    q.push(start);
    visited[start]=1;
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        
        for(int i=0;i<v[start].size();i++) {
            if(visited[v[start][i]]==0) {
                visited[v[start][i]]=visited[start]+1;
                q.push(v[start][i]);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(vector<int> temp:edge) {
        v[temp[0]].push_back(temp[1]);
        v[temp[1]].push_back(temp[0]);
    }
    
    BFS_iter(1);
    
    int max_Num=0;
    int ret_Cnt=0;
    for(int i=1;i<=n;i++) {
        max_Num=max(max_Num,visited[i]);
    }
    for(int i=1;i<=n;i++) {
        if(visited[i]==max_Num) ret_Cnt+=1;
    }
    return ret_Cnt;
}