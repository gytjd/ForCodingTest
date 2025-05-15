#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int> q;
int visited[104];

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    for(int temp:priorities) {
        q.push(temp);
    }
    
    int ret_Cnt=0;
    bool check_Flag=false;
    while(true) {
        
        for(int i=0;i<priorities.size();i++) {
            if(!visited[i]) {
                if(priorities[i]==q.top()) {
                    ret_Cnt+=1;
                    // cout << i << " " << q.top() << " " << ret_Cnt << "\n";
                    q.pop();
                    visited[i]=1;
                    
                    if(i==location) {
                        answer=ret_Cnt;
                        check_Flag=true;
                        break;
                    }
                }
            }
        }
        
        if(check_Flag) {
            break;
        }
    }
    
    return answer;
}