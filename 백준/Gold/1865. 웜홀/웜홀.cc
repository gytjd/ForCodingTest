#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

int T;
int N,M,W;

vector<pair<int, pair<int, int>>> v;


int Bellman_(int start) {
    vector<int> distance(N+1,INF);
    distance[start]=0;
    
    for(int i=1;i<=N;i++) {
        for(pair<int, pair<int, int>> temp:v) {
            
            if(distance[temp.second.second]>distance[temp.second.first]+temp.first) {
                distance[temp.second.second]=distance[temp.second.first]+temp.first;
                
                if(i==N) {
                    return 1;
                }
            }
        }
    }
    
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    
    for(int i=0;i<T;i++) {
        cin >> N >> M >> W;
        v.clear();
        for(int j=0;j<M;j++) {
            int s,e,w;
            cin >> s >> e >> w;
            v.push_back({w,{s,e}});
            v.push_back({w,{e,s}});
        }
        
        for(int j=0;j<W;j++) {
            int s,e,w;
            cin >> s >> e >> w;
            v.push_back({-w,{s,e}});
        }
        
        
        if(Bellman_(1)) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}

