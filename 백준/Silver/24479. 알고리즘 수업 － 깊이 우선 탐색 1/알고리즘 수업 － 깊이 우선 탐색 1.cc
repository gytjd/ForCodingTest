#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> temp[100001];
int visited[100001];
int count_n=1;

int N,M,R;

bool comp(int a,int b) {
    return a<b;
}

void DFS_rec(int start) {
    visited[start]=count_n++;
    
    for(int i=0;i<temp[start].size();i++) {
        if(visited[temp[start][i]]==0) {
            DFS_rec(temp[start][i]);
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
    
    DFS_rec(R);
    
    for(int i=1;i<=N;i++) {
        cout << visited[i] << "\n";
    }
    
    return 0;
}

