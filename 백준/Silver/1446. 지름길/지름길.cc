#include <iostream>
#include <vector>

using namespace std;

int N,D;
int visited[10004];
vector<pair<int,int>> v[10004]; // first 는 시작 second 는 시간

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> D;
    for(int i=0;i<N;i++) {
        int start,end,weight;
        cin >> start >> end >> weight;
        v[end].push_back({start,weight});
    }
    
    for(int i=1;i<=D;i++) {
        visited[i]=visited[i-1]+1;
        for(int j=0;j<v[i].size();j++) {
            visited[i]=min(visited[i],visited[v[i][j].first]+v[i][j].second);
        }
    }
    
    cout << visited[D] << "\n";
    
    return 0;
}
