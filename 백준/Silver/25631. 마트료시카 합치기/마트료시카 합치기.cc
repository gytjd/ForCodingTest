#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<int> v;
priority_queue<int,vector<int>,greater<int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    sort(v.begin(),v.end());
    
    q.push(v[0]);
    for(int i=1;i<N;i++) {
        if(q.top()<v[i]) {
            q.pop();
            
        }
        q.push(v[i]);
    }
    
    cout << q.size() << "\n";
    
    return 0;
}
