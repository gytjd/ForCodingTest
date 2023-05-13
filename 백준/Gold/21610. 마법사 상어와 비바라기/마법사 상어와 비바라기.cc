#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
using namespace std;

int N,M;
int arr[54][54];

int cloud[54][54];
int visited[54][54];

deque<pair<int, int>> v;
int dir[8][2]={{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
int temp_dir[4][2]={{-1,-1},{-1,1},{1,1},{1,-1}};

void display_() {
    
    cout << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void make_cloud() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(arr[i][j]>=2 and visited[i][j]!=1) {
                v.push_back({i,j});
                arr[i][j]-=2;
            }
            else if(visited[i][j]==1) {
                visited[i][j]=0;
            }
        }
    }
    
}

void go_(int d,int s) {
    
    int x,y;
    int dx,dy;
    unsigned long size_V=v.size();
    
    for(int i=0;i<size_V;i++) {
        x=v.front().first;
        y=v.front().second;
        v.pop_front();
        
//        cout << x << " " << y << "\n";
        
        dx=(x+(dir[d][0]*s))%N;
        dy=(y+(dir[d][1]*s))%N;
        
        
        
        if(dx<0) {
            dx=abs(dx)%N;
            dx=-dx+N;
        }

        if(dy<0) {
            dy=abs(dy)%N;
            dy=-dy+N;
        }
        
//        cout << dx << " " << dy << "\n";
        
        visited[dx][dy]=1;
        v.push_back(make_pair(dx, dy));
        arr[dx][dy]+=1;
    }
    // 구름 사라짐
//
    
    for(int i=0;i<size_V;i++) {
        x=v.front().first;
        y=v.front().second;
        v.pop_front();
        
        int tmp_Cnt=0;
        
        for(int j=0;j<4;j++) {
            dx=x+temp_dir[j][0];
            dy=y+temp_dir[j][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=N) {
                continue;
            }
            
            if(arr[dx][dy]==0) {
                continue;
            }
            
            tmp_Cnt+=1;
        }
        
        arr[x][y]+=tmp_Cnt;
    }
    
    make_cloud();
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
    
    v.push_back({N-1,0});
    v.push_back({N-1,1});
    v.push_back({N-2,0});
    v.push_back({N-2,1});
    
    
    for(int i=0;i<M;i++) {
        int s,d;
        cin >> d >> s;
        go_(d-1,s);
//        display_();
    }
    
    int tot_Cnt=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            
            tot_Cnt+=arr[i][j];
        }
    }
    
    cout << tot_Cnt << "\n";
    
    return 0;
}
