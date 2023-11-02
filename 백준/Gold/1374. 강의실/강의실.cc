#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int ret;
int N;
vector<pair<int, int>> v;
priority_queue<int,vector<int>,greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int temp,a,b;
        cin >> temp >> a >> b;
        v.push_back({a,b});
    }
    
    sort(v.begin(), v.end());

    for(int i=0;i<N;i++) {
        if(!pq.empty()) {
            if(pq.top()>v[i].first) {
                ret+=1;
            }
            else {
                pq.pop();
            }
        }
        else {
            ret+=1;
        }
        pq.push(v[i].second);
    }

    cout << ret << "\n";
    
    return 0;
}
