#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int ret;
int N;
vector<int> v[54];
int visited[54];

int BFS_iter(int start) {
    int temp=0;
    queue<int> q;
    visited[start]=1;
    for(int i=0;i<v[start].size();i++) {
        temp+=1;
        visited[v[start][i]]=1;
        q.push(v[start][i]);
    }
    
    int x;
    while(!q.empty()) {
        x=q.front();
        q.pop();
        
        for(int i=0;i<v[x].size();i++) {
            if(visited[v[x][i]]==0) {
                visited[v[x][i]]=1;
                temp+=1;
            }
        }
    }
    
    return temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        for(int j=0;j<N;j++) {
            if(a[j]=='Y') {
                v[i].push_back(j);
            }
        }
    }
    
    for(int i=0;i<N;i++) {
        memset(visited, 0, sizeof(visited));
        ret=max(ret,BFS_iter(i));
    }
    
    cout << ret << "\n";
    
    return 0;
}
