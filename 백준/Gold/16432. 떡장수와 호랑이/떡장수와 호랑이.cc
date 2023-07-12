#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool check_Flag;
int N,M;
string tot;
vector<int> v[1004];
int visited[1004][10];

int go_(int idx,int curr,string ret) {
    
//    cout << idx << " " << curr  << " " << visited[idx][curr] << "\n";
    
    if(idx==N) {
        tot=ret;
        check_Flag=true;
        return 1;
    }
    
    if(visited[idx][curr]!=-1) {
        return visited[idx][curr];
    }
    visited[idx][curr]=0;
    
    for(int i=0;i<v[idx].size();i++) {
        if(v[idx][i]!=curr) {
            visited[idx][curr]=go_(idx+1, v[idx][i],ret+to_string(v[idx][i]));
        }
    }
    
    return visited[idx][curr];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    memset(visited, -1, sizeof(visited));
    cin >> N;
    
    for(int i=0;i<N;i++) {
        cin >> M;
        for(int j=0;j<M;j++) {
            int data;
            cin >> data;
            v[i].push_back(data);
        }
    }
    
    go_(0,0,"");
    if(check_Flag) {
        for(int i=0;i<N;i++) {
            cout << tot[i] << "\n";
        }
    }
    else {
        cout << -1 << "\n";
    }
    
    return 0;
}
