#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int dirX;
    int dirY;
    int data;
};

Node temp[8][8];
Node result[8][8];
int visited[8][8];

queue<pair<int, int>> q;
vector<pair<int, int>> t;

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int N,M;

int max_result=0;

void init_() {
    int i,j;
    for(i=0;i<N;i++) {
        for(j=0;j<M;j++) {
            visited[i][j]=0;
            result[i][j]=temp[i][j];
        }
    }
}

int check_Zero() {
    int count=0;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(result[i][j].data==0) {
                count+=1;
            }
        }
    }
    
    return count;
}

void BFS_recur(int x,int y) {

    int dx,dy;
    visited[x][y]=1;
    
    q.push(make_pair(x, y));
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M) {
                continue;
            }
            
            if(result[dx][dy].data==0 and visited[dx][dy]==0) {
                visited[dx][dy]=1;
                result[dx][dy].data=2;
                q.push(make_pair(dx, dy));
            }
        }
        
    }
    
    
    
}

void go() {
    int i,j;
    
    for(i=0;i<N;i++) {
        for(j=0;j<M;j++) {
            if(result[i][j].data==2) {
                BFS_recur(i,j);
            }
        }
    }
    
    int check_temp=check_Zero();
     
    if(check_temp>max_result) {
        max_result=check_temp;
    }
}

void start() {
    
    int i,j,k;
    int size_t=t.size();
    
    for(i=0;i<size_t;i++) {
        for(j=i+1;j<size_t;j++) {
            for(k=j+1;k<size_t;k++) {
                
                init_();
                result[t[i].first][t[i].second].data=1;
                result[t[j].first][t[j].second].data=1;
                result[t[k].first][t[k].second].data=1;
                
                go();
                
                result[t[i].first][t[i].second].data=0;
                result[t[j].first][t[j].second].data=0;
                result[t[k].first][t[k].second].data=0;
            }
        }
    }
}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            
            int data;
            cin >> data;
            
            Node new_node;
            new_node.dirX=i;
            new_node.dirY=j;
            new_node.data=data;
            
            temp[i][j]=new_node;
            result[i][j]=new_node;
            
            if(data==0) {
                t.push_back(make_pair(i, j));
            }
        }
    }
    
    start();
    cout << max_result << "\n";
    return 0;
}
