#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,M;
vector<pair<int, int>> v;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int start,end;
        cin >> start >> end;
        v.push_back({start,end});
        M=max(M,end);
    }
    
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    
    vector<int> ret(M+1,-1);
    
    for(int i=0;i<N;i++) {
        if(ret[v[i].second]==-1) {
            ret[v[i].second]=v[i].first;
        }
        else {
            for(int j=v[i].second-1;j>=1;j--) {
                if(ret[j]==-1) {
                    ret[j]=v[i].first;
                    break;
                }
            }
        }
    }
    int sum_R=0;
    for(int i=1;i<=M;i++) {
        if(ret[i]==-1) {
            continue;
        }
        sum_R+=ret[i];
    }
    
    cout << sum_R << "\n";
    
    return 0;
}
