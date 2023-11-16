#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N,temp;
priority_queue<int,vector<int>,greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> temp;
            pq.push(temp);
            
            if(pq.size()>N) {
                pq.pop();
            }
        }
    }
    
    cout << pq.top() << "\n";
    
    return 0;
}
