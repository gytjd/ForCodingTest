#include <iostream>
#include <queue>
#include <vector>

#define INF 987654321

using namespace std;

int N;
int arr[54][54];
int visited[54][54];

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

struct Node {
    int weight,x,y;
    
    bool operator()(Node a,Node b) {
        return a.weight<b.weight;
    };
};

void display_() {
    
    cout << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}

void BFS_iter(int x,int y) {
    
    int dx,dy;
    int weight;
    priority_queue<Node,vector<Node>,Node> q;
    q.push({0,x,y});
    visited[x][y]=0;
    
    while(!q.empty()) {
        x=q.top().x;
        y=q.top().y;
        weight=q.top().weight;
        q.pop();
        
//        display_();
        
        if(visited[x][y]<weight) {
            continue;
        }
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=N) {
                continue;
            }
            
//            cout << dx << " " << dy << " " << visited[x][y] <<  " " << visited[dx][dy] << "\n";
            if(arr[dx][dy]==0) {
                if(visited[x][y]+1<visited[dx][dy]) {
                    visited[dx][dy]=visited[x][y]+1;
                    q.push({visited[dx][dy],dx,dy});
                }
            }
            else if(arr[dx][dy]==1) {
                if(visited[x][y]<visited[dx][dy]) {
                    visited[dx][dy]=visited[x][y];
                    q.push({visited[dx][dy],dx,dy});
                }
            }
        }
        
        
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        for(int j=0;j<a.size();j++) {
            arr[i][j]=a[j]-'0';
            visited[i][j]=INF;
        }
    }
    
    BFS_iter(0, 0);
    cout << visited[N-1][N-1] << "\n";
//    display_();
    
    return 0;
}
