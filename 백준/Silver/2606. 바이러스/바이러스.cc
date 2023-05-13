#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;
vector<int> temp[101];
int visited[101];

void BFS_iter(int start) {
    visited[start]=1;
    
    int w;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()) {
        w=q.front();q.pop();
        for(int i=0;i<temp[w].size();i++) {
            if(visited[temp[w][i]]==0) {
                visited[temp[w][i]]=1;
                q.push(temp[w][i]);
            }
        }
    }
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    cin >> M;
    
    for(int i=0;i<M;i++) {
        int start,end;
        cin >> start >> end;
        
        temp[start].push_back(end);
        temp[end].push_back(start);
    }
    
    BFS_iter(1);
    
    int count_n=0;
    for(int i=1;i<=N;i++) {
        if(visited[i]==1) {
            count_n+=1;
        }
    }
    
    cout << count_n-1 << "\n";
    
    return 0;
}
