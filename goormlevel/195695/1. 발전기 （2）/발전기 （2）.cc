#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N,K;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[1004][1004];
int visited[1004][1004];
int apt_ret[34];
vector<pair<int,int>> v;

bool cmp(pair<int,int> &a,pair<int,int> &b) {
	if(a.second==b.second) {
		return a.first>b.first;
	}
	return a.second>b.second;
}

int BFS_iter(int x,int y,int num) {
    int dx,dy;
    int temp_Cnt=0;
    
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=1;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        temp_Cnt+=1;
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=N) {
                continue;
            }
            
            if(arr[dx][dy]==num and visited[dx][dy]==0) {
                visited[dx][dy]=1;
                q.push({dx,dy});
            }
        }
    }
    
    return temp_Cnt;
}
int main() {
	
    cin >> N >> K;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(visited[i][j]==0) {
                int temp=BFS_iter(i,j,arr[i][j]);
							
                if(temp>=K) {
                    apt_ret[arr[i][j]]+=1;
                }
            }
        }
    }
    
    for(int i=1;i<=30;i++) {
			v.push_back({i,apt_ret[i]});
    }
	sort(v.begin(),v.end(),cmp);
	// for(pair<int,int> temp:v) {
	// 	cout << temp.first << " " << temp.second << "\n";
	// }
	cout << v[0].first << "\n";
    
  return 0;
}
