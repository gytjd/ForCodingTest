#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int N,M;
vector<pair<int, int>> arr[1004];
int visited[1004];

void BFS_iter(int start) {

    queue<int> q;
    q.push(start);
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        
        for(pair<int, int> temp:arr[start]) {
            if(!visited[temp.first]) {
                visited[temp.first]=visited[start]+temp.second;
                q.push(temp.first);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N-1;i++) {
        int start,end,weight;
        cin >> start >> end >> weight;
        arr[start].push_back({end,weight});
        arr[end].push_back({start,weight});
    }
    
    for(int i=0;i<M;i++) {
        int start,end;
        cin >> start >> end;
        
        memset(visited, 0, sizeof(visited));
        BFS_iter(start);
        cout << visited[end] << "\n";
    }
    
    return 0;
}
