#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[1000004];

void BFS_iter(int X,int Y,int N) {
    
    int dx;
    queue<int> q;
    q.push(X);
    visited[X]=1;
    
    while(!q.empty()) {
        X=q.front();
        q.pop();
        
        for(int i=0;i<3;i++) {
            if(i==0) {
                dx=X+N;
            }
            else if(i==1) {
                dx=X*2;
            }
            else {
                dx=X*3;
            }
            
            if(dx<=1000001 and visited[dx]==0) {
                visited[dx]=visited[X]+1;
                q.push(dx);
            }
        }
    }
}

int solution(int x, int y, int n) {
    int answer = 0;
    
    BFS_iter(x,y,n);
    
    if(visited[y]==0) {
        answer=-1;
    }
    else {
        answer=visited[y]-1;
    }
    return answer;
}