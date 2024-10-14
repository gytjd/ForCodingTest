#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int visited[504][504];

int solution(vector<vector<int>> triangle) {
    int ret=0;
    
    for(int i=0;i<triangle.size();i++) {
        for(int j=0;j<triangle[i].size();j++) {
            visited[i+1][j+1]=triangle[i][j];
        }
    }
    
    for(int i=1;i<=triangle.size();i++) {
        for(int j=1;j<=triangle[i-1].size();j++) {
            visited[i][j]=max(visited[i-1][j-1],visited[i-1][j])+visited[i][j];
        }
    }
    
    for(int i=1;i<=triangle.size();i++) {
        ret=max(ret,visited[triangle.size()][i]);
    }
    return ret;
}