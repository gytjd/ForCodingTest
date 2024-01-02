#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

string answer = "";
int visited[4][3];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
pair<int,int> curr_Left={3,0}; // *
pair<int,int> curr_Right={3,2}; // #

void init_() {
    for(int i=0;i<4;i++) {
        for(int j=0;j<3;j++) {
            visited[i][j]=0;
        }
    }
}

void BFS_iter(int x,int y) {
    int dx,dy;
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=1;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=4 or dy<0 or dy>=3) {
                continue;
            }
            
            if(visited[dx][dy]==0) {
                visited[dx][dy]=visited[x][y]+1;
                q.push({dx,dy});
            }
        }
    }
    
}

void common_hand(int temp,string hand) {
    if(hand=="right") {
        if(temp==0) {
            curr_Right.first=3;
        }
        else {
            curr_Right.first=temp/3;
        }
        curr_Right.second=1;
        answer+='R';
    } else {
        if(temp==0) {
            curr_Left.first=3;
        }
        else {
            curr_Left.first=temp/3;
        }
        curr_Left.second=1;
        answer+='L';
    }
}


string solution(vector<int> numbers, string hand) {
    
    for(int temp:numbers) {
        
        // cout << curr_Left.first << " " << curr_Left.second << "\n";
        // cout << curr_Right.first << " " << curr_Right.second << "\n";
        // cout << "\n";
        
        if(temp==1 or temp==4 or temp==7) {
            curr_Left.first=temp/3;
            curr_Left.second=0;
            answer+='L';
        }
        else if(temp==3 or temp==6 or temp==9) {
            curr_Right.first=temp/3-1;
            curr_Right.second=2;
            answer+='R';
        }
        else {  // 가까운거 가야함
            init_();
            if(temp==0) {
                BFS_iter(3,1);
            }
            else {
                BFS_iter(temp/3,1);
            }
            
            int temp_RetA=visited[curr_Left.first][curr_Left.second]; // 왼손
            int temp_RetB=visited[curr_Right.first][curr_Right.second]; // 오른손
            
            if(temp_RetA<temp_RetB) {
                if(temp==0) {
                    curr_Left.first=3;
                }
                else {
                    curr_Left.first=temp/3;
                }
                curr_Left.second=1;
                answer+='L';
            }
            else if(temp_RetA>temp_RetB) {
                
                if(temp==0) {
                    curr_Right.first=3;
                }
                else {
                    curr_Right.first=temp/3;
                }
                curr_Right.second=1;
                answer+='R';
            }
            else { // 
                common_hand(temp,hand);
            }   
        }
    }
    return answer;
}