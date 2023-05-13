#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> v;

int ret;

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
    sort(v.begin(), v.end());
    
    ret=v[0].first+v[0].second;
    for(int i=1;i<v.size();i++) {
        if(ret<=v[i].first) {
            ret=v[i].first+v[i].second;
        }
        else {
            ret+=(v[i].second);
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}
