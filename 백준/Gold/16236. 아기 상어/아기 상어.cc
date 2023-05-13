#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int x;
    int y;
    int dist;
};

int N;
int arr[24][24];
int visited[24][24];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int currX,currY;

int shark_Size=2;
vector<Node> temp;
int ret;

bool comp(Node a,Node b) {
    
    if(a.dist==b.dist) {
        if(a.x==b.x) {
            return a.y<b.y;
        }
        else {
            return a.x<b.x;
        }
    }
    else {
        return a.dist<b.dist;
    }
}

void init_() {
    
    for(int i=0;i<24;i++) {
        for(int j=0;j<24;j++) {
            visited[i][j]=0;
        }
    }
}
void BFS_iter(int x,int y) {
    
    visited[x][y]=1;
    int dx,dy;
    queue<Node> q;
    q.push({x,y,0});
    
    while(!q.empty()) {
        x=q.front().x;
        y=q.front().y;
        q.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=N) {
                continue;
            }
            
            if(visited[dx][dy]==0 and arr[dx][dy]<=shark_Size) {
                
                visited[dx][dy]=visited[x][y]+1;
                q.push({dx,dy,visited[dx][dy]});
                
                if(arr[dx][dy]<shark_Size and arr[dx][dy]!=0) {
                    temp.push_back({dx,dy,visited[dx][dy]-1});
                }
            
            }
        }
    }
}

void go_() {
    
    int cnt=0;
    while(1) {
        init_();
        temp.clear();
        
        BFS_iter(currX, currY);
        sort(temp.begin(), temp.end(), comp);
        
        if(temp.size()==0) {
            cout << ret << "\n";
            break;
        }
        
        Node tmp=temp[0];
        cnt+=1;
        ret+=tmp.dist;
        
        if(cnt==shark_Size) {
            shark_Size+=1;
            cnt=0;
        }
        
        arr[currX][currY]=0;
        currX=tmp.x;
        currY=tmp.y;
        arr[tmp.x][tmp.y]=9;
        
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
            
            if(arr[i][j]==9) {
                currX=i;
                currY=j;
            }
        }
    }
    
    go_();
    
    return 0;
}
