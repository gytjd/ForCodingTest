#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
priority_queue<long long,vector<long long>,greater<>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        
        if(data==0) {
            if(q.empty()) {
                cout << 0 << "\n";
            }
            else {
                cout << q.top() << "\n";
                q.pop();
            }
        }
        else {
            q.push(data);
        }
    }
    
    return 0;
}
