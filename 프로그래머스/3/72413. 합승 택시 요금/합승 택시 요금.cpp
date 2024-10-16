#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 1e9

using namespace std;


int distA[204];
int distB[204];
int distC[204];
int visited[204];
vector<pair<int,int>> v[204];
priority_queue<pair<int,int>,vector<pair<int,int>>> pq;


struct cmp {
    bool operator()(pair<int, int> &a,pair<int, int> &b) {
        return a.second>b.second;
    }
};

void init_(int n) {
    for(int i=1;i<=n;i++) {
        distA[i]=INF;
        distB[i]=INF;
        distC[i]=INF;
    }
}


void Dijkstra(int start,int dist[]) {
    
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

int go_(int n,int s,int a,int b) {
    
    memset(visited,0,sizeof(visited));
    Dijkstra(s,distA);
    
    memset(visited,0,sizeof(visited));
    Dijkstra(a,distB);

    memset(visited,0,sizeof(visited));
    Dijkstra(b,distC);
    
    int ret=INF;
    for(int i=1;i<=n;i++) {
        if(distA[i]==INF or distB[i]==INF or distC[i]==INF) continue;
        ret=min(ret,distA[i]+distB[i]+distC[i]);
    }
    return ret;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    init_(n);
    for(vector<int> temp:fares) {
        v[temp[0]].push_back({temp[1],temp[2]});
        v[temp[1]].push_back({temp[0],temp[2]});
    }
    
    return go_(n,s,a,b);
}