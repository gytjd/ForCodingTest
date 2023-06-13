#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
vector<int> v[504];
int visited[504];

void BFS_iter(int start) {
    visited[start]=1;
    queue<int> q;
    q.push(start);
    
    for(int i=0;i<2;i++) {
        queue<int> temp;
        while(!q.empty()) {
            start=q.front();
            q.pop();
//            cout << start << "\n";
            
            for(int d:v[start]) {
                if(visited[d]==0) {
                    visited[d]=1;
                    temp.push(d);
                }
            }
        }
        q=temp;
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
    
    int ret=0;
    for(int i=2;i<=N;i++) {
        if(visited[i]==1) {
            ret+=1;
        }
    }
    
    cout << ret << "\n";
}
