#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int visited[104];
vector<int> v;

int solution(vector<int> cards) {
    
    for(int i=0;i<cards.size();i++) {
        
        int curr_Cnt=0;
        int curr_Num=cards[i];
        while(!visited[curr_Num]) {
            visited[curr_Num]=1;
            curr_Cnt+=1;
            curr_Num=cards[curr_Num-1];
        }
        if(curr_Cnt) {
            v.push_back(curr_Cnt);
        }
    }
    
    if(v.size()==1) {
        return 0;
    } else {
        sort(v.begin(),v.end(),greater<>());
        return v[0]*v[1];
    }
}