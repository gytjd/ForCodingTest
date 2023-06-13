#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int T,N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    for(int i=0;i<T;i++) {
        int N;
        cin >> N;
        vector<pair<int, int>> v;
        
        for(int j=0;j<N;j++) {
            int start,end;
            cin >> start >> end;
            v.push_back({start,end});
        }
        
        sort(v.begin(), v.end());

        int ret=1;
        int temp=v[0].second;
        for(int j=1;j<N;j++) {
//            cout << v[j].first << " " << v[j].second << "\n";
            if(temp>v[j].second) {
                ret+=1;
                temp=v[j].second;
            }
        }
        
        cout << ret << "\n";
    }
    
    return 0;
}
