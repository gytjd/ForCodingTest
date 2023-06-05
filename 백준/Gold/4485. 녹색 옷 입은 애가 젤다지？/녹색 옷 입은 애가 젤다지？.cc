#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

struct Node {
    int weight,x,y;
};

struct cmp {
    bool operator()(Node &a,Node &b) {
        return a.weight>b.weight;
    }
};

int N;
Node arr[128][128];
int visited[128][128];
int dist[128][128];

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

void display_() {
    
    cout << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
void Dijkstra(int weight,int x,int y) {
    
    int dx,dy;
    priority_queue<Node,vector<Node>,cmp> pq;
    
    pq.push({weight,x,y});
    dist[x][y]=weight;
    
    while(!pq.empty()) {
        x=pq.top().x;
        y=pq.top().y;
        weight=pq.top().weight;
        pq.pop();
        
        visited[x][y]=1;
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];

            
            if(dx<0 or dx>=N or dy<0 or dy>=N) {
                continue;
            }
            
            if(visited[dx][dy]==0) {
                if(dist[x][y]+arr[dx][dy].weight<dist[dx][dy]) {
                    
                    dist[dx][dy]=dist[x][y]+arr[dx][dy].weight;
                    pq.push({dist[dx][dy],dx,dy});
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int count_T=0;
    while(true) {
        cin >> N;
        if(!N)
            break;
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                int data;
                cin >> data;
                arr[i][j]={data,i,j};
                dist[i][j]=INF;
                visited[i][j]=0;
            }
        }
        
        Dijkstra(arr[0][0].weight, 0, 0);
        cout << "Problem " << ++count_T << ": " << dist[N-1][N-1] << "\n";
//        display_();
    }
    
    return 0;
}
