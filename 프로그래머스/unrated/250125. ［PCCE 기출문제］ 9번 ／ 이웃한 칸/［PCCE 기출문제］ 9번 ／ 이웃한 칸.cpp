#include <string>
#include <vector>

using namespace std;

int N,M;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int solution(vector<vector<string>> board, int h, int w) {
    
    int curr_cnt=0;
    N=board[0].size();
    M=board.size();
    
    int dx,dy;
    for(int i=0;i<4;i++) {
        dx=h+dir[i][0];
        dy=w+dir[i][1];
        
        if(dx<0 or dx>=N or dy<0 or dy>=M) {
            continue;
        }
        
        if(board[dx][dy]==board[h][w]) {
            curr_cnt+=1;
        }
    }
    
    return curr_cnt;
}