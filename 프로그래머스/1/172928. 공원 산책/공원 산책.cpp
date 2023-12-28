#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int N,M;
int startX,startY;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

unordered_map<char,int> chrTo = {
    {'E',0},
    {'S',1},
    {'W',2},
    {'N',3}
};

void init_(vector<string> &park) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(park[i][j]=='S') {
                startX=i;
                startY=j;
            }
        }
    }
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    N=park.size();
    M=park[0].size();
    init_(park);
    
    for(string temp:routes) {
        
        bool check_Flag=false;
        int dx=startX;
        int dy=startY;
        int dirChr=chrTo[temp[0]];
        int dirNum=temp[2]-'0';
        
        for(int i=0;i<dirNum;i++) {
            dx+=dir[dirChr][0];
            dy+=dir[dirChr][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M or park[dx][dy]=='X') {
                check_Flag=true;
                break;
            }
        }
        
        if(!check_Flag) {
            startX=dx;
            startY=dy;
        }
    }
    
    answer.push_back(startX);
    answer.push_back(startY);
    
    return answer;
}