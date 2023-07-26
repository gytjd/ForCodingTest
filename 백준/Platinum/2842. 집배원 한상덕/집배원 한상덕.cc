#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int tot=987654321;
int start_X,start_Y;
int N,M;
int dir[8][2]={{0,1},{1,0},{0,-1},{-1,0},{-1,1},{1,1},{1,-1},{-1,-1}};
char arr[54][54];
int height[54][54];
int visited[54][54];

vector<int> v;

int BFS_iter(int x,int y,int low,int high) {
    
    int ret=0;
    
    if(height[x][y]<low or height[x][y]>high) {
        return 0;
    }
    
    int dx,dy;
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y]=1;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
//        cout << x << " " << y << " " << arr[x][y] << "\n";
        
        for(int i=0;i<8;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=N or visited[dx][dy]==1) {
                continue;
            }
            
            if(height[dx][dy]<low or height[dx][dy]>high) {
                continue;
            }
            
            if(visited[dx][dy]==0) {
                visited[dx][dy]=1;
                q.push({dx,dy});
                
                if(arr[dx][dy]=='K') {
                    ret+=1;
                }
            }
        }
    }
    
//    cout << ret << "\n";
    return ret;
}

void go_() {
    
    int low=0;
    int high=0;
    
//    cout << start_X << " " << start_Y << "\n";
    
    while(low<=high and high<v.size()) {
//        cout << v[low] << " " << v[high] << "\n";
        
        memset(visited, 0, sizeof(visited));
        if(BFS_iter(start_X, start_Y, v[low], v[high])==M) {
            tot=min(tot,v[high]-v[low]);
            low+=1;
        }
        else {
            high+=1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        for(int j=0;j<N;j++) {
            arr[i][j]=a[j];
            
            if(arr[i][j]=='K') {
                M+=1;
            }
            if(arr[i][j]=='P') {
                start_X=i;
                start_Y=j;
            }
        }
    }
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> height[i][j];
            v.push_back({height[i][j]});
        }
    }
    
    sort(v.begin(),v.end());
    
    go_();
    cout << tot << "\n";
    
    return 0;
}
