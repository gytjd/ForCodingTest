#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define MAX_SIZE 54

using namespace std;

int N;
int visited[MAX_SIZE];
vector<int> v[MAX_SIZE];
vector<int> answer[MAX_SIZE];

int BFS_iter(int start) {
    
    int temp_Answer=0;
    queue<int> q;
    q.push(start);
    visited[start]=1;
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        temp_Answer=max(temp_Answer,visited[start]);
        
        for(int temp:v[start]) {
            if(visited[temp]==0) {
                visited[temp]=visited[start]+1;
                q.push(temp);
            }
        }
    }
    return temp_Answer-1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    while(true) {
        int start,end;
        cin >> start >> end;
        if(start==-1 and end==-1) break;
        
        v[start].push_back(end);
        v[end].push_back(start);
    }
    
    for(int i=1;i<=N;i++) {
        memset(visited,0,sizeof(visited));
        answer[BFS_iter(i)].push_back(i);
    }
    
    for(int i=1;i<=N;i++) {
        if(answer[i].size()) {
            cout << i << " " << answer[i].size() << "\n";
            sort(answer[i].begin(),answer[i].end());
            for(int temp:answer[i]) {
                cout << temp << " ";
            }
            cout << "\n";
            break;
        }
    }
    return 0;
}
