#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int cnt_visited[10];
int visited[6];
vector<int> v;

void DFS_recur(int idx,int cnt) {
    if(cnt==6) {
        for(int i=0;i<6;i++) {
            cout << visited[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=idx;i<N;i++) {
        visited[cnt]=v[i];
        DFS_recur(i+1,cnt+1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    while(true) {
        cin >> N;
        if(!N) break;
        
        v.clear();
        memset(visited,0,sizeof(visited));
        
        for(int i=0;i<N;i++) {
            int data;
            cin >> data;
            v.push_back(data);
        }
        sort(v.begin(),v.end());
        
        DFS_recur(0,0);
        cout << "\n";
    }
    return 0;
}
