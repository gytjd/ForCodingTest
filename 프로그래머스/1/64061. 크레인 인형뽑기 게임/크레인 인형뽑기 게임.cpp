#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int N;
queue<int> q[34];
stack<int> s;

void init_(vector<vector<int>> board) {
    N=board.size();
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(board[i][j]!=0) {
                q[j+1].push(board[i][j]);
            }
        }
    }
}
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    init_(board);
    for(int temp:moves) {
        
        int ret=0;
        if(!q[temp].empty()) {
            ret=q[temp].front();
            q[temp].pop();
        }
        else {
            continue;
        }
        
        if(s.empty()) {
            s.push(ret);
        }
        else {
            // cout << s.top() << " " << ret << '\n';
            if(s.top()==ret) {
                answer+=2;
                s.pop();
            }
            else {
                s.push(ret);
            }
        }
    }
    
    return answer;
}