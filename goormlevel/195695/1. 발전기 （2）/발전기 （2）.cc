#include <iostream>
#include <algorithm> 
#include <queue> 
using namespace std;

int N; 
int K; 
queue<pair<int,int>> q; 
int m[1004][1004];
int danzi[34];
bool visited[1004][1004]; 
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

void bfs(int y, int x){
	q.push({y, x}); 
	int counter = 1;
	int danziNo= m[y][x];
	while(!q.empty()){
		pair <int,int> p = q.front(); 
		int curr_y= p.first;
		int curr_x= p.second; 
		q.pop(); 
		for(int i = 0; i < 4; i++){
			int dy= curr_y + dir[i][0];
			int dx = curr_x + dir[i][1];
			if(dy>=0 && dy < N && dx>=0 && dx < N){
				if(m[dy][dx]==m[y][x] & visited[dy][dx]==0){
					q.push({dy,dx});
					visited[dy][dx]=1; 
					counter++;
				}
			}
		}
	}
	if(counter >= K){
			danzi[danziNo] = danzi[danziNo] + 1;
	}
}
void display(){
	int largest= 0;
	int pos =0;
	for(int i = 0; i < 31; i++){
		if(danzi[i]>=largest){
			largest = danzi[i];
			pos= i;
		}
	}
	cout << pos;

}
int main() {
	cin >> N >> K;
	for(int y =0; y < N; y++){
		for(int x = 0; x < N; x++){
			int M; 
			cin >> M;
			m[y][x]=M; 
		}
	}
	
	for(int y =0; y < N; y++){
		for(int x = 0; x < N; x++){
			if(visited[y][x]==0){
				visited[y][x] =1;
				bfs(y,x);
			}
		}
	}
	display();
	return 0;
}