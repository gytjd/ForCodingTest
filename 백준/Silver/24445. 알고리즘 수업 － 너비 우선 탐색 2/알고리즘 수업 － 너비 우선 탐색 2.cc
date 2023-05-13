#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> temp[100001];
int visited[100001];
int count_n=1;

int N,M,R;

bool comp(int a,int b) {
    return a>b;
}

void BFS_recur(int start) {
    
    int w;
    visited[start]=count_n;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()) {
        w=q.front();q.pop();
        
        for(int i=0;i<temp[w].size();i++) {
            if(visited[temp[w][i]]==0) {
                visited[temp[w][i]]=++count_n;
                q.push(temp[w][i]);
            }
        }
    }
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> R;
    
    for(int i=0;i<M;i++) {
        int start,end;
        cin >> start >> end;
        
        temp[start].push_back(end);
        temp[end].push_back(start);
    }
    
    for(int i=1;i<=N;i++) {
        sort(temp[i].begin(),temp[i].end(),comp);
    }
    
    BFS_recur(R);
    
    for(int i=1;i<=N;i++) {
        cout << visited[i] << "\n";
    }
    
    return 0;
}
