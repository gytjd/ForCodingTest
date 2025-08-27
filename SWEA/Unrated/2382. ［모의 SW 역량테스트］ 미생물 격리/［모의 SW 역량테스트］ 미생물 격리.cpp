#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int ret;
int T;
int N,M,K;
int retDir[5][2]={{0,0},{-1,0},{1,0},{0,-1},{0,1}};

struct Node {
    int x;
    int y;
    int num;
    int dir;
};

vector<Node> v;
pair<int,pair<int,int>> visited[104][104]; // 값,방향

void display_() {
    
    for(int i=0;i<=N-1;i++) {
        for(int j=0;j<=N-1;j++) {
            cout << visited[i][j].first << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int change_(int curr) {
    
    if(curr==1) {
        return 2;
    } else if(curr==2) {
        return 1;
    } else if(curr==3) {
        return 4;
    } else if(curr==4) {
        return 3;
    }
    return 0;
}

void move_(int x,int y,int num,int dir) {
    
    int dx,dy;
    dx=x+retDir[dir][0];
    dy=y+retDir[dir][1];
    int tempNum=num;
    int tempDir=dir;
    
    if(dx<=0 or dx>=N-1 or dy<=0 or dy>=N-1) {
        tempNum=num/2;
        tempDir=change_(dir);
    }
    
    if(tempNum==0) {
        return;
    }
    
    if(visited[dx][dy].first<tempNum) {
        visited[dx][dy].first=tempNum;
        visited[dx][dy].second.first+=tempNum;
        visited[dx][dy].second.second=tempDir;
    } else {
        visited[dx][dy].second.first+=tempNum;
    }
}

void go_() {
    
    for(int i=0;i<M;i++) {
        
        memset(visited,0,sizeof(visited));
        for(Node temp:v) {
            move_(temp.x,temp.y,temp.num,temp.dir);
        }
//        display_();
        
        v.clear();
        for(int i=0;i<=N-1;i++) {
            for(int j=0;j<=N-1;j++) {
                if(visited[i][j].first) {
                    v.push_back({i,j,visited[i][j].second.first,visited[i][j].second.second});
                }
            }
        }
    }
    
    for(Node temp:v) {
        ret+=temp.num;
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    for(int test_case=1;test_case<=T;test_case++) {
        
        cin >> N >> M >> K;
        v.clear();
        ret=0;
        
        for(int i=0;i<K;i++) {
            int x,y,num,dir;
            cin >> x >> y >> num >> dir;
            v.push_back({x,y,num,dir});
        }
        
        go_();
        cout << "#" << test_case << " " << ret << "\n";
    }
    
    return 0;
}
