#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N,M,C;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[104][104];
int visited[104][104][104];

struct Node {
	int x;
	int y;
	int z;
};

void display_() {
	cout << "\n";
	for(int z=0;z<=C;z+=10) {
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				cout << visited[i][j][z] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
}

void BFS_iter(int x,int y,int z) {
	
	int dx,dy;
	queue<Node> q;
	q.push({x,y,z});
	visited[x][y][z]=1;
	
	while(!q.empty()) {
		x=q.front().x;
		y=q.front().y;
		z=q.front().z;
		q.pop();
		
		for(int i=0;i<4;i++) {
			dx=x+dir[i][0];
			dy=y+dir[i][1];
			
			if(dx<0 or dx>=N or dy<0 or dy>=M) {
				continue;
			}
			
			
			if(arr[dx][dy]==0 and visited[dx][dy][z]==0) {
				visited[dx][dy][z]=visited[x][y][z]+1;
				q.push({dx,dy,z});
			}
			
			if(arr[dx][dy]==1 and visited[dx][dy][z]==0 and z>=10) {
			  dx=x+(dir[i][0]*2);
				dy=y+(dir[i][1]*2);
				
				if(dx<0 or dy>=N or dy<0 or dy>=M) {
					continue;
				}
				// cout << dx << " " << dy << " " << z << "\n";
				if(arr[dx][dy]==0 and visited[dx][dy][z-10]==0) {
					visited[dx][dy][z-10]=visited[x][y][z]+1;
					q.push({dx,dy,z-10});
				}
			}
		}
	}
} 

int main() {
	
	cin >> N >> M >> C;
	for(int i=0;i<N;i++) {
		string data;
		cin >> data;
		for(int j=0;j<M;j++) {
			arr[i][j]=data[j]-'0';
		}
	}
	
	BFS_iter(0,0,C);
	
	int ret=987654321;
	bool check_Flag=false;
	
	for(int z=0;z<=C;z++) {
		if(visited[N-1][M-1][z]==0) {
			continue;
		}
		ret=min(ret,visited[N-1][M-1][z]-1);
		check_Flag=true;
	}
	
	if(!check_Flag) {
		cout << -1 << "\n";
	}
	else {
		cout << ret << "\n";
	}
	
	
	return 0;
}