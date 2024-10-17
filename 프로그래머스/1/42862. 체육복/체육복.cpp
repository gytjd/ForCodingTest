#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int visited[34];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for(int i=1;i<=n;i++) {
        visited[i]=1;
    }
    
    for(int i=0;i<lost.size();i++) {
        visited[lost[i]]-=1;
    }
    for(int i=0;i<reserve.size();i++) {
        visited[reserve[i]]+=1;
    }
    
    for(int i=1;i<=n;i++){
        if(visited[i]==0) {
            
            if(visited[i-1]==2) {
                visited[i-1]=1;
                visited[i]=1;
            } else if (visited[i+1]==2) {
                visited[i]=1;
                visited[i+1]=1;
            }
        }
    }
    
    for(int i=1;i<=n;i++) {
        if(visited[i]) {
            answer+=1;
        }
    }
    return answer;
}