
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N,M;
bool visited[1504][1504];
bool one_Flag=false;

bool tot_Flag=false;
vector<string> arr;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

queue<pair<int, int>> start;
queue<pair<int, int>> swan;

int x1,y1;

void display_() {
    
    cout << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    
    cout << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}

void BFS_iter() {
    
    int x,y;
    int dx,dy;
    queue<pair<int, int>> temp;
    
    while(!start.empty()) {
        x=start.front().first;
        y=start.front().second;
        start.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M) {
                continue;
            }
            
            if(arr[dx][dy]=='X') {
                arr[dx][dy]='.';
                temp.push(make_pair(dx, dy));
            }
        }
    }
    start=temp;
}

void BFS_() {
    
    int x,y;
    int dx,dy;
    
    bool check_Flag=false;
    
    queue<pair<int, int>> temp;
    
    while(!swan.empty()) {
        x=swan.front().first;
        y=swan.front().second;
        swan.pop();
        
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M) {
                continue;
            }
            
            if(arr[dx][dy]=='.' and visited[dx][dy]==0) {
//                cout << dx << " " << dy << "\n";
                visited[dx][dy]=1;
                swan.push(make_pair(dx, dy));
            }
            else if(arr[dx][dy]=='X' and visited[dx][dy]==0) {
                visited[dx][dy]=1;
                temp.push(make_pair(dx, dy));
            }
            else if(arr[dx][dy]=='L' and visited[dx][dy]==0) {
                check_Flag=true;
                tot_Flag=true;
            }
        }
        
        if(check_Flag==true) {
            break;
        }
    }
    swan=temp;
    
}

void go_() {
    
    int day_Cnt=0;
    
    while(1) {
        
        BFS_();
        
        if(tot_Flag==true) {
            cout << day_Cnt << "\n";
            break;
        }
        BFS_iter();
        
        
        day_Cnt+=1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        arr.emplace_back(a);
        
        for(int j=0;j<M;j++) {
            if(a[j]=='.' or a[j]=='L') {
                start.push(make_pair(i, j));
            }
            
            if(a[j]=='L' and one_Flag==false) {
                swan.push(make_pair(i, j));
                visited[i][j]=1;
                one_Flag=true;
            }
        }
    }
    
    go_();
    
    return 0;
}

