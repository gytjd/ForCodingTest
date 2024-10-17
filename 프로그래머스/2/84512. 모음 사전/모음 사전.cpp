#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
vector<char> v={{'A','E','I','O','U'}};
vector<string> ret;
unordered_map<string,int> m;

void DFS_recur(int curr,string temp) {
    ret.push_back(temp);
    
    if(curr==5) {
        return;
    }
    
    for(int i=0;i<5;i++) {
        DFS_recur(curr+1,temp+v[i]);
    }
}
    
int solution(string word) {
    
    DFS_recur(0,"");
    sort(ret.begin(),ret.end());
    for(int i=1;i<ret.size();i++) {
        m[ret[i]]=i;
    }
    
    return m[word];
}