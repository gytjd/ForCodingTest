#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<string> v;
unordered_map<string,int> visited;

bool is_one(string ori,string temp) {
    
    int cnt=0;
    for(int i=0;i<ori.size();i++) {
        if(ori[i]!=temp[i]) {
            cnt+=1;
        }
    }
    if(cnt==1) return true;
    else return false;
}

void BFS_iter(string start) {
    queue<string> q;
    q.push(start);
    visited[start]=1;
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        
        for(int i=0;i<v.size();i++) {
            if(visited[v[i]]==0 and is_one(start,v[i])) {
                visited[v[i]]=visited[start]+1;
                q.push(v[i]);
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {

    v=words;
    BFS_iter(begin);
    
    if(visited[target]) return visited[target]-1;
    else return 0;
}