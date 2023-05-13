#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int start,end;
        cin >> start >> end;
        v.push_back({end,start});
    }
    
    sort(v.begin(), v.end());
    
    int tot_Cnt=0;
    int max_N=v[0].first;
    
    for(int i=1;i<v.size();i++) {
        if(max_N>v[i].second) {
            continue;
        }
        
        max_N=v[i].first;
        
        tot_Cnt+=1;
    }
    
    cout << tot_Cnt+1 << "\n";
    
    return 0;
}
