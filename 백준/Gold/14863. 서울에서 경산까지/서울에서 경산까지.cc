#include <iostream>
#include <vector>
#include <cstring>

#define INF -987654321

using namespace std;

int N,K;
int visited[104][100004];

vector<pair<int, int>> v1;
vector<pair<int, int>> v2;

int go_(int idx,int min) {
    
    if(idx==N) {
        return 0;
    }
    
    int &ret=visited[idx][min];
    if(ret!=-1) {
        return ret;
    }
    ret=INF;
    
    if(min+v1[idx].first<=K) {
        
        ret=max(ret,go_(idx+1, min+v1[idx].first)+v1[idx].second);
    }
    
    if(min+v2[idx].first<=K) {
        ret=max(ret,go_(idx+1, min+v2[idx].first)+v2[idx].second);
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> K;
    
    for(int i=0;i<N;i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        v1.push_back({a,b});
        v2.push_back({c,d});
    }
    
    memset(visited, -1, sizeof(visited));
    cout << go_(0, 0) << "\n";
    
    return 0;
}
