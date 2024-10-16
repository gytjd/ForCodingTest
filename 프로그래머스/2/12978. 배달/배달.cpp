#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

int dist[54];
int visited[20004];
vector<pair<int,int>> v[54];


struct cmp {
    bool operator()(pair<int, int> &a,pair<int, int> &b) {
        return a.second>b.second;
    }
};

void Dijkstra(int start) {
    
    priority_queue<pair<int, int>,vector<pair<int, int>>,cmp> q;
    dist[start]=0;
    q.push({start,0});

    while(!q.empty()) {
        start=q.top().first;
        q.pop();
        visited[start]=1;
        
        for(pair<int, int> temp:v[start]) {
            if(visited[temp.first]==0) {
                if(dist[start]+temp.second<dist[temp.first]) {
                    dist[temp.first]=dist[start]+temp.second;
                    q.push({temp.first,dist[temp.first]});
                }
            }
        }
    }
}

void init_(int N) {
    for(int i=1;i<=N;i++) {
        dist[i]=INF;
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    init_(N);
    for(vector<int> temp:road) {
        v[temp[0]].push_back({temp[1],temp[2]});
        v[temp[1]].push_back({temp[0],temp[2]});
    }
    
    Dijkstra(1);
    
    for(int i=1;i<=N;i++) {
        // cout << i << " " << dist[i] << "\n";
        if(dist[i]<=K) answer+=1;
    }
    
    return answer;
}