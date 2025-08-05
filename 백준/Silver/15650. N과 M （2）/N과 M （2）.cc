#include <iostream>

using namespace std;

int N,M;
int visited[14];

void display_() {
    for(int i=1;i<=N;i++) {
        if(visited[i]) cout << i << " ";
    }
    cout << "\n";
}

void DFS_recur(int curr,int idx) {
    
    if(curr==M) {
        display_();
        return;
    }
    
    for(int i=idx;i<=N;i++) {
        if(visited[i]==0) {
            visited[i]=1;
            DFS_recur(curr+1, i+1);
            visited[i]=0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    DFS_recur(0, 1);
    
    return 0;
}
