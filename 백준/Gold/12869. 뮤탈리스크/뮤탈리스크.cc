#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int temp[3];

int dir[6][3]={{9,3,1},{9,1,3},{3,1,9},{3,9,1},{1,3,9},{1,9,3}};

struct Node {
    int x;
    int y;
    int z;
    
    Node(int a,int b,int c) {
        x=a;
        y=b;
        z=c;
    }
};

int visited[61][61][61];

void BFS_iter(int a,int b,int c,int depth) {
    
    int dx,dy,dz;
    queue<Node> q;
    Node tp=Node(a, b, c);
    q.push(tp);
    visited[a][b][c]=1;
    
    while(!q.empty()) {
        a=q.front().x;
        b=q.front().y;
        c=q.front().z;
        q.pop();
        
        if(!visited[a][b][c]) {
            break;
        }
        
        
        for(int i=0;i<6;i++) {
            dx=a-dir[i][0];
            dy=b-dir[i][1];
            dz=c-dir[i][2];
            
            
            if(dx<0) dx=0;
            if(dy<0) dy=0;
            if(dz<0) dz=0;
            
            if(visited[dx][dy][dz]!=0) {
                continue;
            }
            visited[dx][dy][dz]=visited[a][b][c]+1;
            tp=Node(dx, dy, dz);
            q.push(tp);
            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> temp[i];
    }
    
    BFS_iter(temp[0], temp[1], temp[2], 0);
    cout << visited[0][0][0]-1 << "\n";
    
    return 0;
}

