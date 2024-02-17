#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int answer;
vector<pair<int,int>> v;

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
    
    sort(v.begin(),v.end());
    
    int low=v[0].first;
    int high=v[0].second;
    for(int i=1;i<N;i++) {
        if(v[i].first<=high) {
            high=max(high,v[i].second);
        }
        else {
            answer+=high-low;
            low=v[i].first;
            high=v[i].second;
        }
    }
    
    answer+=high-low;
    cout << answer << "\n";
    
    return 0;
}
