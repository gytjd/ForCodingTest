#include <iostream>
#include <string>
#include <vector>

using namespace std;

int visited[1004];

void init_() {
    for(int i=1;i<=1000;i++) {
        for(int j=i;j<=1000;j+=i) {
            visited[j]+=1;
        }
    }
}

int solution(int left, int right) {
    int answer = 0;
    
    init_();
    
    for(int i=left;i<=right;i++) {
    
        if(visited[i]%2==0) {
            answer+=i;
        }
        else {
            answer-=i;
        }
    }
    return answer;
}