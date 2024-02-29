#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int N,M;
bool check_Flag;
vector<int> v[204];
vector<int> route;
int visited[204];

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
    
    cin >> N;
    cin >> M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            int data;
            cin >> data;
            if(data) v[i].push_back(j);
        }
    }
    for(int i=0;i<M;i++) {
        int data;
        cin >> data;
        route.push_back(data);
    }
    
    for(int i=0;i<M-1;i++) {
        memset(visited, 0, sizeof(visited));
        BFS_iter(route[i]);
        if(visited[route[i+1]]==0) {
            check_Flag=true;
            break;
        }
    }
    
    cout << (!check_Flag?"YES":"NO") << "\n";
    
    return 0;
}
