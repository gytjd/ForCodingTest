#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

int T;
int N,D,C;

vector<pair<int, int>> arr[10004];
int dist[10004];

void display_() {
    
    int count_T=0;
    int ret=0;
    for(int i=1;i<=N;i++) {
        if(dist[i]!=INF) {
            count_T+=1;
            ret=max(ret,dist[i]);
        }
    }
    
    cout << count_T << " " << ret << "\n";
}

void init_() {
    for(int i=1;i<=N;i++) {
        arr[i].clear();
        dist[i]=INF;
    }
}

void Dijkstra() {
    
    int start,weight;
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> q;
    q.push({0,C});
    dist[C]=0;
    
    while(!q.empty()) {
        weight=q.top().first;
        start=q.top().second;
        q.pop();
        
//        cout << weight << " " << start << "\n";
        
        if(dist[start]<weight) {
            continue;
        }
        
        for(pair<int, int> temp:arr[start]) {
            
//            cout << temp.first << " " << temp.second << "\n";
            
            if(weight+temp.first<dist[temp.second]) {
                dist[temp.second]=temp.first+weight;
                q.push({dist[temp.second],temp.second});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    
    for(int i=0;i<T;i++) {
        cin >> N >> D >> C;
        
        init_();
        
        for(int j=0;j<D;j++) {
            int end,start,weight;
            cin >> end >> start >> weight;
            arr[start].push_back({weight,end});
        }
        
        Dijkstra();
        display_();
        
    }
    
    return 0;
}
