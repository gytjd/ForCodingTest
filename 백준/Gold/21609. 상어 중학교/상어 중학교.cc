#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,M;
int arr[24][24];
int visited[24][24];
int tot_Cnt=0;
int rain_Cnt=0;
int ret;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

struct Node {
    int x,y;
    int block_size;
    int rainbow_Cnt;
};

bool cmp(Node a,Node b) {
    
    if(a.block_size==b.block_size) {
        if(a.rainbow_Cnt==b.rainbow_Cnt) {
            if(a.x==b.x) {
                return a.y>b.y;
            }
            return a.x>b.x;
        }
        return a.rainbow_Cnt>b.rainbow_Cnt;
    }
    return a.block_size>b.block_size;
}

void display_() {
    
    cout << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            
            if(arr[i][j]==-2) {
                printf("%3c",'X');
            }
            else {
                printf("%3d",arr[i][j]);
            }
        }
        cout << "\n";
    }
}

void init_BFS(int x,int y,int num) {

    int temp_visited[24][24]={0,};
    
    int dx,dy;
    queue<pair<int, int>> q;
    visited[x][y]=1;
    temp_visited[x][y]=1;
    q.push(make_pair(x, y));
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        tot_Cnt+=1;
        
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=N) {
                continue;
            }
            
            if(temp_visited[dx][dy]==0 and (arr[dx][dy]==num or arr[dx][dy]==0)) {
                
                if(arr[dx][dy]==num) {
                    visited[dx][dy]=1;
                } else {
                    rain_Cnt+=1;
                }
                
                temp_visited[dx][dy]=1;
                q.push(make_pair(dx, dy));
            }
        }
    }
}
int init_() {
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            visited[i][j]=0;
        }
    }
    
    vector<Node> v;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(visited[i][j]==0 and arr[i][j]!=0 and arr[i][j]!=-1 and arr[i][j]!=-2) {
                
                Node temp;
                temp.x=i;
                temp.y=j;
                
                tot_Cnt=0;
                rain_Cnt=0;
                
                init_BFS(i, j, arr[i][j]);
                
                temp.block_size=tot_Cnt;
                temp.rainbow_Cnt=rain_Cnt;
                
//                cout << temp.x << " " << temp.y << " " <<temp.block_size << " " <<temp.rainbow_Cnt << "\n";
                if(temp.block_size<2) {
                    continue;
                }
                
                v.push_back(temp);
            }
        }
    }
    
    if(v.size()==0) {
        return -1;
    }
    
    sort(v.begin(), v.end(), cmp);
    Node temp=v[0];
    
    int x,y,dx,dy;
    int del_num;
    int ret_Cnt=0;
    int temp_visited[24][24]={0,};
    
    x=temp.x; y=temp.y;
    del_num=arr[x][y];
    temp_visited[x][y]=1;
    
//    cout << x << " " << y << "\n";
    
    queue<pair<int, int>> q;
    q.push(make_pair(x,y));
    arr[x][y]=-2;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        
        ret_Cnt+=1;
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
    
            if(dx<0 or dx>=N or dy<0 or dy>=N) {
                continue;
            }
            
            if(temp_visited[dx][dy]==0 and (arr[dx][dy]==del_num or arr[dx][dy]==0)) {
                temp_visited[dx][dy]=1;
                arr[dx][dy]=-2;
                q.push(make_pair(dx, dy));
            }
        }
    }
    
    return ret_Cnt;
}

void SWAP_(int &pa,int &pb) {
    int temp;
    temp=pa;
    pa=pb;
    pb=temp;
}

void gravity() {
    for(int i=0;i<N;i++) {
        for(int j=N-2;j>=0;j--) {
            
            if(arr[j][i]==-1 or arr[j][i]==-2) {
                continue;
            }
            
            int k=j;
            while(k<N) {
                
                if(arr[k+1][i]==-2) {
                    k+=1;
                }
                else {
                    SWAP_(arr[j][i], arr[k][i]);
                    break;
                }
            }
        }
    }
}

void turn_() {
    
    int temp[24][24];
    
    for(int i=N-1;i>=0;i--) {
        for(int j=0;j<N;j++) {
            temp[N-1-i][j]=arr[j][i];
        }
    }
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            arr[i][j]=temp[i][j];
        }
    }
}

void start_() {
    
    while(1) {
        int tmp_num=init_();
        
        if(tmp_num==-1) {
            cout << ret << "\n";
            break;
        }
        ret+=(tmp_num*tmp_num);
        
//        display_();
        gravity();
//        display_();
        turn_();
//        display_();
        gravity();
//        display_();
//        cout << "---------------------" << "\n";
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }
    
    start_();
    
    
    return 0;
}

