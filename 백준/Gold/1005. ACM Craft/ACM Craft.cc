#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T;
int N,K,W;
int visited[1004];
int in_degree[1004];
int answer[1004];
vector<int> v[1004];

struct cmp {
    bool operator()(pair<int,int> &a,pair<int,int> &b) {
        return a.second>b.second;
    }
};

void init_() {
    for(int i=1;i<=N;i++) {
        v[i].clear();
        visited[i]=0;
        in_degree[i]=0;
        answer[i]=0;
    }
}

void topo_Sort() {
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;
    for(int i=1;i<=N;i++) {
        if(in_degree[i]==0) {
//            cout << i << "\n";
            q.push({i,visited[i]});
        }
    }
    
    int start,weight;
    while(!q.empty()) {
        start=q.top().first;
        weight=q.top().second;
        q.pop();
        answer[start]=max(answer[start],weight);
        
        for(int i=0;i<v[start].size();i++) {
            in_degree[v[start][i]]-=1;
            
            if(in_degree[v[start][i]]==0) {
                q.push({v[start][i],weight+visited[v[start][i]]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    
    for(int q=0;q<T;q++) {
        cin >> N >> K;
        
        init_();
        
        for(int i=1;i<=N;i++) {
            cin >> visited[i];
        }
        
        for(int i=0;i<K;i++) {
            int start,end;
            cin >> start >> end;
            v[start].push_back(end);
            in_degree[end]+=1;
        }
        cin >> W;
        
        topo_Sort();
        cout << answer[W] << "\n";
//        for(int i=1;i<=N;i++) {
//            cout << i << " " << answer[i] << "\n";
//        }
    }

    return 0;
}
