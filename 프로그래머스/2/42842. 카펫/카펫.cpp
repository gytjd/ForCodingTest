#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<pair<int,int>> solution(int brown, int yellow) {
    vector<pair<int,int>> answer;
    
    for(int i=1;i<=brown+yellow;i++) {
        
        if((brown+yellow)%i==0 and i>=(brown+yellow)/i) {
            int temp=(brown+yellow)/i;
            if((2*i+2*temp-4)==brown) {
                answer.push_back({i,temp});
            }
        }
    }
    return answer;
}