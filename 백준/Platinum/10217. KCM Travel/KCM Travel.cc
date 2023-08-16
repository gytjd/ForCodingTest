#include <iostream>
#include <vector>
#include <queue>

#define MAX_SIZE 104
#define INF 1e9+7

using namespace std;

struct Node {
    int curr,weight,time;
};

struct cmp {
    bool operator()(Node &a,Node &b) {
        return a.weight>b.weight;
    }
};

int T;
int N,M,K;
vector<pair<int,pair<int, int>>> v[MAX_SIZE];
int dist[MAX_SIZE][10004];

void init_() {
    for(int i=0;i<MAX_SIZE;i++) {
        for(int j=0;j<10004;j++) {
            dist[i][j]=INF;
        }
    }
}

void Dijkstra(int curr) {
    int weight;
    int time;
    
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({curr,0,0});
    dist[curr][0]=0;
    
    while(!q.empty()) {
        weight=q.top().weight;
        curr=q.top().curr;
        time=q.top().time;
        q.pop();
        
        if(dist[curr][weight]<time) {
            continue;
        }
        
        for(pair<int, pair<int, int>> temp:v[curr]) {
            if(weight+temp.second.first<=M) {
//                cout << temp.first << " " << temp.second.first << " " << temp.second.second << "\n";
                if(dist[curr][weight]+temp.second.second<dist[temp.first][temp.second.first+weight]) {
                    
                    for(int i=weight+temp.second.first+1;i<=M;i++) {
                        if(dist[temp.first][i]<=time+temp.second.second) {
                            break;
                        }
                        dist[temp.first][i]=time+temp.second.second;
                    }
                    
                    dist[temp.first][temp.second.first+weight]=dist[curr][weight]+temp.second.second;
                    q.push({temp.first,weight+temp.second.first,dist[temp.first][temp.second.first+weight]});
                }
            }
        }
    }
}
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    cin >> N >> M >> K;

    init_();
    
    for(int i=0;i<K;i++) {
        int S,E,W,TI;
        cin >> S >> E >> W >> TI;
        v[S].push_back({E,{W,TI}});
    }
    
    Dijkstra(1);
    int ret=INF;
    for(int i=0;i<10004;i++) {
        ret=min(ret,dist[N][i]);
    }
    
    if(ret==INF) {
        cout << "Poor KCM" << "\n";
    }
    else {
        cout << ret << "\n";
    }
    return 0;
}
