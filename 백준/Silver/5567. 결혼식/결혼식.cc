#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int ret;
int N,M;
vector<int> v[504];
int visited[504];

void BFS_iter(int start) {
    queue<int> q;
    q.push(start);
    visited[start]=1;
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        
        for(int temp:v[start]) {
            if(visited[temp]==0) {
                visited[temp]=visited[start]+1;
                q.push(temp);
                
                if(visited[temp]==2 or visited[temp]==3) {
                    ret+=1;
                }
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
        v[start].push_back(end);
        v[end].push_back(start);
    }
    
    BFS_iter(1);
    cout << ret << "\n";
    
    return 0;
}
