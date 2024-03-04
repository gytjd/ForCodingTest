#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int N,M;
int answer;
int start_N,end_M;
int low=1000000004,high=1;
vector<pair<int,int>> v[100004];
int visited[100004];

void BFS_iter(int start,int weight) {
    queue<int> q;
    q.push(start);
    visited[start]=1;
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        
        for(pair<int,int> temp:v[start]) {
            if(visited[temp.first]==0 and temp.second>=weight) {
                visited[temp.first]=1;
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
    
    for(int i=0;i<M;i++) {
        int A,B,C;
        cin >> A >> B >> C;
        v[A].push_back({B,C});
        v[B].push_back({A,C});
        
        low=min(low,C);
        high=max(high,C);
    }
    cin >> start_N >> end_M;
    
    while(low<=high) {
        int mid=(low+high)/2;
        
//        cout << mid << "\n";
        
        memset(visited, 0, sizeof(visited));
        BFS_iter(start_N,mid);
        
        if(visited[end_M]) { // mid 값으로 통과함
            answer=max(answer,mid);
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
    
    cout << answer << "\n";
    return 0;
}
