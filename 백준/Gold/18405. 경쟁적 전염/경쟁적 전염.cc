#include <iostream>
#include <queue>
using namespace std;

int N,K;
int S,X,Y;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[204][204];
int visited[204][204];

priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<>> q;

void BFS_iter() {
    int n,x,y;
    int dx,dy;
    
    priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<>> temp;
    
    while(!q.empty()) {
        n=q.top().first;
        x=q.top().second.first;
        y=q.top().second.second;
        q.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=N) {
                continue;
            }
            
            if(visited[dx][dy]==0 and arr[dx][dy]==0) {
                arr[dx][dy]=n;
                visited[dx][dy]=1;
                temp.push({arr[dx][dy],{dx,dy}});
            }
        }
    }
    
    q=temp;
}
void go_() {
    
    for(int i=0;i<S;i++) {
        BFS_iter();
    }
    cout << arr[X-1][Y-1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> K;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
            if(arr[i][j]!=0) {
                q.push({arr[i][j],{i,j}});
                visited[i][j]=1;
            }
        }
    }
    cin >> S >> X >> Y;
    
    go_();
    

    return 0;
}
