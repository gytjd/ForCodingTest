#include <iostream>
#include <queue>

using namespace std;

int N,M;
int x1,y1,x2,y2;

char temp[304][304];
int visited[304][304];

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

queue<pair<int, int>> q;

void display_() {
    int i,j;
    
    cout << "\n";
    for(i=0;i<N;i++) {
        for(j=0;j<M;j++) {
            cout << temp[i][j] << " ";
        }
        cout << "\n";
    }
}
void BFS_iter(int x,int y) {
    
    int time_Cnt=0;
    bool check_Flag=false;
    
    int dx,dy;
    visited[x][y]=1;
    q.push(make_pair(x, y));
    
    while(1) {
        
        queue<pair<int,int>> p;
        while(!q.empty()) {
            
            x=q.front().first;
            y=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++) {
                dx=x+dir[i][0];
                dy=y+dir[i][1];
                
                if(dx<0 or dx>=N or dy<0 or dy>=M) {
                    continue;;
                }
                
                if(temp[dx][dy]=='1' and visited[dx][dy]==0) {
                    visited[dx][dy]=1;
                    temp[dx][dy]='0';
                    p.push(make_pair(dx, dy));
                }
                else if(temp[dx][dy]=='0' and visited[dx][dy]==0) {
                    visited[dx][dy]=1;
                    q.push(make_pair(dx, dy));
                }
                else if(temp[dx][dy]=='#') {
                    check_Flag=true;
                    break;
                }
            }
            
            if(check_Flag==true) {
                break;
            }
        }
        q=p;
        time_Cnt+=1;
        if(check_Flag==true) {
            cout << time_Cnt << "\n";
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;
    
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        
        for(int j=0;j<a.size();j++) {
            temp[i][j]=a[j];
        }
    }
    
    BFS_iter(x1, y1);
    
    return 0;
}
