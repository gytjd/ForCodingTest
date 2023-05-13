#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
int startX,startY;
int idx;
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        int start,end;
        cin >> start >> end;
        v.push_back({start,end});
    }
    
    sort(v.begin(), v.end());
    
    
    int ret=0;
    int temp=0;
    
    for(int i=0;i<N;i++) {
        
        if(v[i].second<=idx) {
            continue;
        }
        
        if(idx<v[i].first) {
            temp=(v[i].second-v[i].first)/M+((v[i].second-v[i].first)%M?1:0);
            idx=v[i].first+temp*M;
        }
        else {
            temp=(v[i].second-idx)/M+((v[i].second-idx)%M?1:0);
            idx=idx+temp*M;
        }
        
        ret+=temp;
    
    }
    
    cout << ret << "\n";
    
    return 0;
}
