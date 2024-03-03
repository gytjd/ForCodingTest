#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int T;
int N;
vector<int> v[1004];
int visited[1004];

void init_() {
    
    memset(visited,0,sizeof(visited));
    for(int i=1;i<=1004;i++) {
        v[i].clear();
    }
}
void BFS_iter(int start) {
    queue<int> q;
    q.push(start);
    visited[start]=1;
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        
        for(int temp:v[start]) {
            if(visited[temp]==0) {
                visited[temp]=1;
                q.push(temp);
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
        init_();
        
        for(int i=1;i<=N;i++) {
            int data;
            cin >> data;
            v[i].push_back(data);
        }
        
        int answer=0;
        for(int i=1;i<=N;i++) {
            if(visited[i]==0) {
                BFS_iter(i);
                answer+=1;
            }
        }
        cout << answer << "\n";
    }
    return 0;
}
