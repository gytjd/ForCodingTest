#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<pair<int, int>> v;
int visited[14];

long long ret=-1;
void go_(long long S,long long B,int depth,int M) {
    
    if(depth==M) {
        if(ret==-1) {
            ret=abs(S-B);
        }
        else {
            ret=min(ret, abs(S-B));
        }
        return;
    }
    
    for(int i=0;i<N;i++) {
        if(!visited[i]) {
            visited[i]=1;
            go_(S*v[i].first, B+v[i].second, depth+1, M);
            visited[i]=0;
        }
    }
    
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int start,end;
        cin >> start >> end;
        v.push_back({start,end});
    }
    
    for(int i=1;i<=N;i++) {
        memset(visited, 0, sizeof(visited));
        go_(1, 0, 0, i);
    }
    
    cout << ret << "\n";
    
    return 0;
}
