#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string,int> m;

int solution(vector<vector<string>> clothes) {
    
    int ret=1;
    for(vector<string> temp:clothes) {
        m[temp[1]]+=1;
    }
    
    for (pair<string,int> temp : m) {
        ret*=temp.second+1;
    }
    
    return ret-1;
}