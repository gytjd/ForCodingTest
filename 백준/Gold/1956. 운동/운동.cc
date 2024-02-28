#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_SIZE 404
#define INF 1e9

using namespace std;

int V,E;
int answer=INF;
vector<pair<int,int>> v[MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];

void init_() {
    for(int i=1;i<=V;i++) {
        for(int j=1;j<=V;j++) {
            if(i==j) continue;
            dist[i][j]=INF;
        }
    }
}

void display_() {
    cout << '\n';
    for(int i=1;i<=V;i++) {
        for(int j=1;j<=V;j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

void Dijkstra(int start,int curr,int weight) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({weight,curr});
    
    while(!q.empty()) {
        weight=q.top().first;
        curr=q.top().second;
        q.pop();
        
        if(dist[start][curr]<weight) continue;
        
        for(pair<int,int> temp:v[curr]) {
            if(dist[start][curr]+temp.second<dist[start][temp.first]) {
                dist[start][temp.first]=dist[start][curr]+temp.second;
                q.push({dist[start][temp.first],temp.first});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> V >> E;
    
    for(int i=0;i<E;i++) {
        int start,end,weight;
        cin >> start >> end >> weight;
        v[start].push_back({end,weight});
    }
    
    init_();
    for(int i=1;i<=V;i++) {
        Dijkstra(i, i,0);
    }
    
//    display_();
    
    for(int i=1;i<=V;i++) {
        for(int j=i+1;j<=V;j++) {
            if(dist[i][j]!=INF and dist[j][i]!=INF)
                answer=min(answer,dist[i][j]+dist[j][i]);
        }
    }
    
    cout << (answer==INF?-1:answer) << "\n";
    
    return 0;
}
