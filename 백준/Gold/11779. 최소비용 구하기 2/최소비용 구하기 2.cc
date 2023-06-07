#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

int N,M,S,E;

vector<int> ret;
vector<pair<int, int>> arr[1004];

int dist[1004];
int dir[1004];

void display_() {
    
    cout << "\n";
    for(int i=1;i<=N;i++) {
        cout << dir[i] << " ";
    }
    cout << "\n";
}

void init_() {
    for(int i=0;i<=N;i++) {
        dist[i]=INF;
    }
}

void Dijkstra(int start) {
    
    int weight;
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> q;
    q.push({0,start});
    dist[start]=0;
    dir[start]=0;
    
    while(!q.empty()) {
        weight=q.top().first;
        start=q.top().second;
        q.pop();
        

        if (dist[start] < weight)
        {
            continue;
        }
        
        for(pair<int, int> temp:arr[start]) {
            if(dist[start]+temp.first<dist[temp.second]) {
                dist[temp.second]=dist[start]+temp.first;
                q.push({dist[temp.second],temp.second});
                dir[temp.second]=start;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    init_();
    
    for(int i=0;i<M;i++) {
        int start,end,weight;
        cin >> start >> end >> weight;
        arr[start].push_back({weight,end});
    }
    
    cin >> S >> E;
    
    Dijkstra(S);
    cout << dist[E] << "\n";
    
    int count_T=1;
    while(dir[E]!=0) {
        count_T+=1;
        ret.push_back(E);
        E=dir[E];
    }
    ret.push_back(S);
    reverse(ret.begin(), ret.end());
    
    cout << count_T << "\n";
    for(int temp:ret) {
        cout << temp << " ";
    }
    cout << "\n";
    
    return 0;
}
