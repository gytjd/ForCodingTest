#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_SIZE 2504
#define INF 1e15+7

using namespace std;

struct Node {
    long long weight,curr,min_Prev;
};

struct cmp {
    bool operator()(Node &a,Node &b) {
        return a.weight>b.weight;
    }
};

long long N,M;
vector<long long> price;
vector<pair<long long, long long>> v[MAX_SIZE];
long long dist[MAX_SIZE][MAX_SIZE];

void init_() {
    for(long long i=0;i<MAX_SIZE;i++) {
        for(long long j=0;j<MAX_SIZE;j++) {
            dist[i][j]=INF;
        }
    }
}

void Dijkstra(long long curr) {
    long long weight;
    long long min_Prev;
    
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({0,curr,price[curr]});
    
    while(!q.empty()) {
        weight=q.top().weight;
        curr=q.top().curr;
        min_Prev=q.top().min_Prev;
        q.pop();
        
        if(dist[curr][min_Prev]<weight) {
            continue;
        }
        
        if(curr==N) {
            cout << weight << "\n";
            break;
        }
        
        for(pair<long long, long long> temp:v[curr]) {
//            cout << temp.second << " " << weight+(temp.first*min_Prev) << "\n";
            
            if(weight+(temp.first*min_Prev)<dist[temp.second][min_Prev]) {
                dist[temp.second][min_Prev]=weight+(temp.first*min_Prev);
                q.push({dist[temp.second][min_Prev],temp.second,min(min_Prev,price[temp.second])});
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
    price.push_back(0);
    for(long long i=0;i<N;i++) {
        long long data;
        cin >> data;
        price.push_back(data);

    }
    
    for(long long i=0;i<M;i++) {
        long long S,E,W;
        cin >> S >> E >> W;
        v[S].push_back({W,E});
        v[E].push_back({W,S});
    }
    
    Dijkstra(1);
    
    return 0;
}
