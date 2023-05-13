#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,M,F;
int arr[24][24];
int visited[24][24];
int startX,startY;

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

struct Node {
    int x,y;
    int num;
    int weight;
};

Node person[24][24];

bool cmp(Node a,Node b) {
    if(a.weight==b.weight) {
        
        if(a.x==b.x) {
            return a.y<b.y;
        }
        return a.x<b.x;
    }
    return a.weight<b.weight;
}

void init_() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            visited[i][j]=0;
        }
    }
}

void move_person(vector<Node> &v,int x,int y) {
    
    visited[x][y]=1;
    
    int dx,dy;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    if(person[x][y].num!=0) {
        v.push_back({x,y,person[x][y].num,visited[x][y]-1});
    }
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=N) {
                continue;;
            }
            
            if(visited[dx][dy]==0 and arr[dx][dy]==0) {
                visited[dx][dy]=visited[x][y]+1;
                q.push(make_pair(dx, dy));
                
                if(person[dx][dy].num!=0) {
                    v.push_back({dx,dy,person[dx][dy].num,visited[dx][dy]-1});
//                    cout << dx << " " << dy << "\n";
                }
                
            }
        }
    }
    
}

int move_destination(int x,int y,int endX,int endY,int num) {
    
    int dx,dy;
    visited[x][y]=1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
//        cout << x << " " << y << "\n";
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=N) {
                continue;;
            }
            
            if(visited[dx][dy]==0 and arr[dx][dy]==0) {
                visited[dx][dy]=visited[x][y]+1;
                q.push(make_pair(dx, dy));
                
                if(dx==endX and dy==endY) {
                    startX=dx;
                    startY=dy;
                    return visited[dx][dy]-1;
                }
            }
        }
    }
    
    return -1;
}

void go_() {

    bool check_Flag=false;
    for(int i=0;i<M;i++) {
        
        int temp_N;
        vector<Node> v;
        init_();
        move_person(v, startX, startY);
        
        if(v.size()==0) {
            cout << -1 << "\n";
            check_Flag=true;
            break;
        }
        sort(v.begin(), v.end(), cmp);
        Node temp=v[0];
        startX=temp.x;
        startY=temp.y;
        temp_N=temp.weight;
        person[startX][startY].num=0;
//        cout << temp_N << "\n";
        
        int endX,endY;
        endX=person[startX][startY].x;
        endY=person[startX][startY].y;
        
        if(F-temp_N<0) {
            cout << -1 << "\n";
            check_Flag=true;
            break;
        }
        F-=temp_N;
        init_();
        temp_N=move_destination(startX, startY,endX,endY,temp.num);
        
        if(temp_N==-1 or F-temp_N<0) {
            cout <<-1 << "\n";
            check_Flag=true;
            break;
        }
        else {
            F-=temp_N;
            F+=(temp_N*2);
//            cout << "# " << F << "\n";
        }
        
    }
    
    if(!check_Flag) {
        cout << F << "\n";
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> F;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }
    
    cin >> startX >> startY;
    startX-=1; startY-=1;
    
    for(int i=0;i<M;i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        person[a-1][b-1]={c-1,d-1,i+1,0};
    }
    
    go_();
    
    return 0;
}
