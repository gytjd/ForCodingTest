#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_SIZE 2504
#define INF 1e9+7

using namespace std;

struct Node {
    int weight,curr,min_Prev;
};

struct cmp {
    bool operator()(Node &a,Node &b) {
        return a.weight>b.weight;
    }
};

int N,M;
vector<int> price;
vector<pair<int, int>> v[MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];

void init_() {
    for(int i=0;i<MAX_SIZE;i++) {
        for(int j=0;j<MAX_SIZE;j++) {
            dist[i][j]=INF;
        }
    }
}

void Dijkstra(int curr) {
    int weight;
    int min_Prev;
    
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
        
        for(pair<int, int> temp:v[curr]) {
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
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        price.push_back(data);

    }
    
    for(int i=0;i<M;i++) {
        int S,E,W;
        cin >> S >> E >> W;
        v[S].push_back({W,E});
        v[E].push_back({W,S});
    }
    
    Dijkstra(1);
    
    return 0;
}
